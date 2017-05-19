#include <Timer32.h>
#include <Timer32.cpp>

struct esp32_packet
{
	uint8_t sync 0;
	uint8_t sync 1;
	uint8_t version;
	uint8_t count;
	uint16_t data[6];
	uint8_t switches;
}

#define NUMCHANNELS 6
#define HEADERLEN 4
#define PACKETLEN (NUMCHANNELS * 2 + HEADERLEN + 1)
#define SAMPFREQ 10000
#define TIMER2VAL (1024/(SAMPFREQ))
#define LED1 13
#define CAL_SIG 9

volatile unsigned char TXBuf[PACKETLEN];
volatile unsigned char TXIndex;
volatile unsigned char CurrentCh;
volatile unsigned char counter = 0;
volatile unsigned int ADC_Value = 0;

void SETUP_LED1();{
	ledc_isr_register();
}

void toggle_LED1(void){

}

void toggle_GAL_SIG(void){

}

void TIMER_SETUP(){
	Timer32::set(0, 0, , TIMER32OVERFLOW, interrupt, );
}

void setup(){

	SETUP_LED1();

	TXBuf[0] = 0x5a;
	TXBuf[1] = 0xa5;
	TXBuf[2] = 2;
	TXBuf[3] = 0;
	TXBuf[4] = 0x02;
	TXBuf[5] = 0x00;
	TXBuf[6] = 0x02;
	TXBuf[7] = 0x00;
	TXBuf[8] = 0x02;
	TXBuf[9] = 0x00;
	TXBuf[10] = 0x02;
	TXBuf[11] = 0x00;
	TXBuf[12] = 0x02;
	TXBuf[13] = 0x00;
	TXBuf[14] = 0x02;
	TXBuf[15] = 0x00;
	TXBuf[2 * NUMCHANNELS + HEADERLEN] = 0x01;

	TIMER_SETUP();

	<send data>

}

void TIMER32OVERFLOW()
{
	toggle_LED1();
	for (CurrentCh = 0; CurrentCh < 6; CurrentCh++){
		adc1_config_width(3);
		if (CurrentCh >= 4)
			modCurrentCh = CurrentCh + 2;
			adc1_config_channel_atten(modCurrentCh, 0);
			ADC_Value = adc1_get_voltage(modCurrentCh);
			TXBuf[((2 * CurrentCh) + HEADERLEN)] = ((unsigned char)((ADC_Value & 0xFF00) >> 8));
			TXBuf[((2 * CurrentCh) + HEADERLEN + 1)] = ((unsigned char)(ADC_Value & 0x00FF));

		else
			adc1_config_channel_atten(CurrentCh, 0);
			ADC_Value = adc1_get_voltage(CurrentCh);
			TXBuf[((2 * CurrentCh) + HEADERLEN)] = ((unsigned char)((ADC_Value & 0xFF00) >> 8));
			TXBuf[((2 * CurrentCh) + HEADERLEN + 1)] = ((unsigned char)(ADC_Value & 0x00FF));
	}

	for(TXIndex=0; TXIndex < 17; TXIndex++){
		<send data>
	}

	TXBuf[3]++;
	counter++;
	if(counter == 12){
		counter = 0;
		toggle_GAL_SIG();
	}
}
