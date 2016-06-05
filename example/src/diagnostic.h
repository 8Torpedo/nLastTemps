/*
 * diagnostic.h
 *
 *  Created on: 3 cze 2016
 *      Author: ciokb
 */

#ifndef SRC_DIAGNOSTIC_H_
#define SRC_DIAGNOSTIC_H_
#include "board.h"

void showTempChange(const uint8_t tempPrev, const uint8_t temp);
int averageTempTable(uint8_t table[], const uint8_t TAB_SIZE);
void lastTemps(uint8_t table[], uint8_t average, uint8_t TAB_SIZE);

#endif /* SRC_DIAGNOSTIC_H_ */
