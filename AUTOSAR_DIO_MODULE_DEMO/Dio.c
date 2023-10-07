/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Muhammed
 */


#include "Dio.h"

// Macro to read a specific bit from a byte
#define READ_BIT(byte, bitNum) (((byte) >> (bitNum)) & 1)

// Macro to set a specific bit in a byte to 1
#define WRITE_BIT(byte, bitNum, value) ((byte) |= ((value) << (bitNum)))

// Macro to write a value (data) to a specific port (portReg)
#define WRITE_PORT(portReg, data) ((portReg) = (data))


/**
 * @brief Reads the level of a specific Digital Input/Output (DIO) channel.
 *
 * @param ChannelId: The ID of the DIO channel to read.
 * @return Dio_LevelType: The level (HIGH or LOW) of the specified channel.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId) {
    uint16_t value = 0;
    uint8_t port = ChannelId / 8;
    uint8_t pin = ChannelId % 8;

    if (ChannelId) {
        switch (port) {
            case 0 ... 5 :
                value = READ_BIT(port, pin);
                break;
            default :
                value = ERROR;
                break;
        }
    }

    return value;
}


/**
 * @brief Writes a specified level to a specific Digital Input/Output (DIO) channel.
 *
 * @param ChannelId: The ID of the DIO channel to write.
 * @param Level: The level (HIGH or LOW) to set on the specified channel.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level) {
    uint8_t port = ChannelId / 8;
    uint8_t pin = ChannelId % 8;

    switch (port) {
        case 0 ... 5 :
            WRITE_BIT(port, pin, Level);
            break;
    }
}


/**
 * @brief Reads the level of a specific Digital Input/Output (DIO) port.
 *
 * @param PortId: The ID of the DIO port to read.
 * @return Dio_PortLevelType: The level (bit pattern) of the specified port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId) {
    uint8_t value = 0;

    switch (PortId) {
        case 0 ... 5 :
            value = PortId;
            break;
    }

    return value;
}


/**
 * @brief Writes a specified level to a specific Digital Input/Output (DIO) port.
 *
 * @param PortId: The ID of the DIO port to write.
 * @param Level: The level (bit pattern) to set on the specified port.
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level) {
    switch (PortId) {
        case 0 ... 5 :
            WRITE_PORT(PortId, Level);
            break;
    }
}
