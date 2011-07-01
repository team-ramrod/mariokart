#include <drivers/char_display/char_display.h>

int main(int argc, char *argv[]) {
    char_display_init();

    uint16_t num = 0x00;
    uint32_t count = 0x01;

    for (;;) {
        char_display_number(num);
        num = (num + 1) % 100;
        count = 0x01;
        while (count != 0x00) {
            count++;
            char_display_show();
        }
    }

    return 0;
}
