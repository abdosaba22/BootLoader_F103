#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "DIO_interface.h"
#include "MSPI_interface.h"
#include "MSPI_config.h"
#include "MSPI_private.h"

void (*CallBack)(u8);

void MSPI1_voidInit(void)
{
	MSPI1->CR1 = 0x0347;
}

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTransmit, u8 *Copy_DataToReceive)
{
	/* Clear For Slave Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	/* cause it active low */
	
	/* Send Data */
	MSPI1 -> DR = Copy_u8DataToTransmit;
	
	/* Wait Busy Flag to finish */
	while (GET_BIT(MSPI1 -> SR, 7) == 1);

 	/* Return to the received data */
	*Copy_DataToReceive = MSPI1 -> DR;
	
	/* Set Salve Select Pin */
	MGPIO_VidSetPinValue(MSPI1_SLAVE_PIN,HIGH);
}
