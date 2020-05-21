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
}

void hblFunc(void)
{
	
}