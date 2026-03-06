#include <stdio.h>
#include "myGPIO.h"
#include "driver/gpio.h"

#define led
#define KNOP 5

// LED

int huidge_waarde = 0;
int vorige_waarde = 0;


void myGPIO_LED_aan(int pin)
{
    gpio_set_level(pin, 1);
}
void myGPIO_LED_uit(int pin)
{
    gpio_set_level(pin, 0);
}
void myGPIO_LED_toggle(int pin);
void myGPIO_LED_setup(int pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_OUTPUT);
}

void myGPIO_LED_value(int pin, int value);

// INPUT KNOP

void myGPIO_KNOP_setup(int pin)
{
    gpio_reset_pin(pin);
    gpio_set_direction(pin, GPIO_MODE_INPUT);
    gpio_pullup_en(pin);
}
int myGPIO_KNOP_value(int pin)
{
    return gpio_get_level(pin);
}
int myGPIO_KNOP_flank(int pin)
{
    vorige_waarde = huidge_waarde;
    huidge_waarde = myGPIO_KNOP_value(KNOP);
    
    if(huidge_waarde == 1 && vorige_waarde == 0)
    {
        return 1;
    }
    return 0;
}