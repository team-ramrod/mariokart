mtype = {error, ack, ready, go, reset1, reset2, ok1, ok2, ok3, data};
chan M = [0] of {mtype};
chan S = [0] of {mtype};
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

//TODO: Slave startup function with chan param
//      Slave error state function with chan param
//      Random error state entry sets global high for ltl claims
//      Same deal with random resets
//      Introduce broadcast channel for go and error (maybe insert message n times for n slaves?)
//      write those never claims


proctype Comms() {
    mtype response;
Startup:
    M!ready;
    M?response;
    if
        ::response == ok1
        ::else -> goto Startup
    fi;

    S!ready;
    S?response;
    if
        ::response == ok1
        ::else -> goto Startup
    fi;

    S!go;
    M!go;

progress:
    do
        ::M!data;
          M?ack;
          S!data;
          S?_
          :: comms_reset = true; goto Startup
          :: comms_error = true; goto Error
    od;

Error:
    do
        ::S!error; M!error
        ::break
    od  
    

    // move all boards to error state
    // wait until reset signal received
}

proctype Sensor() {
    mtype response;
Startup:
    S?response;// wait until asked if ready
    if 
        ::response == ready
        ::else -> goto Error // incorrect input results in error state (e.g. board rebooted mid-flight)
    fi;

    if
        ::S!ok1 // respond either yes (and continue)
 //       ::S!error; goto Error // or no (e.g. pre-flight check failed)
    fi;
    
    S?response;
    if
        ::response == go
        ::else -> goto Error
    fi;

progress:
    do 
        :: S?_; S!data
        :: sensor_reset = true; goto Startup
        :: sensor_error = true; goto Error
    od;

Error:
    S?response;
    if 
        ::response == reset1 -> S!ok1
        ::else -> goto Error
    fi;
    
    S?response;
    if
        ::response == reset2 -> S!ok2
        ::else -> goto Error
    fi;

    goto Startup;
}


proctype Motor() {
    mtype response;
Startup:
    M?response;// wait until asked if ready
    if 
        ::response == ready
        ::else -> goto Error // incorrect input results in error state (e.g. board rebooted mid-flight)
    fi;

    if
        ::M!ok1 // respond either yes (and continue)
        :: motor_error = true; M!error; goto Error // or no (e.g. pre-flight check failed)
    fi;
    
    M?response;
    if
        ::response == go
        ::else -> goto Error
    fi;

progress:
    do 
        :: M?data; M!ack
        :: motor_reset = true; goto Startup
        :: motor_error = true; goto Error
    od;

Error:
    M?response;
    if 
        ::response == reset1 -> M!ok1 // change this to safely exit the process (for all processes) as getting back to the start is fine
        ::else -> goto Error
    fi;
    
    M?response;
    if
        ::response == reset2 -> M!ok2
        ::else -> goto Error
    fi;

    goto Startup;
}

init {
    atomic {
        sensor_id = run Sensor();
        motor_id = run Motor();
        run Comms();
    }
}
