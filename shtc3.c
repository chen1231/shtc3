#include "stm32l0xx.h"
#include "shtc3.h"

extern I2C_HandleTypeDef hi2c1;

float  get_decimal_temp_celsius()
{
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,wakeup_cmd ,2 ,100);
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,measurement_cmd ,2 ,100);
	HAL_I2C_Master_Receive (&hi2c1 ,0xE1 ,measure_data ,6 ,100);

	temperature=(int )measure_data[0]*256+(int )measure_data[1];
	temperature_decimal_celsius= (-45)+ (175*temperature) /65536.0;
	return temperature_decimal_celsius;
}

float get_decimal_humidity ()
{
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,wakeup_cmd ,2 ,100);
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,measurement_cmd ,2 ,100);
	HAL_I2C_Master_Receive (&hi2c1 ,0xE1 ,measure_data ,6 ,100);
	
	humidity = (int )measure_data[3]*256+(int )measure_data[4];		//16bit hum transferred to float
	humidity_decimal=100*(humidity/65536.0);
	
	return humidity_decimal;
}

float temp_to_decimal_fahrenheit ()
{
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,wakeup_cmd ,2 ,100);
	HAL_I2C_Master_Transmit(&hi2c1 ,0xE0 ,measurement_cmd ,2 ,100);
	HAL_I2C_Master_Receive (&hi2c1 ,0xE1 ,measure_data ,6 ,100);
	
	temperature=(int )measure_data[0]*256+(int )measure_data[1];
	temperature_decimal_celsius= (-45)+ (175*temperature) /65536.0;	
	
	temperature_decimal_fahrenheit=(1.8*temperature_decimal_celsius)+32;
	
	return temperature_decimal_fahrenheit;
}