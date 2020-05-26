#include <libheart.h>
#include "interrupt.h"
#include "game.h"

void vblFunc(void)
{
	mmVBlank();
	mmFrame();
	hrt_ScanKeys();
	keys_up = hrt_KeysUp();
	keys_down = hrt_KeysDown();
	keys_held = hrt_KeysHeld();
	if (keys_held == (KEY_A|KEY_B|KEY_SELECT|KEY_START))
	{
		hrt_RegisterRamReset(1);
		hrt_SoftReset(0);
	}
}

void hblFunc(void)
{
	
}