#include "board.h"
#include "common.h"

#include "libs/led.h"

int main(int argc, char *argv[]) {
    led_init();

    uint16_t num = 0x00;
    uint32_t count = 0x01;

    for (;;) {
        led_display(num);
        num = (num + 1) % 100;
        count = 0x01;
        while (count != 0x00) {
            count++;
            led_show();
        }
    }

    return 0;
}
