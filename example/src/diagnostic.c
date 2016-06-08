/*
 * diagnostic.c
 *
 *  Created on: 3 cze 2016
 *      Author: ciokb
 */

#include "diagnostic.h"

enum {LED_RED, LED_GREEN, LED_BLUE};

int averageTemp(uint8_t table[], const uint8_t TAB_SIZE){
	uint8_t average = 0;
	uint16_t sum = 0;
	uint8_t index =0;
	do{
		sum+=table[index];
		index++;
	}while (index<TAB_SIZE);

	average = sum / index;
	return average;
}

void lastTemps(uint8_t table[], uint8_t average, uint8_t TAB_SIZE, const uint8_t index){
	uint8_t rising=0;
	uint8_t falling=0;
	uint8_t stable=0;
	uint8_t lastTAB_SIZE = TAB_SIZE - index;

	while (lastTAB_SIZE<TAB_SIZE){
		if(table[lastTAB_SIZE]<average){
			falling++;
		} else if(table[lastTAB_SIZE]>average){
			rising++;
		} else if(table[lastTAB_SIZE]==average){
			stable++;
		}
		lastTAB_SIZE++;
	}
	if((falling>rising)&&(falling>stable)){
		if(falling==index){
			Board_LED_Set(LED_RED, FALSE);
			Board_LED_Set(LED_BLUE,TRUE);
			Board_LED_Set(LED_GREEN,FALSE);
		}
	} else if((rising>falling)&&(rising>stable)){
		if(rising==index){
			Board_LED_Set(LED_RED, TRUE);
			Board_LED_Set(LED_BLUE,FALSE);
			Board_LED_Set(LED_GREEN,FALSE);
		}
	} else if((stable>rising)&&(stable>falling)){
		if(stable==index){
			Board_LED_Set(LED_RED, FALSE);
			Board_LED_Set(LED_BLUE,FALSE);
			Board_LED_Set(LED_GREEN,TRUE);
		}
	}
}



