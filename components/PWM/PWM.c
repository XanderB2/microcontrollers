#include <stdio.h>
#include "PWM.h"
#include "driver/ledc.h"




#define LEDC_MODE LEDC_LOW_SPEED_MODE
#define LEDC_DUTY_RES LEDC_TIMER_10_BIT
#define LEDC_TIMER LEDC_TIMER_0
#define LEDC_FREQUENCY 4000
#define LEDC_CHANNEL LEDC_CHANNEL_0
#define LEDC_GPIOPIN 4

void PWM_setup(void)
{
    //configureren van de LEDC timer
    ledc_timer_config_t ledc_timer =
    {
        .speed_mode = LEDC_MODE,
        .duty_resolution = LEDC_DUTY_RES,
        .timer_num = LEDC_TIMER,
        .freq_hz = LEDC_FREQUENCY
    };
    ledc_timer_config(&ledc_timer);

    ledc_channel_config_t ledc_channel =
    {
        .channel = LEDC_CHANNEL,
        .gpio_num = LEDC_GPIOPIN,
        .timer_sel = LEDC_TIMER,
        .speed_mode = LEDC_MODE,
        .duty = 0
    };
    ledc_channel_config(&ledc_channel);
}

void PWM_set(int value)
{
    ledc_set_duty(LEDC_MODE,LEDC_CHANNEL, value);
    ledc_update_duty(LEDC_MODE,LEDC_CHANNEL);
}
