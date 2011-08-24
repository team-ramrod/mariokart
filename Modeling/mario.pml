mtype = {error, ready, reset1, reset2, ok1, ok2, ok3, data};
chan M = [0] of {mtype};
chan S = [0] of {mtype};
byte sensor_id;
byte motor_id;

proctype Comms() {
Reset:
    //                                      ISSUES          RESPONSE
    // hit up all boards                    incorrect reply     error
    // once all ack tell all boards ready   never ack           acks time out, must be refreshed if a board is hanging
    // wait for all boards to ready up      board returns error propagate error 
    // signal start to all boards           heartbeat timesout  propagate error
    do
        ::M!ready;
          if 
              ::M?ok -> S!ready;
              if 
                  ::S?ok -> //exit out of do loop
              fi
          fi
        ::skip//do nothing (stay in loop)
    od;
Running:
    do
        ::M!data;
          S!data;
          C?_
        :: goto Reset
        :: goto Error
    od;

Error: skip
    // move all boards to error state
    // wait until reset signal received
}

proctype Sensor() {
Startup:
    S?ready1;// wait until asked if ready
    if
        ::S!ok1 // respond either yes (and continue)
        ::S!error; goto Startup // or no
    fi;
    
    mtype response;
    S?response
    if
        ::response == ok2 -> skip
        ::else -> goto error
    fi;

Running:
    do 
        ::S?_;
        D!data
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
