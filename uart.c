#include "uart.h" // Include our header-file

void USART2_Init(void){ // Start definition of the function USART2_Init()

 RCC->APB1ENR  |=  0x20000; /* Set the USART2EN bit in the RCC_APB1ENR register to 1.
                               This enables the USART2 clock. */

 RCC->AHB1ENR   |=0x01; /* Set the GPIOAEN bit in the RCC_AHB1ENR register to 1.
                           This enables the GPIOA clock. */

 
GPIOA->MODER &=~0x00F0; /* Set bits [4:7] in the GPIOA_MODER register to 0.
                           This sets MODER2 and MODER3 (pin A2 and pin A3) to be inputs.
                           (reset state) */
GPIOA->MODER |= 0x00A0; /* Set bits 5 and 7 in the GPIOA_MODER register to 1.
                           Together with the previous line, this sets bits [4:7] of the
                           GPIOA_MODER register to 1010, which sets pins A2 and A3 to
                           alternate function mode. */

/* The reference manual uses AFRL and AFRH, but I'm assuming that AFR[0] means AFRL. */
 GPIOA->AFR[0] &= ~0xFF00; /* Sets bits [8:15] in GPIOA_AFRL to 0. */
 GPIOA->AFR[0] |= 0x7700; /* Together with the previous line sets bits [8:15] in
                             GPIOA_AFRL to 0111 0111, which means that AFRL2 and AFRL3
                             is set to AF7. Another way of putting it is that we set the
                             alternate function for port A, bit 2 and 3.
                             I still can't find what AF7 (assuming alternate function 7)
                             specifies though. *shrugs* */


USART2->BRR  =  0x0683; /* Sets the USART2 Baud Rate Register to 0x0683, which means
                           that the mantissa of the USART Divider is set to 0x68 = 104,
                           and the fraction of the USART Divider is set to 3.
                           This means the USART Clock will be the System clock divided
                           by 68.3. */
USART2->CR1  =  0x000C; /* Sets USART2_CR1 to 0x000C, which sets bits 2 and 3 to 1, and
                           the rest to 0. This sets all the flags that control the USART
                    in CR1 to vairous things, including disabling the USART, disabling
                           parity, sets the USART to use 8 data bits, inhibiting
                           interrupts, enables transmitter, and enables receiver. */
USART2->CR2  =  0x000; /* Sets USART2_CR2 to 0, which sets all the flags that control
                          the USART in CR2 to various things, including disabling LIN
                          mode, disables the clock pin, and more settings that has to do
                          with the LIN mode. */
USART2->CR3  =  0x000; /* Sets USART_CR3 to 0, which sets all the flags that control the
                          USART in CR3 to various things, which has to do with different
                          modes it can be set to use. */
USART2->CR1  |=  0x2000; /* Sets bit 13 in USART_CR1 to 1, which enables the UART now
                            that all the configurations are done. */
	
	

}

int USART2_write(int ch){ /* Start inline definition of USART2_write(int). */

	while(!(USART2->SR & 0x0080)){} /* Wait until bit 7 in USART2_SR (TXE) is 1, as
                                          this indicate the USART is done transmitting. */
	USART2->DR = (ch & 0xFF); /* Put ch in the USART's Data Register, which will send
                                     the character. */
	
  return ch; /* Return the character we just sent. */
}

int USART2_read(void){ /* Start inline definition of USART2_read(). */
  while(!(USART2->SR & 0x0020)){} /* Wait until bit 5 in USART2_SR (RXNE) is 1, as this
                                     indicate that the USART contains data ready to be
                                     read. */
	return USART2->DR; /* Read the value in the USART's Data Register and return it.*/
}

struct __FILE { int handle; }; /* A Struct for IO-events */
FILE __stdin  = {0};
FILE __stdout = {1};
FILE __stderr = {2};


int fgetc(FILE *f) {
    int c;

    c = USART2_read(); /* Read character from terminal */

    if (c == '\r') {
        USART2_write(c); /* Write character \n to terminal */
        c = '\n';
    }

    USART2_write(c); /* Echo */

    return c;
}



int fputc(int c, FILE *f) { /* Input function för writing to terminal */
    return USART2_write(c);
}


int n;
char str[80];
		
void test_setup(void){
	
	printf("please enter a number: ");
	scanf("%d", &n);
	printf("the number entered is: %d\r\n", n);
	printf("please type a character string: ");
	gets(str);
	printf("the character string entered is: ");
	puts(str);
	printf("\r\n");
	
}
