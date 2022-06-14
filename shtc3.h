#include "stm32l0xx.h"


static uint8_t wakeup_cmd [2]={0x35,0x17};
static uint8_t measurement_cmd  [2]={0x64,0x58};
static uint8_t sleep_cmd  [2]={0xB0,0x98};
static uint8_t measure_data[6];

static int temperature=0;
static int humidity=0;

static float temperature_decimal_celsius=0;
static float humidity_decimal=0;
static float temperature_decimal_fahrenheit=0;


float get_decimal_temp_celsius ();
float get_decimal_humidity ();
float temp_to_decimal_fahrenheit ();


