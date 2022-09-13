#include "mbed.h"
 
DigitalIn mybutton(BUTTON1,PullUp); // Pushbutton input (PC_13)
InterruptIn button(BUTTON1);        // Pusbutton interrupt
volatile uint16_t counts;           // counter variable

void button_pressed() {
    counts++;                       // counts button presses
}
 
int main() {   
    button.mode(PullUp);             // Enable internal pullup
    button.fall(&button_pressed);    // Attach function to falling edge
    while (true) {
        counts = 0;                  // Clear counter
        printf("Press & release switch... \r\n");
        while (mybutton);            // Wait for button press
        ThisThread::sleep_for(20ms); // Debounce delay
        while (!mybutton);           // Wait for button release
        ThisThread::sleep_for(20ms); // Debounce delay
        printf("Button pressed %d times\r\n",counts);
    }
}