/*
 * Temp_Sensor.h
 *
 * Created: 8/30/2023 3:26:29 PM
 *  Author: galal
 */ 


#ifndef TEMP_SENSOR_H_
#define TEMP_SENSOR_H_

#ifndef F_CPU
#define F_CPU 8000000
#endif

#include <avr/io.h>
#include <util/delay.h>

#define TEMP_DDR DDRA
#define TEMP_SENS_PIN PA0

// initialize sensor
void temp_sensor_init(void);
// get temperature
uint16_t read_temp(void);




#endif /* TEMP_SENSOR_H_ */