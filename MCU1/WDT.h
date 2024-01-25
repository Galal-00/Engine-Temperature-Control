/*
 * WDT.h
 *
 * Created: 8/31/2023 7:40:27 PM
 *  Author: galal
 */ 


#ifndef WDT_H_
#define WDT_H_

#include <avr/io.h>

// Enables the WDT on the smallest possible interval for reset
void WDT_enable(void);
// Disables WDT
void WDT_disable(void);


#endif /* WDT_H_ */