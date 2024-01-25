/*
 * WDT.c
 *
 * Created: 8/31/2023 7:40:37 PM
 *  Author: galal
 */ 

#include "WDT.h"

void WDT_enable(void)
{
	WDTCR = (1<<WDE);	// Enable WDT, minimum number of cycles (16K)
}

void WDT_disable(void)
{
	WDTCR = (1<<WDTOE) | (1<<WDE);	// WDT turn-off enabled
	WDTCR = 0x00;	// WDT disabled
}