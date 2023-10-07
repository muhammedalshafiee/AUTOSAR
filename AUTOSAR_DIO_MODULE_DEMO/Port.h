/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Muhammed
 */

#ifndef PORT_H_
#define PORT_H_
#include <stdint.h>
#include "inc/hw_types.h"

typedef struct {
    uint32_t PortId;          // Port ID (e.g., SYSCTL_PERIPH_GPIOF)
    uint32_t UnlockValue;     // Unlock value for GPIO_PORTx_LOCK_R
    uint32_t CRValue;         // Value for enabling changes to GPIOCR register
    uint8_t Direction;        // Direction configuration for pins
    uint8_t PullConfig;       // Pull-up/pull-down configuration for pins
    uint8_t DigitalEnable;    // Digital enable configuration for pins
} Port_ConfigType;

void Port_Init(const Port_ConfigType* ConfigPtr);





#endif /* PORT_H_ */
