#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"
#include "menu.h"

//Entry
int main(void)
{
	hrt_Init();
	hrt_DSPDisableForceBlank();
	hrt_DSPEnableBG(1);
	hrt_DSPEnableBG(2);
	hrt_DSPEnableOBJ();
	hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
	mmInitDefault((mm_addr)soundbank_bin, 20);
	g_InitMainMenu();
}