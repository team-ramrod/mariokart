mtype = {error, ack, ready, go, reset1, reset2, ok1, ok2, ok3, data};
chan Mt = [0] of {mtype};
chan Mr = [0] of {mtype};
chan St = [0] of {mtype};
chan Sr = [0] of {mtype};
byte sensor_id;
byte motor_id;

bool comms_error, motor_error, sensor_error,
     comms_reset, motor_reset, sensor_reset;

int error_count;

// Basic state machine description of Comms
// hit up all boards                    
// once all ack tell all boards ready   
// wait for all boards to ready up      
// signal start to all boards

//ISSUE               RESPONSE
//incorrect reply     error
//never ack           acks time out, must be refreshed if a board is hanging
//board returns error propagate error 
//heartbeat timesout  propagate error                                         

//TODO:
//      Random error state entry sets global high for ltl claims
//      Same deal with random resets
//      Introduce broadcast channel for go and error (maybe insert message n times for n slaves?)
//      write those never claims


inline error_state(input, output) {
    mtype error_response;
    error_count ++;
    input?error_response;
    if 
        ::error_response == reset1 -> output!ok1 // change this to safely exit the process (for all processes) as getting back to the start is fine
        ::else -> goto Error
    fi;
    
    input?error_response;
    if
        ::error_response == reset2 -> output!ok2
        ::else -> goto Error
    fi;

}

inline start_state(input, output) {
    mtype response;
    input?response;// wait until asked if ready
    if 
        ::response == ready
        ::else -> goto Error // incorrect input results in error state (e.g. board rebooted mid-flight)
    fi;

    if
        :: output!ok1 // respond either yes (and continue)
        :: motor_error = true;
           output!error; 
           goto Error // or no (e.g. pre-flight check failed)
    fi;
    
    input?response;
    if
        ::response == go
        ::else -> goto Error
    fi;

}

proctype Comms() {
    mtype response;
Startup:
    Mt!ready;
    Mr?response;
    if
        ::response == ok1
        ::else -> goto Startup
    fi;

    St!ready;
    Sr?response;
    if
        ::response == ok1
        ::else -> goto Startup
    fi;

    St!go;
    Mr!go;

progress:
    do
        ::Mt!data;
          Mr?ack;
          St!data;
          Sr?_
          :: comms_reset = true; goto Startup
          :: comms_error = true; goto Error
    od;

Error:
    error_count++;
    do
        ::St!error; Mt!error
        ::break
    od  
    

    // move all boards to error state
    // wait until reset signal received
}

proctype Sensor() {
Startup:
    start_state(St, Sr);

progress:
    do 
        :: St?_; Sr!data
        :: sensor_reset = true; goto Startup
        :: sensor_error = true; goto Error
    od;

Error:
    error_state(St, Sr);

    goto Startup;
}


proctype Motor() {
Startup:
    start_state(Mt, Mr);

progress:
    do 
        :: Mt?data; Mr!ack
        :: motor_reset = true; goto Startup
        :: motor_error = true; goto Error
    od;

Error:
    error_state(Mt, Mr);

    goto Startup;
}

init {
    atomic {
        sensor_id = run Sensor();
        motor_id = run Motor();
        run Comms();
    }
}
