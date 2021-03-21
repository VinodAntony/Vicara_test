#include "delay.h"

void delayinit(){
	SystemCoreClockUpdate();
	SysTick_Config(SystemCoreClock/1000); //1ms delay
}

void delay_ms(uint32_t msval){
	
	//time_ms = msval;
	while(msval--);
}