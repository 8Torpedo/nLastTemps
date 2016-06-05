/*
 * diagnostic.c
 *
 *  Created on: 3 cze 2016
 *      Author: ciokb
 */

#include "diagnostic.h"

enum {LED_RED, LED_GREEN, LED_BLUE};

void showTempChange(const uint8_t tempPrev, const uint8_t temp){

	if(tempPrev==temp){
		Board_LED_Set(LED_GREEN,TRUE);
		Board_LED_Set(LED_BLUE,FALSE);
		Board_LED_Set(LED_RED,FALSE);
	}
	else if(tempPrev>temp){
		Board_LED_Set(LED_BLUE,TRUE);
		Board_LED_Set(LED_GREEN,FALSE);
		Board_LED_Set(LED_RED,FALSE);
	}
	else if(tempPrev<temp){
		Board_LED_Set(LED_RED, TRUE);
		Board_LED_Set(LED_BLUE,FALSE);
		Board_LED_Set(LED_GREEN,FALSE);
	}
}

int averageTempTable(uint8_t table[], const uint8_t TAB_SIZE){
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

void lastTemps(uint8_t table[], uint8_t average, uint8_t TAB_SIZE){
	TAB_SIZE-=3;
	if ((table[TAB_SIZE++]>average)&&(table[TAB_SIZE++]>average)&&(table[TAB_SIZE++]>average)){
		Board_LED_Set(LED_RED, TRUE);
		Board_LED_Set(LED_BLUE,FALSE);
		Board_LED_Set(LED_GREEN,FALSE);
	} else if((table[TAB_SIZE++]<average)&&(table[TAB_SIZE++]<average)&&(table[TAB_SIZE++]<average)){
		Board_LED_Set(LED_RED, FALSE);
		Board_LED_Set(LED_BLUE,TRUE);
		Board_LED_Set(LED_GREEN,FALSE);
	} else{
		Board_LED_Set(LED_RED, FALSE);
		Board_LED_Set(LED_BLUE,FALSE);
		Board_LED_Set(LED_GREEN,TRUE);
	}
}



