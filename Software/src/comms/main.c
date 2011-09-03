NAME "Comms"


//------------------------------------------------------------------------------
//         Local variables
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//         Main Function
//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    debug_init(SOFTWARE_NAME);

    //enables interrupts (note resets all configured interrupts)
    PIO_InitializeInterrupts(AT91C_AIC_PRIOR_LOWEST);

    //Main initialisations
    char_display_init();
    switches_init();

    while(1) {
        char_display_tick();
    }

    return 0;
}

