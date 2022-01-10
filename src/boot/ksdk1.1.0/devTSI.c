#include <stdint.h>

/*
 *	config.h needs to come first
 */
#include "config.h"

#include "fsl_port_hal.h"
#include "fsl_hwtimer.h"

#include "SEGGER_RTT.h"
#include "gpio_pins.h"
#include "warp.h"
#include "devTSI.h"



/*
 *	Override Warp firmware's use of these pins and define new aliases.
 */
enum
{
	kTSIPinA		= GPIO_MAKE_PIN(HW_GPIOB, 6),
	kTSIPinB		= GPIO_MAKE_PIN(HW_GPIOB, 7),
};




int
devTSIinit(void)
{
	/*
	 *	Redundancy, in case these are set elsewhere (besides boot.c, which I removed).
	 *
	 *	Reconfigure to use as GPIO.
	 */
	PORT_HAL_SetMuxMode(PORTB_BASE, 6u, kPortMuxAsGpio);
	PORT_HAL_SetMuxMode(PORTB_BASE, 7u, kPortMuxAsGpio);
	
	
	GPIO_DRV_ClearPinOutput(kTSIPinA);
	GPIO_DRV_ClearPinOutput(kTSIPinB);
	
	return 0;
}

uint32_t
readSensorTSI(int pin)
{
	uint32_t	pinOutput;
	pinOutput = GPIO_DRV_ReadPinInput(pin);
	
	return pinOutput;
}

void
printSensorDataTSI(void)
{
	uint32_t	TSIpinA;
	uint32_t	TSIpinB;
	
	TSIpinA = readSensorTSI(kTSIPinA);
	TSIpinB = readSensorTSI(kTSIPinB);
	
	warpPrint(" %d, %d,", TSIpinA, TSIpinB);
}

/*bool
touchDetector(void)		// Clock loops after 32768
{
	uint32_t	sensorReadA;
	uint32_t	sensorReadB;
	uint32_t	clockStart;
	uint32_t	clockEnd;
	
	HWTIMER_SYS_Start();
	
	GPIO_DRV_SetPinDir(PTB,6,0);	// Setting PTB6 and 7 to input (high impedance) mode.
	GPIO_DRV_SetPinDir(PTB,7,0);
	
	if(sensorReadA || sensorReadB == 1)
	{
		warpPrint("Bits not set to 0 properly");
		break;
	}
	
	while(timer < t_max)
	{
		sensorReadA = readSensorTSI(kTSIPinA);
		sensorReadB = readSensorTSI(kTSIPinB);
		if(sensorReadA || sensorReadB == 1)
		{
			HWTIMER_SYS_Stop;
			break;
		}
	}
	return 0;
}*/
