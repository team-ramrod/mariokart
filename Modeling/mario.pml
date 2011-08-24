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

Running:
    do
        ::M!data;
          S!data;
          S?_
        :: goto Startup
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
    
    S?response;
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
    S?response;// wait until asked if ready
    if 
        ::response == ready
        ::else -> goto Error // incorrect input results in error state (e.g. board rebooted mid-flight)
    fi;

    if
        ::S!ok1 // respond either yes (and continue)
        ::S!error; goto Error // or no (e.g. pre-flight check failed)
    fi;
    
    S?response;
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

init {
    atomic {
        sensor_id = run Sensor();
        motor_id = run Motor();
        run Comms();
    }
}
