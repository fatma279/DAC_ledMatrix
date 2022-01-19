/*  Author  : fatma                          */
/*  Date    : 19 December 2021                  */
/*  version : V1                             */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"

#include "DAC_interface.h"
#include "DAC_private.h"
#include "DAC_config.h"

#include "file.h"

volatile u16 i=0;

void DAC_voidInit(void)
{
	   MGPIO_voidSetPinDirection(GPIOA, PIN8, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN9, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN10, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN11, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN12, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOA, PIN15, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN13, OUTPUT_SPEED_2MHZ_PP);
	   MGPIO_voidSetPinDirection(GPIOC, PIN14, OUTPUT_SPEED_2MHZ_PP);


}
void voidSetDAC(void)
{

	u8 Local_u8BIT;

	for(int iteration=0; iteration<8; iteration++)
	{
		/* Get bit value */
		Local_u8BIT = GET_BIT(Yamn3n3_raw[i],iteration);

		/*Set value in desire pin */
		MGPIO_voidSetPinValue(PIN_DATA[iteration][0],PIN_DATA[iteration][1], Local_u8BIT);
	}

	i++;
	if(i==40031)
	{
		i=0;
	}
}
