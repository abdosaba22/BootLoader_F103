
#ifndef TFT_INTERFACE_H
#define TFT_INTERFACE_H


void HTFT_voidInitialize(void);

void HTFT_voidDisplayImage(const u16 * Copy_Image);

void HTFT_voidFillColor(u16  Copy_u16Color);

void HTFT_voidDrawRect(u8 x1, u8 x2, u8 y1, u8 y2, u16  Copy_u16Color);

void HTFT_voidDrawChar(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 charcter);

void HTFT_voidDrawString(u8 x1,u8 y1,u16 CharColor, u16 BackColor, u8 * string);

#endif
