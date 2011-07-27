#include <components/char_display.h>

int main(int argc, char *argv[]) {
    blahdly blah blah breakage
    char_display_init();

    unsigned int num = 0x00;
    unsigned int count = 0x01;

    for (;;) {
        char_display_number(num);
        num = (num + 1) % 100;
        count = 0x01;
        while (count != 0x00) {
            count++;
            char_display_tick();
        }
    }

    return 0;
}
