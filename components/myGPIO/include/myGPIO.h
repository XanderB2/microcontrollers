// LED

void myGPIO_LED_aan(int pin);
void myGPIO_LED_uit(int pin);
void myGPIO_LED_toggle(int pin);
void myGPIO_LED_setup(int pin);
void myGPIO_LED_value(int pin, int value);

// INPUT KNOP

void myGPIO_KNOP_setup(int pin);
int myGPIO_KNOP_value(int pin);
int myGPIO_KNOP_flank(int pin);