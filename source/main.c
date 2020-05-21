#include <libheart.h>
#include "soundbank_bin.h"
#include "soundbank.h"
#include "interrupt.h"

int main()
{
	mmInitDefault((void*)soundbank_bin, 16);
	mmStart(MOD_WORLD4, MM_PLAY_LOOP);
	hrt_InitIRQ();
	hrt_EnableIRQ(IRQ_VBLANK);
	hrt_SetIRQ(IRQ_VBLANK, vblFunc);
	hrt_DSPDisableForceBlank();
	hrt_DSPEnableBG(2);
	hrt_DSPSetBGMode(0);
	hrt_DSPEnableOBJ();
	hrt_SetFXMode(FX_MODE_BRIGHTEN);
	hrt_SetFXLevel(16);
	hrt_FXEnableBG(1,0);
	hrt_FXEnableBG(2,0);
	hrt_FXEnableBackdrop(0);
	hrt_FXEnableOBJ(0);
	while(1)
	{
		hrt_VblankIntrWait();
	}
	return 0;
}