/*
 * WI-FI Car.c
 *
 * Created: 10/30/2019 5:40:23 PM
 * Author : M_Moawad
 */ 

#include "MOTOR.h"
#include "uart_driver.h"
/*#include "ESP_Driver.h"*/

void test_func (uint8_t received_byte);

int main(void)
{
	
	unsigned char received_Byte;

	UART_Init(9600,test_func);
	UART_Write_String("AT\r\n");
	_delay_ms(2000);
	UART_Write_String("AT+CWMODE=2\r\n");
	_delay_ms(2000);
	UART_Write_String("AT+CIPMUX=1\r\n");
	_delay_ms(2000);
	UART_Write_String("AT+CIPSERVER=1,1234\r\n");
	_delay_ms(2000);
	UART_Write_String("AT+CWSAP=\"IROMAN\",\"123456789\",1,3\r\n");
	_delay_ms(2000);
	
    while (1) 
    {
			received_Byte = UART_Receive_Byte();
			
			switch(received_Byte)
			{
				case 'f':
					PORTB |= (1<<6);
					car_forward();
				break;
				
				case 'b':
					car_backward();
				break;
				
				case 'l':
					car_rotate_left();
				break;
				
				case 'r':
					car_rotate_right();
				break;
				
				case 'a':
					car_amraka();
				break;	
				
				case 's':
					PORTB &= ~(1<<6);
					car_stop();
				break;
				
				default:
				break;
			}

    }
}

void test_func (uint8_t received_byte)
{
	PORTB |= (1<<5);
}