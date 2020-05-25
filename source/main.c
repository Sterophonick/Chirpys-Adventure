#include <libheart.h>
#include "data.h"
#include "interrupt.h"
#include "sound.h"

u8 test;

int main()
{
	mmInitDefault((void*)soundbank_bin, 16);
	mmStart(MOD_ENDING, MM_PLAY_LOOP);
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
	initSoundEffects();
	test = mmEffectEx(&gDebugConfirm);
	while(1)
	{
		hrt_VblankIntrWait();
	}
	return 0;
}