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
	hrt_DSPSetBGMode(3);
	while(1)
	{
		hrt_VblankIntrWait();
	}
}