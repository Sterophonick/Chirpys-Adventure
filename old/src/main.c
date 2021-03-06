#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"
#include "menu.h"
#include "game.h"

//Entry
int main(void)
{
	hrt_Init();
	hrt_DSPEnableBG(2);
	hrt_DSPDisableBG(1);
	hrt_DSPEnableOBJ();
	hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
	mmInitDefault((mm_addr)soundbank_bin, 20);
	//hrt_irqInit();
	//hrt_irqSet(IRQ_VBLANK, VBLFunc);
	//hrt_irqEnable(IRQ_VBLANK);
	mmSetVBlankHandler(VBLFunc);
	hrt_SetFXLevel(16);
	hrt_FXEnableBG(1,0);
	hrt_FXEnableBG(2,0);
	hrt_FXEnableBackdrop(0);
	hrt_FXEnableOBJ(0);
	hrt_SetKeyStructPointer(keypad);
	hrt_DSPDisableForceBlank();
	g_InitMainMenu();
	return 0;
}