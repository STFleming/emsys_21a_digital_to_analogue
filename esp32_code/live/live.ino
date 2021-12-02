
const unsigned int pwmPin = 15;

const unsigned int freq = 5000; // clock divider
const unsigned int pwmChannel = 0; // the PWM hardware id
const unsigned int resolution = 8; // bits of our timer 256

unsigned int * duty_reg = (unsigned int *)(0x3FF59008);
unsigned int * LEDC_HSCH0_CONF0_REG = (unsigned int *)(0x3FF59000);
unsigned int * LEDC_HSCH0_CONF1_REG = (unsigned int *)(0x3FF5900C);

void setup() {

        ledcSetup(pwmChannel, freq, resolution); // configures the timer
        ledcAttachPin(pwmPin, pwmChannel); // configures the connection to pin

}

void loop() {

    for(int i=0; i<256; i++) {
        *LEDC_HSCH0_CONF0_REG = (1 << 2);
        *LEDC_HSCH0_CONF1_REG = (1 << 31);
        *duty_reg = (i << 4);
        delayMicroseconds(10);
    }


}
