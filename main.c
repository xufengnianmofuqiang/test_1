#include "stm32f10x.h"                  // Device head
#include "Delay.h"
//#include "bsp_usart.h"
#include "OLED.h"
//#include "Countsensor.h"
//#include "Timer.h"
#include "PWM.h"
#include "ADC.h"

uint16_t ADValue;
float Voltage;

int main(void)
{
	OLED_Init();
	AD_Init();
	
	OLED_ShowString(1, 1, "ADValue:");
	OLED_ShowString(2, 1, "Volatge:0.00V");

	while (1)
	{
		ADValue = ADC_GetValue();
		Voltage = (float)ADValue / 4095 * 3.3;
		
		OLED_ShowNum(1, 9, ADValue, 4);
		OLED_ShowNum(2, 9, Voltage, 1);
		OLED_ShowNum(2, 11, (uint16_t)(Voltage * 100) % 100, 2);
		
		Delay_ms(100);

	}


}



