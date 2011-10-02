/**
 * If one board goes into 
 * error state, they all must.
 */
never {
    do
        :: error_count > 0 -> break
        :: true -> skip
    od;
    
accept:
    do
        :: error_count != num_boards
    od;
}