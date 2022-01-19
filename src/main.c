/*  Author  : Fatma                          */
/*  Date    : 19 December 2021                */
/*  version : V1                             */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "LEDMRX_interface.h"
#include "DAC_interface.h"
#include "STK_interface.h"


/* array of data to display*/
u8 Data[48]={0, 0, 139, 127, 139, 0, 0, 0,0, 0, 171, 95, 139, 0, 0, 0,0, 0, 139, 95, 171,
		     0, 0, 0,0, 0, 171, 95, 139, 0, 0, 0,0, 0, 155, 111, 139, 0, 0, 0,0, 0, 171, 95, 139, 0, 0, 0};



void main(void)
{
   MRCC_voidInitSysClock();                 /*chose clock system to HSE 8MHZ */
   MRCC_voidEnableClock(APB2, IOPA);        /*Enable GPIOA clock*/
   MRCC_voidEnableClock(APB2, IOPB);        /*Enable GPIOB clock */
   MRCC_voidEnableClock(APB2, IOPC);        /*Enable GPIOc clock */

   /*Init DAC pins*/
   DAC_voidInit();

   MSTK_voidInit();
   MSTK_voidSetIntervalPeriodic( 125, voidSetDAC);

	/*Init LedMatrix pins*/
	HLEDMRX_voidInit();

   while(1)
   {
		/*Start animating*/
		   HLEDMRX_voidStartAnimating(Data);
   }



}
