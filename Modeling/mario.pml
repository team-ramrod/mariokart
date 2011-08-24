mtype = {error, ready, go, reset1, reset2, ok1, ok2, ok3, data};
chan M = [0] of {mtype};
chan S = [0] of {mtype};
byte sensor_id;
byte motor_id;

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


proctype Comms() {
Startup:
    mtype response;

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

Running:
    do
        ::M!data;
          S!data;
          C?_
        :: goto Reset
        :: goto Error
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
        ::S!error; goto Error // or no (e.g. pre-flight check failed)
    fi;
    
    S?response
    if
        ::response == go
        ::else -> goto Error
    fi;

Running:
    do 
        :: S?_; S!data
        :: goto Startup
        :: goto Error
    od;

Error:
    S?reset1;
    if 
        ::S!ok3
        ::S!error; goto Error
    fi;
    if
        ::S?reset2
        ::else -> goto Error
    fi;

    goto Startup;
}

proctype Motor() {
Startup:
    do 
        :: M?waiting
        :: timeout -> goto Error
    od;

    do 
        ::M?_
        :: goto Reset
        :: goto Error
    od;

Error: skip
}

init {
    atomic {
        sensor_id = run Sensor();
        motor_id = run Motor();
        run Comms();
    }
}
