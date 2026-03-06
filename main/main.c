#include <stdio.h>
#include <myADC.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "myGPIO.h"

#define THERMO 0

#define blauw 1
#define groen 2
#define rood 3

void app_main(void)
{
    myADC_setup(THERMO);
    int waarde;
    while(1)
    {
        waarde = myADC_inlezen(THERMO);
        printf("de temperatuur is %d\n", waarde);

        vTaskDelay(100);

        if(waarde<14)
        {
            myGPIO_LED_aan(blauw);
            myGPIO_LED_uit(rood);
            myGPIO_LED_uit(groen);
        }
        if(waarde>=14 && waarde<=19)
        {
            myGPIO_LED_aan(groen);
            myGPIO_LED_uit(blauw);
            myGPIO_LED_uit(rood);
        }
        else
        {
            myGPIO_LED_aan(rood);
            myGPIO_LED_uit(blauw);
            myGPIO_LED_uit(groen);
        }
    }
}
