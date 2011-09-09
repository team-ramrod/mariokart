int num_clients = 2;
mtype = {req_calibrate, ack_calibrate, do_calibrate, req_run, ack_run, do_run, data, ack, no, error};
chan comms = [0] of {mtype};
chan clients[2] = [0] of {mtype};

int error_count;

proctype AsyncSend(chan recipient) {recipient!error}

proctype Comms() {
    mtype response;
    int i;
Startup:
    for (i : 0..num_clients-1) {
        clients[i]!req_calibrate;
        comms?response;
        if
            :: response == ack_calibrate
            :: response != ack_calibrate -> goto Error
        fi
    };
    for (i : 0..num_clients-1) {
        clients[i]!do_calibrate
    };

Calibration:

    for (i : 0..num_clients-1) {
        clients[i]!req_run;
        comms?response;
        if
            ::response == ack_run && i == 0 -> skip
            ::response == ack_run && i == 1 -> goto SendRun
            ::response == no -> goto Calibration
            ::else -> goto Error
        fi
    };

SendRun:

    clients[0]!do_run;
    clients[1]!do_run;

Running:
progress:
    clients[0]!data;
    comms?response;
    if 
        :: response == ack
        :: response != ack -> goto Error
    fi;
    clients[1]!data;
    comms?response;
    if 
        :: response == ack
        :: response != ack -> goto Error
    fi;
    goto Running;

Error:
    error_count++;
    run AsyncSend(clients[0]);
    run AsyncSend(clients[1]);
    comms?_
}


proctype Client(chan input) {
    mtype message;
    int calib_count = 0;
    bool ready_to_run = false;
Startup:
    input?message;
    if
        :: message == req_calibrate -> comms!ack_calibrate; goto Startup
        :: message == do_calibrate -> goto Calibration
        :: else -> goto Error 
    fi;

Calibration:
    input?message;
    if
        :: message == req_run ->
            if
                :: calib_count < 10 -> comms!no; calib_count++; goto Calibration
                :: comms!ack_run -> ready_to_run = true; goto Calibration
            fi
        :: message == do_run -> 
            if 
                :: ready_to_run == false -> goto Error
                :: else -> goto Running
            fi
        :: (message != req_run && message != do_run) -> goto Error
        :: goto Error
        :: goto Startup
    fi;

Running:
progress:
    input?data;
    comms!ack;
    goto Running;

Error:
    error_count++;
    comms!error;
}

/**
 * If one board goes into error state, they all must (eventually)
 */
never {
    do
        :: error_count > 0 -> break
        :: true -> skip
    od;

accept:
    do
        :: error_count != 3 
    od
}


init {
    atomic {
        run Comms();
        run Client(clients[0]);
        run Client(clients[1])
    }
}
