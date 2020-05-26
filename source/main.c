#include <libheart.h>
#include "data.h"
#include "interrupt.h"
#include "sound.h"
#include "animations.h"

int main()
{
	mmInitDefault((void*)soundbank_bin, 24);
	mmStart(MOD_WORLD1, MM_PLAY_LOOP);
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
	mmEffectEx(&gUnkClockReverb);
	while(1)
	{
		hrt_VblankIntrWait();
		animPlayer();
	}
	return 0;
}