#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
map demolevel;
rom demo;
snd audio;
player bird;

int main()
{
	u32 y;
	u32 x;
	hrt_EnableSoftReset();
	hrt_InitNoIntro();
	mmInitDefault((mm_addr)soundbank_bin, 8);
	demolevel.yscroll = 480;
	hrt_LoadBGTiles((void*)level1Tiles, 832);
	hrt_LoadBGPal((void*)level1Pal, 16);
	hrt_SetDSPMode(0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	hrt_ConfigBG(0, 0, 1, 1, 0, 0, 1, 0);
	REG_SOUNDCNT_H = 0x330E;
	mmStart(MOD_WORLD2, MM_PLAY_LOOP);
	hrt_LoadOBJPal()
	while (1)
	{
		hrt_VblankIntrWait();
		if (keyDown(KEY_UP))
		{
			demolevel.yscroll--;
		}
		if (keyDown(KEY_DOWN))
		{
			demolevel.yscroll++;
		}
		if (keyDown(KEY_LEFT))
		{
			demolevel.xscroll--;
		}
		if (keyDown(KEY_RIGHT))
		{
			demolevel.xscroll++;
		}
		for (y = 0; y < 16; y++)
		{
			for (x = 0; x < 16; x++)
			{
				VRAM[y * 16 + x] = level1Map[y * 150 + x];
			}
		}
	}
}