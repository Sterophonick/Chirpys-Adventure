#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"

//Entry
int main(void)
{
	hrt_Init();
	hrt_DSPDisableForceBlank();
	hrt_DSPEnableBG(2);
	hrt_DSPEnableBG(0);
	hrt_DSPEnableOBJ();
	hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
	mmInitDefault((mm_addr)soundbank_bin, 20);
}