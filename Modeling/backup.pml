mtype = {error, waiting, data};
chan C = [1] of {mtype};
chan M = [1] of {mtype};
chan S = [1] of {mtype};
byte sensor_id;
byte motor_id;

proctype Comms() {
Reset: 
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
