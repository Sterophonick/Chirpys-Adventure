#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
extern rom game;

void Credits()
{
	register u32 oldscroll;
	register u16 string;
	register u16 scroll;
	hrt_DSPSetBGMode(0);
	hrt_DSPEnableBG(2);
	hrt_DSPDisableBG(0);
	hrt_DSPDisableBG(1);
	hrt_DSPDisableOBJ();
	hrt_DSPDisableBG(3);
	hrt_DSPDisableForceBlank();
	hrt_InitTiledText(2);
	hrt_PrintOnTilemap(6, 20, (char*)gl_credits[0]);
	mmStart(MOD_CREDITS, MM_PLAY_LOOP);
	register u8 temp;
	for (scroll = 0; scroll < 512; scroll++)
	{
		hrt_SleepF(5);
		REG_BG2VOFS = scroll;
		if(oldscroll/ 8 != scroll / 8)
		{
			oldscroll = scroll;
			string++;
			temp = 30-strlen((char*)gl_credits[string]);
			hrt_PrintOnTilemap(hrt_Div(temp, 2), 20+string, (char*)gl_credits[string]);
			hrt_PrintOnTilemap(0, string-40, "                              ");
		}
	}
	for (scroll = 0; scroll < 312; scroll++)
	{
		hrt_SleepF(5);
		REG_BG2VOFS = scroll;
		if(oldscroll/ 8 != scroll / 8)
		{
			oldscroll = scroll;
			string++;
			temp = 30-strlen((char*)gl_credits[string]);
			hrt_PrintOnTilemap(hrt_Div(temp, 2), 20+string, (char*)gl_credits[string]);
			hrt_PrintOnTilemap(0, string-40, "                              ");
		}
	}
	hrt_SleepF(450);
	hrt_ColdReset();
}