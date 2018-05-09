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
	hrt_SetDSPMode(0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
	hrt_ConfigBG(0, 0, 1, 1, 0, 0, 1, 0);
	REG_SOUNDCNT_H = 0x330E;
	mmStart(MOD_WORLD2, MM_PLAY_LOOP);
	hrt_LoadOBJPal((void*)b_idlePal, 16);
	hrt_LoadOBJGFX((void*)b_idleTiles, 64);
	hrt_LoadOBJGFX((void*)b_fireTiles, 16);
	hrt_LoadOBJGFX((void*)h_headTiles, 16);
	hrt_LoadOBJGFX((void*)h_flightTiles, 96);
	hrt_LoadOBJGFX((void*)h_xTiles, 16);
	hrt_LoadOBJGFX((void*)h_stageTiles, 128);
	hrt_LoadOBJGFX((u16*)&h_numsTiles, 16);
	hrt_LoadOBJGFX((u16*)&h_numsTiles+48, 16);
	hrt_offsetOAMData += 32;
	hrt_LoadOBJGFX((u16*)&h_numsTiles+16, 16);
	hrt_LoadOBJGFX((u16*)&h_numsTiles+16, 16);
	hrt_LoadOBJGFX((void*)f_0Tiles, 112);
	hrt_LoadOBJGFX((void*)h_emptyTiles, 64);
	hrt_LoadOBJGFX((void*)h_halfTiles, 64);
	hrt_LoadOBJGFX((void*)h_fullTiles, 64);
	hrt_CreateOBJ(0, 120, 80, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	hrt_CreateOBJ(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34);
	hrt_CreateOBJ(2, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38);
	hrt_CreateOBJ(3, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42);
	hrt_CreateOBJ(4, 40, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5);
	hrt_CreateOBJ(5, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,12);
	hrt_CreateOBJ(6, 56, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21);
	hrt_CreateOBJ(7, 80, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 13);
	hrt_CreateOBJ(8, 112, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 17);
	hrt_CreateOBJ(9, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25);
	hrt_CreateOBJ(10, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,26);
	hrt_CreateOBJ(11, 208, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27);
	hrt_CreateOBJ(12, 160, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6);
	hrt_CreateOBJ(13, 192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10);
	while (1)
	{
		hrt_VblankIntrWait();
		hrt_offsetOAMData = 0;
		hrt_offsetOAMPal = 0;
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
				VRAM[y * 16 + x] = level1Map[y * 150 + x+2];
			}
		}
	}
}