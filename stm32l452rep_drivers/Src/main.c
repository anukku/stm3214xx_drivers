#include "uart.h"
#include "systick.h"
#include "stdio.h"

int main(void) {
    uart2_tx_init();
    while (1) {
        systickDelayMs(1000);
        printf("a second passed \n\r");
    }
}
