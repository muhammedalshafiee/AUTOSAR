/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Muhammed
 */
#include "Port.h"

#define GPIO_PIN_0 0x01
#define GPIO_PIN_1 0x02
#define GPIO_PIN_2 0x04
#define GPIO_PIN_3 0x08
#define GPIO_PIN_4 0x10
#define GPIO_PIN_5 0x20
#define GPIO_PIN_6 0x40
#define GPIO_PIN_7 0x80

#define ALL_GPIO_PINS (GPIO_PIN_0 | GPIO_PIN_1 | GPIO_PIN_2 | GPIO_PIN_3 | GPIO_PIN_4 | GPIO_PIN_5 | GPIO_PIN_6 | GPIO_PIN_7)


// Trial A
//void Port_Init(){
//
//        SYSCTL_RCGCGPIO_R |=0x00000020; // Enabling Clock for PORTf
//        while((SYSCTL_RCGCGPIO_R & 0x00000020 ) == 0){}; // waiting till the clock is activated
//        GPIO_PORTF_LOCK_R = 0x4C4F434B; //
//        GPIO_PORTF_CR_R = 0x1F;
//        GPIO_PORTF_DIR_R = 0x0E;
//        GPIO_PORTF_PUR_R = 0x11;
//        GPIO_PORTF_DEN_R = 0x1F;
//}

/**
 * @brief Initializes the PORTF GPIO pins based on the provided configuration.
 *
 * This function configures the GPIO pins on a specified port based on the
 * provided configuration settings in the 'ConfigPtr' parameter.
 *
 * @param ConfigPtr: A pointer to the configuration settings for the port.
 *
 * @note Before calling this function, ensure that the system clock to the
 *       specified port has been enabled.
 *
 * @note The function waits for the clock to be activated before proceeding.
 *
 * @note The function also unlocks and clears any GPIO locks and configures
 *       the pins with the necessary settings specified in 'ConfigPtr'.
 */
void Port_Init(const Port_ConfigType* ConfigPtr) {
    // Enable the clock for the specified port and wait for activation
    SysCtlPeripheralEnable(ConfigPtr->PortId);
    while (!SysCtlPeripheralReady(ConfigPtr->PortId)) {}

    // Configure pins on the specified port
    GPIODirModeSet(ConfigPtr->PortId, ConfigPtr->Direction);

    // Set pull-up/pull-down settings for all pins on the port
    GPIOPadConfigSet(ConfigPtr->PortId, ALL_GPIO_PINS, ConfigPtr->PullConfig);

    // Enable digital functions for all pins on the port
    GPIODigitalEnable(ConfigPtr->PortId, ConfigPtr->DigitalEnable);
}


