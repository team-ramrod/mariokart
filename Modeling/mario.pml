mtype = {error, waiting, data};
chan C = [1] of {mtype};
chan M = [1] of {mtype};
chan S = [1] of {mtype};
byte sensor_id;
byte motor_id;

proctype Comms() {
Reset://                                        ISSUES          RESPONSE
    // hit up all boards                    incorrect reply     error
    // once all ack tell all boards ready   never ack           acks time out, must be refreshed if a board is hanging
    // wait for all boards to ready up      board returns error propagate error 
    // signal start to all boards           heartbeat timesout  propagate error
    M!waiting;
    S!waiting;
    do
        ::M!data;
          S!data;
          C?_
        :: goto Reset
        :: goto Error
    od;

Error: skip
    // movve all boards to error state
    // wait until reset signal received
}

proctype Sensor() {
Reset: 
    do 
        :: S?waiting;
        :: timeout -> goto Error
    od;

    do 
        ::S?_;
        C!data
        :: goto Reset
        :: goto Error
    od;

Error: skip
    
}

proctype Motor() {
Reset:
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
