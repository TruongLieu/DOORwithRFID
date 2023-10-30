#include <xc.h>
#include <stdint.h>

#define _XTAL_FREQ 20000000  // Crystal frequency (20 MHz)

// Define your desired baud rate
#define BAUDRATE 9600

// Function to initialize UART reception
void init() {
    // Configure RC2 as an input for UART reception
    TRISC2 = 1;
}

// Function to receive a byte via UART
unsigned char receiveUARTByte() {
    unsigned char receivedData = 0;

    // Wait for the start bit
    while (RC2 == 1);

    // Delay for half a bit period
    __delay_us(500000 / BAUDRATE);

    // Read 8 data bits
    for (int i = 0; i < 8; i++) {
        // Wait for a full bit period
        __delay_us(1000000 / BAUDRATE);

        // Read the bit and store it in receivedData
        receivedData |= (RC2 << i);
    }

    // Wait for the stop bit
    __delay_us(1000000 / BAUDRATE);

    return receivedData;
}

void main() {
    // Initialize the PIC for UART communication
    init();

    // Other initializations if needed

    while (1) {
        char receivedData = receiveUARTByte();

        // Process the received data as needed
        // (e.g., store it in a buffer, perform actions, etc.)
    }
}
