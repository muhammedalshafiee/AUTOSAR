/*
 * Dio.c
 *
 *  Created on: Oct 7, 2023
 *      Author: Muhammed
 */

#ifndef DIO_H_
#define DIO_H_
#// Standard Library Includes
#include <stdint.h>
#include <stdbool.h>

// Error Value
#define ERROR 0xFFF

// Standard Logic Levels
#define STD_LOW 0x00
#define STD_HIGH 0x01

// Type Definitions

// Dio_LevelType represents the channel level (Read, Write).
typedef uint8_t Dio_LevelType;

// Dio_PortLevelType represents the port level (Read, Write).
typedef uint8_t Dio_PortLevelType;

// Dio_ChannelType represents the numeric ID of a DIO channel PORT pins.
typedef uint8_t Dio_ChannelType;

// Dio_PortType represents the number of ports.
typedef uint8_t Dio_PortType;

// Function Prototypes

/**
 * @brief Reads the level of a specific Digital Input/Output (DIO) channel.
 *
 * @param ChannelId: The ID of the DIO channel to read.
 * @return Dio_LevelType: The level (HIGH or LOW) of the specified channel.
 */
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

/**
 * @brief Writes a specified level to a specific Digital Input/Output (DIO) channel.
 *
 * @param ChannelId: The ID of the DIO channel to write.
 * @param Level: The level (HIGH or LOW) to set on the specified channel.
 */
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);

/**
 * @brief Reads the level of a specific Digital Input/Output (DIO) port.
 *
 * @param PortId: The ID of the DIO port to read.
 * @return Dio_PortLevelType: The level (bit pattern) of the specified port.
 */
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);

/**
 * @brief Writes a specified level to a specific Digital Input/Output (DIO) port.
 *
 * @param PortId: The ID of the DIO port to write.
 * @param Level: The level (bit pattern) to set on the specified port.
 */
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level);

#endif /* DIO_H_ */
