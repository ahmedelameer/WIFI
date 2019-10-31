/*
 * DIO.h
 *
 * Created: 9/13/2019 10:49:22 AM
 *  Author: Moawad
 */ 


#ifndef DIO_H_
#define DIO_H_

typedef enum{NOK,OK}Std_Func_t;

#define MAX_NUM_OF_PINS		(uint8_t)32

/*#include <avr/io.h>*/

#include "DIO_cnfg.h"

Std_Func_t DIO_init (void);

Std_Func_t DIO_write (uint8_t port,uint8_t pin,uint8_t val);

Std_Func_t DIO_read (uint8_t port,uint8_t pin,uint8_t * Pval);

#endif /* DIO_H_ */