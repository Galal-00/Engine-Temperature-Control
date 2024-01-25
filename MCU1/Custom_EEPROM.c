/*
 * EEPROM.c
 *
 * Created: 8/31/2023 12:42:12 AM
 *  Author: galal
 */ 

#include "Custom_EEPROM.h"

void write_eeprom_byte(uint16_t addr, uint8_t val_8)
{
	while(EECR & (1<<EEWE));	// wait for previous write
	EEAR = addr;	// set up address register
	EEDR = val_8;	// set up data register
	EECR |= (1<<EEMWE);	// master write enable
	EECR |= (1<<EEWE);	// write enable
}

uint8_t read_eeprom_byte(uint16_t addr)
{
	while(EECR & (1<<EEWE));	// wait for previous write
	EEAR = addr;	// set up address register
	EECR |= (1<<EERE);	// read enable, load data into EEDR register
	return EEDR;
}