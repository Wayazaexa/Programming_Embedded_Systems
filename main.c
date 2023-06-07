#include "uart.h" // Include the UART code


int main() // Begin the main function
{

    USART2_Init(); // Call the init-function

    //test_setup();
    printf("Hello there from main function"); // Print to standard output
    while (1) { // Infinite loop

    }

}
