mtype = {req_calibrate, ack_calibrate, do_calibrate, req_run, ack_run, do_run, data, ack, no, error};
chan comms = [0] of {mtype};
chan client = [0] of {mtype};
byte Rclientid;
byte motor_id;

bool comms_error, motor_error, sensor_error,
     comms_reset, motor_reset, sensor_reset;

int error_count;


proctype Comms() {
    mtype response;
Startup:
    client!req_calibrate;
    comms?response;
    if
        ::response == ack_calibrate
        ::else -> goto Error
    fi;

    client!do_calibrate;

Calibration:

    client!req_run;
    comms?response;
    if
        ::response == ack_run
        ::response == no -> goto Calibration
        ::else -> goto Error
    fi;

    client!do_run;

Running:
progress:
    do
        ::client!data;
          client?ack;
    od;

Error:
    error_count++;
    do
        ::client!error
    od  
}


proctype Client() {
    mtype message;
    int calib_count = 0;
    bool ready_to_run = false;
Startup:
    client?message;
    if
        :: message == req_calibrate -> comms!ack_calibrate; goto Startup
        :: message == do_calibrate 
        :: else -> goto Error 
    fi;

Calibration:
    if
        :: client?req_run ->
            if
                :: calib_count < 10 -> comms!no; calib_count++
                :: comms!ack_run; 
            fi
        :: client?do_run -> 
            if 
                :: ready_to_run == false -> goto Error
                :: else -> skip
            fi
    fi;

Running:
progress:
//  client?message;
    do 
        :: client?data -> comms!ack 
//      :: else -> goto Error
    od;

Error:
    error_count++;
    do
        ::client!error
    od 
}

init {
    atomic {
        run Comms();
        run Client()
    }
}
