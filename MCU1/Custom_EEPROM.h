/*
 * EEPROM.h
 *
 * Created: 8/31/2023 12:42:04 AM
 *  Author: galal
 */ 


#ifndef EEPROM_H_
#define EEPROM_H_

#include <avr/io.h>

// write a byte to a given address
void write_eeprom_byte(uint16_t addr, uint8_t val_8);
// read a byte from a given address
uint8_t read_eeprom_byte(uint16_t addr);



#endif /* EEPROM_H_ */