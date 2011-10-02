/**
 * A greatly simplified version 
 * of the client board model.
 */
proctype Client(chan input) {
Startup:
    input?req_transition;
    comms!ack_transition;

Calibration:
    // calibration handling
    // More message passing
Running:
    do
        :: //Normal routine
        :: goto Startup
        :: goto Error
    od;
Error:
    broadcast!error
}