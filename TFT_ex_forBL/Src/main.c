
#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "DIO_interface.h"
#include "STK_interface.h"
#include "MSPI_interface.h"

#include "TFT_interface.h"

#include "image.h"

int main(void)
{
	RCC_voidInitSysClock();
		/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);
		/* Enable SPI1 */
	RCC_voidEnableClock(RCC_APB2,12);

	MGPIO_VidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP); /* A0 */
	MGPIO_VidSetPinDirection(GPIOA,PIN2,OUTPUT_SPEED_2MHZ_PP); /* RST */
	MGPIO_VidSetPinDirection(GPIOA,PIN5,OUTPUT_SPEED_10MHZ_AFPP); /* CLK */
	MGPIO_VidSetPinDirection(GPIOA,PIN7,OUTPUT_SPEED_10MHZ_AFPP); /* MOSI */

	MSTK_voidInit();

	MSPI1_voidInit();


	HTFT_voidInitialize();

	HTFT_voidFillColor(0xffff);

	MSTK_voidSetBusyWait(5000);

	HTFT_voidDisplayImage(arr);



	for(;;);
	return 0;

}
