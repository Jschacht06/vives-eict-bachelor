// Uitlezen van een MPU9250 via I²C (Sparkfun breakout board) (7-bit adres = 0x68).
//
// Dit breakout board bevat reeds 10kOhm pull-up weerstanden naar de 3V3.
//
// OPM: Alle registers van de MPU9250 staan na reset op 0x00, behalve Who Am I en het Power management register 
// (adres 0x6B = 107 staat op 0x01 = Auto selects the best available clock source – PLL if ready, else use the Internal oscillator).

#include "mpu9250.h"
#include "main.h"

void InitMpu9250(I2C_HandleTypeDef* hi2c)
{
	uint32_t waitSteps = 0;
	uint8_t data[2];
	
	// MPU Resetten.
	data[0] = 0x6B;
	data[1] = 0x80;
	HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), data, 2, 100);	
	
	// Wachten tot heropstart...
	for(waitSteps = 0; waitSteps < 500000 ; waitSteps++)
		__NOP();	
	
	// Range Gyro instellen.
	data[0] = 0x1B;
	data[1] = 0x18;
	HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), data, 2, 100);	
	
	// Magnetometer instellen.
	data[0] = 0x6A;
	data[1] = 0x00;
	HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), data, 2, 100);

	// I²C Bypass enable modus.
	data[0] = 0x37;
	data[1] = 0x02;
	HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), data, 2, 100);	
	
	// Continuous measurement mode 2 (dat is meten op 100Hz), in 16-bit mode (magnetometer).
	data[0] = 0x0A;
	data[1] = 0x16;
	HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_MAGNETOMETER << 1), data, 2, 100);
}

uint8_t WhoAmIMpu9250(I2C_HandleTypeDef* hi2c)
{	
    uint8_t regAddr = 0x75; // Het adres van het WHO_AM_I register
    uint8_t data = 0;
    
    HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), &regAddr, 1, 100);
    
    HAL_I2C_Master_Receive(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), &data, 1, 100);
    
    return data; // Zou 0x71 moeten zijn
}

uint8_t ReadIdAK8963(I2C_HandleTypeDef* hi2c)
{
    uint8_t regAddr = 0x00; 
    uint8_t data = 0;
    
    HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_MAGNETOMETER << 1), &regAddr, 1, 100);
    
    HAL_I2C_Master_Receive(hi2c, (SLAVE_ADDRESS_MAGNETOMETER << 1), &data, 1, 100);
    
    return data; // Zou 0x48 moeten zijn
}
Mpu9250 ReadMpu9250(I2C_HandleTypeDef* hi2c)
{
    Mpu9250 sensordata;
    uint8_t data[14];
    uint8_t magData[7];
    uint8_t regAddr;
	
		// imu uitlezen
    regAddr = 0x3B;
    HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), &regAddr, 1, 100);

    HAL_I2C_Master_Receive(hi2c, (SLAVE_ADDRESS_GYRO_ACC << 1), data, 14, 100);

    sensordata.accX  = (int16_t)((data[0]  << 8) | data[1]);
    sensordata.accY  = (int16_t)((data[2]  << 8) | data[3]);
    sensordata.accZ  = (int16_t)((data[4]  << 8) | data[5]);
    sensordata.temp  = (int16_t)((data[6]  << 8) | data[7]);
    sensordata.gyroX = (int16_t)((data[8]  << 8) | data[9]);
    sensordata.gyroY = (int16_t)((data[10] << 8) | data[11]);
    sensordata.gyroZ = (int16_t)((data[12] << 8) | data[13]);

    // magnetometer uitlezen
    regAddr = 0x03;
    HAL_I2C_Master_Transmit(hi2c, (SLAVE_ADDRESS_MAGNETOMETER << 1), &regAddr, 1, 100);

    HAL_I2C_Master_Receive(hi2c, (SLAVE_ADDRESS_MAGNETOMETER << 1), magData, 7, 100);

    sensordata.magnX = (int16_t)((magData[1] << 8) | magData[0]);
    sensordata.magnY = (int16_t)((magData[3] << 8) | magData[2]);
    sensordata.magnZ = (int16_t)((magData[5] << 8) | magData[4]);

    return sensordata;
}
