int num_clients = 2;
mtype = {req_calibrate, ack_calibrate, do_calibrate, req_run, ack_run, do_run, data, ack, no, error};
chan comms = [0] of {mtype};
chan clients[2] = [0] of {mtype};

int error_count;



proctype Comms() {
    mtype response;
    int i;
Startup:
    for (i : 0..num_clients-1) {
        clients[i]!req_calibrate;
        comms?ack_calibrate
    };
    for (i : 0..num_clients-1) {
        clients[i]!do_calibrate
    };

Calibration:

    for (i : 0..num_clients-1) {
        clients[i]!req_run;
        comms?response;
        if
            ::response == ack_run -> skip
            ::response == no -> goto Calibration
            ::else -> goto Error
        fi
    };

SendRun:

    for (i : 0..num_clients-1) {
        clients[i]!do_run
    };

Running:
progress:
    for (i : 0..num_clients-1) {
        clients[i]!data;
        comms?ack
    };
    goto Running;

Error:
    error_count++;
    do
        ::for (i : 0..num_clients-1) {
            clients[i]!error;
        }
    od  
}


proctype Client(chan input) {
    mtype message;
    int calib_count = 0;
    bool ready_to_run = false;
Startup:
    input?message;
    if
        :: message == req_calibrate -> comms!ack_calibrate; goto Startup
        :: message == do_calibrate 
        :: else -> goto Error 
    fi;

Calibration:
    do
        :: input?req_run ->
            if
                :: calib_count < 10 -> comms!no; calib_count++
                :: comms!ack_run -> ready_to_run = true
            fi
        :: input?do_run -> 
            if 
                :: ready_to_run == false -> goto Error
                :: else -> break
            fi
    od;

Running:
progress:
    input?data;
    comms!ack;
    goto Running;

Error:
    error_count++;
    do
        ::input!error
    od 
}


never {
    do
        :: true -> skip
        :: error_count > 0 -> break
    od
}

init {
    atomic {
        run Comms();
        run Client(clients[0]);
        run Client(clients[1])
    }
}
