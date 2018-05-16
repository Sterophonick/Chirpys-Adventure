#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
map demolevel;
rom game;
snd audio;
player bird;
GameMap gGameMap;
gmenu menu;
col collision;
sram SaveFiles;
void vblFunc(void);

int main()
{
	mm_sound_effect m_select = {
		{ SFX_M_SELECT },			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	mm_sound_effect m_confirm = {
		{ SFX_M_CONFIRM },			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	mm_sound_effect s_page = {
		{ SFX_S_PAGE },			// id
		(int)(1.0f * (1 << 10)),	// rate
		0,		// handle
		255,	// volume
		128,	// panning
	};
	hrt_EnableSoftReset();
	hrt_EnableRTC();
	hrt_InitNoIntro();
	unsigned char *p = (unsigned char*)&SaveFiles.RNGSeed;
	p[0] = hrt_LoadByte(0x00);
	p[1] = hrt_LoadByte(0x01);
	hrt_SeedRNG(SaveFiles.RNGSeed);
	mmSetVBlankHandler(vblFunc);
	hrt_SetDSPMode(4, //Mode
		0,								  //CGB Mode
		0,								  //Frame Select
		0,                               //Unlocked HBlank
		0,                               //Linear OBJ Tile Mapping
		0,                               //Force Blank
		0,                               //BG 0
		0,                               //BG 1
		1,                               //BG 2
		0,                               //BG 3
		0,                               //OBJ
		0,                               //Win 0
		0,                               //Win 1
		0);							  //OBJWin

	hrt_SetFXMode(1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0);
	hrt_SetFXLevel(31);
	hrt_LZ77UnCompVRAM((u32)disclaimerBitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
	hrt_LoadBGPal((void*)disclaimerPal, 16);
	hrt_offsetBGPal = 0;
	for (game.i = 0; game.i < 17; game.i++) {
		hrt_SetFXLevel(16 - game.i);
		hrt_SleepF(1);
	}
	game.i = 0;
	while (!((game.i == 255) | (keyDown(KEY_A)))) {
		game.i++;
		hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
		hrt_SleepF(1); //Waits one frame
	}
	for (game.i = 0; game.i < 17; game.i++) {
		hrt_SetFXLevel(game.i);
		hrt_SleepF(1);
	}
	mmInitDefault((mm_addr)soundbank_bin, 8);
	REG_SOUNDCNT_H = 0x330E;
	hrt_LoadBGMap((void*)m_bg_Map, 1024);
	hrt_offsetBGMap = 2048;
	hrt_LoadBGMap((void*)m_title_Map, 1024);
	hrt_LoadBGTiles((void*)m_title_Tiles, 1600);
	hrt_offsetBGTile = 16384;
	hrt_LoadBGTiles((void*)m_bg_Tiles, 864);
	hrt_LoadBGPal((void*)m_bgPalette, 16);
	REG_DISPCNT = 0x1640;
	REG_BG1CNT = 0x0204;
	REG_BG2CNT = 0x000C;
	REG_BG1VOFS = 96;
	mmStart(MOD_THEME, MM_PLAY_LOOP);
	for (game.i = 0; game.i < 17; game.i++) {
		hrt_SetFXLevel(16-game.i);
		hrt_SleepF(1);
	}
	hrt_SleepF(60);
	hrt_LoadOBJPal((void*)m_continuePal, 16);
	hrt_LoadOBJGFX((void*)m_yearTiles, 576);
	hrt_LoadOBJGFX((void*)m_optionsTiles, 256);
	hrt_LoadOBJGFX((void*)m_newgameTiles, 256);
	hrt_LoadOBJGFX((void*)m_continueTiles, 256);
	hrt_LoadOBJGFX((void*)m_exitTiles, 128);
	for (game.i = 96; game.i < 257; game.i += 2)
	{
		hrt_VblankIntrWait();
		REG_BG1VOFS = game.i;
	}
	hrt_SleepF(30);
	hrt_CreateOBJ(0, 104, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
	hrt_CreateOBJ(1, 120, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4);
	hrt_CreateOBJ(2, 136, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 8);
	hrt_CreateOBJ(3, 152, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12);
	hrt_CreateOBJ(4, 168, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 16);
	hrt_CreateOBJ(5, 184, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 20);
	hrt_CreateOBJ(6, 200, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 24);
	hrt_CreateOBJ(7, 216, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 28);
	hrt_CreateOBJ(8, 232, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32);
	for (game.i = 0; game.i < 9; game.i++)
	{
		for (game.i2 = 0; game.i2 < 9; game.i2++)
		{
			hrt_SetOBJXY(&sprites[game.i2], (game.i2 * 16) + 104, 160 - game.i);
		}
		hrt_VblankIntrWait();
	}
	hrt_CreateOBJ(9, 8, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 52);
	hrt_CreateOBJ(10, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 56);
	hrt_CreateOBJ(11, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 60);
	hrt_CreateOBJ(12, 48, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 64);
	for (game.i = 0; game.i < 120; game.i += 4)
	{
		for (game.i2 = 0; game.i2 < 5; game.i2++)
		{
			hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 160 - game.i);
		}
		hrt_VblankIntrWait();
	}
	hrt_CreateOBJ(13, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 68);
	hrt_CreateOBJ(14, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 72);
	hrt_CreateOBJ(15, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 76);
	hrt_CreateOBJ(16, 48, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 80);
	for (game.i = 0; game.i < 112; game.i += 4)
	{
		for (game.i2 = 0; game.i2 < 5; game.i2++)
		{
			hrt_SetOBJXY(&sprites[game.i2 + 13], ((game.i2) * 16) + 8, 160 - game.i);
		}
		hrt_VblankIntrWait();
	}
	hrt_CreateOBJ(17, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 36);
	hrt_CreateOBJ(18, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 40);
	hrt_CreateOBJ(19, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 44);
	hrt_CreateOBJ(20, 48, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48);
	for (game.i = 0; game.i < 104; game.i += 4)
	{
		for (game.i2 = 0; game.i2 < 5; game.i2++)
		{
			hrt_SetOBJXY(&sprites[game.i2 + 17], ((game.i2) * 16) + 8, 160 - game.i);
		}
		hrt_VblankIntrWait();
	}
	hrt_CreateOBJ(21, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 84);
	hrt_CreateOBJ(22, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 88);
	for (game.i = 0; game.i < 96; game.i += 4)
	{
		for (game.i2 = 0; game.i2 < 3; game.i2++)
		{
			hrt_SetOBJXY(&sprites[game.i2 + 21], ((game.i2) * 16) + 8, 160 - game.i);
		}
		hrt_VblankIntrWait();
	}
	hrt_LoadOBJPal((void*)m_arrow4Pal, 16);
	hrt_LoadOBJGFX((void*)m_arrow1Tiles, 16);
	hrt_CreateOBJ(23, 248, 44, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 92);
	for (game.i = 0; game.i < 8; game.i++)
	{
		hrt_SetOBJXY(&sprites[23], 248+game.i, 44);
	}
	hrt_offsetOAMData -= 16;
	u8 uplock = 0;
	u8 downlock = 0;
	while (1)
	{
		game.frames++;
		hrt_VblankIntrWait();
		if ((keyDown(KEY_UP))AND(!(menu.arpos == 0))AND(uplock == 0))
		{
			menu.arpos--;
			uplock = 1;
			audio.menusel = mmEffectEx(&m_select);
		}
		if (!(keyDown(KEY_UP)))
		{
			uplock = 0;
		}
		if ((keyDown(KEY_DOWN))AND(!(menu.arpos == 3))AND(downlock == 0))
		{
			menu.arpos++;
			downlock = 1;
			audio.menusel = mmEffectEx(&m_select);
		}
		if (!(keyDown(KEY_DOWN)))
		{
			downlock = 0;
		}
		hrt_SetOBJXY(&sprites[23], 0, (menu.arpos * 8) + 44);
		if (!(game.frames % 3))
		{
			menu.arframe++;
			if (menu.arframe == 7)
			{
				menu.arframe = 0;
			}
			if (menu.arframe == 0)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 1)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 2)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 3)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow4Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 4)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 5)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
			if (menu.arframe == 6)
			{
				hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014b80, 16, 0x80000000);
			}
		}
		if (keyDown(KEY_A))
		{
			if (menu.arpos == 3)
			{
				audio.menuconf = mmEffectEx(&m_confirm);
				for (game.i = 0; game.i < 128; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 42 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 120; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 13], ((game.i2) * 16) + 8, 50 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 112; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 17], ((game.i2) * 16) + 8, 58 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 104; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 2; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 21], ((game.i2) * 16) + 8, 66 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_EZ4Exit();
			}
			if (menu.arpos == 2)
			{
				audio.menuconf = mmEffectEx(&m_confirm);
				for (game.i = 0; game.i < 128; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 42 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 120; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 13], ((game.i2) * 16) + 8, 50 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 112; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 17], ((game.i2) * 16) + 8, 58 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 104; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 2; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 21], ((game.i2) * 16) + 8, 66 + game.i);
					}
					hrt_VblankIntrWait();
				}
				hrt_offsetOAMData = 0;
				hrt_offsetOAMPal = 0;
				hrt_offsetBGMap = 0;
				hrt_offsetBGPal = 0;
				hrt_offsetBGTile = 0;
				hrt_LoadOBJGFX((void*)m_yearTiles, 576);
				hrt_LoadOBJGFX((void*)m_musvolTiles, 208);
				hrt_LoadOBJGFX((void*)m_sfxvolTiles, 176);
				hrt_LoadOBJGFX((void*)m_creditsTiles, 112);
				hrt_CreateOBJ(9, 8, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 36);
				hrt_CreateOBJ(10, 24, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 38);
				hrt_CreateOBJ(11, 24+16, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 40);
				hrt_CreateOBJ(12, 24+32, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 42);
				hrt_CreateOBJ(13, 24+48, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 44);
				hrt_CreateOBJ(14, 24 + 64, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 46);
				hrt_CreateOBJ(15, 104, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48);
				for (game.i = 0; game.i < 120; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 7; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 160 - game.i);
					}
					hrt_VblankIntrWait();
				}
				hrt_CreateOBJ(16, 8, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 561-512);
				hrt_CreateOBJ(17, 24, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 563 - 512);
				hrt_CreateOBJ(18, 40, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 565 - 512);
				hrt_CreateOBJ(19, 56, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 567 - 512);
				hrt_CreateOBJ(20, 72, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 569 - 512);
				hrt_CreateOBJ(21, 88, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 571 - 512);
				for (game.i = 0; game.i < 112; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 6; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 16], ((game.i2) * 16) + 8, 160 - game.i);
					}
					hrt_VblankIntrWait();
				}
				hrt_CreateOBJ(24, 8, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 572 - 512);
				hrt_CreateOBJ(25, 24, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 574 - 512);
				hrt_CreateOBJ(26, 40, 160, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 576 - 512);
				hrt_CreateOBJ(27, 56, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 578 - 512);
				for (game.i = 0; game.i < 104; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 24], ((game.i2) * 16) + 8, 160 - game.i);
					}
					hrt_VblankIntrWait();
				}
				hrt_CreateOBJ(28, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 84);
				hrt_CreateOBJ(29, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 88);
				for (game.i = 0; game.i < 96; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 2; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 28], ((game.i2) * 16) + 8, 160 - game.i);
					}
					hrt_VblankIntrWait();
				}
				while ((!(keyDown(KEY_B)))OR(!((keyDown(KEY_A))AND(menu.arpos == 3))))
				{
					game.frames++;
					hrt_VblankIntrWait();
					if ((keyDown(KEY_UP))AND(!(menu.arpos == 0))AND(uplock == 0))
					{
						menu.arpos--;
						uplock = 1;
						audio.menusel = mmEffectEx(&m_select);
					}
					if (!(keyDown(KEY_UP)))
					{
						uplock = 0;
					}
					if ((keyDown(KEY_DOWN))AND(!(menu.arpos == 3))AND(downlock == 0))
					{
						menu.arpos++;
						downlock = 1;
						audio.menusel = mmEffectEx(&m_select);
					}
					if (!(keyDown(KEY_DOWN)))
					{
						downlock = 0;
					}
					hrt_SetOBJXY(&sprites[23], 0, (menu.arpos * 8) + 44);
					if (!(game.frames % 3))
					{
						menu.arframe++;
						if (menu.arframe == 7)
						{
							menu.arframe = 0;
						}
						if (menu.arframe == 0)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 1)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 2)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 3)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow4Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 4)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 5)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
						if (menu.arframe == 6)
						{
							hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014b80, 16, 0x80000000);
						}
					}
					if (keyDown(KEY_A))
					{
						if (menu.arpos == 3)
						{
							audio.menuconf = mmEffectEx(&m_confirm);
							for (game.i = 0; game.i < 128; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 7; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 42 + game.i);
								}
								hrt_VblankIntrWait();
							}
							for (game.i = 0; game.i < 120; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 6; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 16], ((game.i2) * 16) + 8, 50 + game.i);
								}
								hrt_VblankIntrWait();
							}
							for (game.i = 0; game.i < 112; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 4; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 24], ((game.i2) * 16) + 8, 58 + game.i);
								}
								hrt_VblankIntrWait();
							}
							for (game.i = 0; game.i < 104; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 2; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 28], ((game.i2) * 16) + 8, 66 + game.i);
								}
								hrt_VblankIntrWait();
							}
							hrt_offsetOAMPal = 0;
							hrt_offsetOAMData = 0;
							hrt_LoadOBJPal((void*)m_continuePal, 16);
							hrt_LoadOBJGFX((void*)m_yearTiles, 576);
							hrt_LoadOBJGFX((void*)m_optionsTiles, 256);
							hrt_LoadOBJGFX((void*)m_newgameTiles, 256);
							hrt_LoadOBJGFX((void*)m_continueTiles, 256);
							hrt_LoadOBJGFX((void*)m_exitTiles, 128);
							hrt_CreateOBJ(9, 8, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 52);
							hrt_CreateOBJ(10, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 56);
							hrt_CreateOBJ(11, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 60);
							hrt_CreateOBJ(12, 48, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 64);
							for (game.i = 0; game.i < 120; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 5; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 160 - game.i);
								}
								hrt_VblankIntrWait();
							}
							hrt_CreateOBJ(13, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 68);
							hrt_CreateOBJ(14, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 72);
							hrt_CreateOBJ(15, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 76);
							hrt_CreateOBJ(16, 48, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 80);
							for (game.i = 0; game.i < 112; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 5; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 13], ((game.i2) * 16) + 8, 160 - game.i);
								}
								hrt_VblankIntrWait();
							}
							hrt_CreateOBJ(17, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 36);
							hrt_CreateOBJ(18, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 40);
							hrt_CreateOBJ(19, 32, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 44);
							hrt_CreateOBJ(20, 48, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 48);
							for (game.i = 0; game.i < 104; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 5; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 17], ((game.i2) * 16) + 8, 160 - game.i);
								}
								hrt_VblankIntrWait();
							}
							hrt_CreateOBJ(21, 0, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 84);
							hrt_CreateOBJ(22, 16, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 88);
							for (game.i = 0; game.i < 96; game.i += 4)
							{
								for (game.i2 = 0; game.i2 < 3; game.i2++)
								{
									hrt_SetOBJXY(&sprites[game.i2 + 21], ((game.i2) * 16) + 8, 160 - game.i);
								}
								hrt_VblankIntrWait();
							}
							break;
						}
						if (menu.arpos == 2)
						{
							audio.menuconf = mmEffectEx(&m_confirm);
							for (game.i = 0; game.i < 17; game.i++) {
								hrt_SetFXLevel(game.i);
								hrt_SleepF(1);
							}
							hrt_offsetBGMap = 0;
							hrt_offsetBGTile = 0;
							hrt_offsetBGPal = 0;
							hrt_SetDSPMode(4, //Mode
								0,								  //CGB Mode
								0,								  //Frame Select
								0,                               //Unlocked HBlank
								0,                               //Linear OBJ Tile Mapping
								0,                               //Force Blank
								0,                               //BG 0
								0,                               //BG 1
								1,                               //BG 2
								0,                               //BG 3
								0,                               //OBJ
								0,                               //Win 0
								0,                               //Win 1
								0);							  //OBJWin

							hrt_SetFXMode(1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0);
							hrt_SetFXLevel(31);
							hrt_LZ77UnCompVRAM((u32)creditsBitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
							hrt_LoadBGPal((void*)creditsPal, 16);
							hrt_offsetBGMap = 0;
							hrt_offsetBGTile = 0;
							hrt_offsetBGPal = 0;
							for (game.i = 0; game.i < 17; game.i++) {
								hrt_SetFXLevel(16-game.i);
								hrt_SleepF(1);
							}
							while (!(keyDown(KEY_A)))
							{
								hrt_VblankIntrWait();
							}
							for (game.i = 0; game.i < 17; game.i++) {
								hrt_SetFXLevel(game.i);
								hrt_SleepF(1);
							}
							hrt_LoadBGMap((void*)m_bg_Map, 1024);
							hrt_offsetBGMap = 2048;
							hrt_LoadBGMap((void*)m_title_Map, 1024);
							hrt_LoadBGTiles((void*)m_title_Tiles, 1600);
							hrt_offsetBGTile = 16384;
							hrt_LoadBGTiles((void*)m_bg_Tiles, 864);
							hrt_LoadBGPal((void*)m_bgPalette, 16);
							REG_DISPCNT = 0x1640;
							for (game.i = 0; game.i < 17; game.i++) {
								hrt_SetFXLevel(16-game.i);
								hrt_SleepF(1);
							}
						}
					}
				}
			}
			if (menu.arpos == 0)
			{
				audio.menuconf = mmEffectEx(&m_confirm);
				for (game.i = 0; game.i < 128; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 9], ((game.i2) * 16) + 8, 42 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 120; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 13], ((game.i2) * 16) + 8, 50 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 112; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 4; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 17], ((game.i2) * 16) + 8, 58 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 104; game.i += 4)
				{
					for (game.i2 = 0; game.i2 < 2; game.i2++)
					{
						hrt_SetOBJXY(&sprites[game.i2 + 21], ((game.i2) * 16) + 8, 66 + game.i);
					}
					hrt_VblankIntrWait();
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_offsetOAMData = 0;
				hrt_offsetOAMPal = 0;
				hrt_offsetBGMap = 0;
				hrt_offsetBGPal = 0;
				hrt_offsetBGTile = 0;
				mmStop();
				hrt_DMA_Copy(3, (u8*)0x02000AD0, (u8*)VRAM, 0xFfffF, 0x80800000);
				hrt_DMA_Copy(3, (u8*)0x02000AD0, (u8*)BGPaletteMem, 0x200, 0x80800000);
				hrt_DMA_Copy(3, (u8*)0x02000AD0, (u8*)&sprites, 0x3FF,  0x80800000);
				hrt_CopyOAM();
				mmStart(MOD_STORY, MM_PLAY_LOOP);
				hrt_SetDSPMode(3, //Mode
					0,								  //CGB Mode
					0,								  //Frame Select
					0,                               //Unlocked HBlank
					0,                               //Linear OBJ Tile Mapping
					0,                               //Force Blank
					0,                               //BG 0
					0,                               //BG 1
					1,                               //BG 2
					0,                               //BG 3
					0,                               //OBJ
					0,                               //Win 0
					0,                               //Win 1
					0);							  //OBJWin
				hrt_SetFXMode(1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0);
				hrt_SetFXLevel(31);
				hrt_LZ77UnCompVRAM((u32)story1Bitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
				hrt_PrintOnBitmap(0, 0, "Chirpy just got home from a");
				hrt_PrintOnBitmap(0, 8, "good lunch.");
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(16 - game.i);
					hrt_SleepF(1);
				}
				game.i = 0;
				while (!((game.i == 255) | (keyDown(KEY_A)))) {
					game.i++;
					hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
					hrt_SleepF(1); //Waits one frame
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_LZ77UnCompVRAM((u32)story2Bitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
				hrt_PrintOnBitmap(0, 0, "He went up to the tree where");
				hrt_PrintOnBitmap(0, 8, "his nest is.");
				audio.pageflip = mmEffectEx(&s_page);
					for (game.i = 0; game.i < 17; game.i++) {
						hrt_SetFXLevel(16 - game.i);
						hrt_SleepF(1);
					}
				game.i = 0;
				while (!((game.i == 255) | (keyDown(KEY_A)))) {
					game.i++;
					hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
					hrt_SleepF(1); //Waits one frame
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_LZ77UnCompVRAM((u32)story3Bitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
				hrt_PrintOnBitmap(0, 0, "But it has gone missing!");
				audio.pageflip = mmEffectEx(&s_page);
					for (game.i = 0; game.i < 17; game.i++) {
						hrt_SetFXLevel(16 - game.i);
						hrt_SleepF(1);
					}
				game.i = 0;
				while (!((game.i == 255) | (keyDown(KEY_A)))) {
					game.i++;
					hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
					hrt_SleepF(1); //Waits one frame
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_LZ77UnCompVRAM((u32)story4Bitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
				hrt_PrintOnBitmap(0, 0, "Chirpy notices tracks nearby");
				hrt_PrintOnBitmap(0, 8, "the tree, and decides to"); 
				hrt_PrintOnBitmap(0, 16, "follow them...");
				audio.pageflip = mmEffectEx(&s_page);
					for (game.i = 0; game.i < 17; game.i++) {
						hrt_SetFXLevel(16 - game.i);
						hrt_SleepF(1);
					}
				game.i = 0;
				while (!((game.i == 255) | (keyDown(KEY_A)))) {
					game.i++;
					hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
					hrt_SleepF(1); //Waits one frame
				}
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
				hrt_DMA_Copy(3, (u8*)0x02000AD0, (u8*)VRAM, 0xFfffF, 0x80800000);
				hrt_DMA_Copy(3, (u8*)0x02000AD0, (u8*)BGPaletteMem, 0x200, 0x80800000);
				hrt_LoadBGTiles((void*)level1Tiles, 832);
				hrt_LoadBGPal((void*)level1Pal, 16);
				hrt_SetDSPMode(0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0);
				REG_BG0CNT = 0x1C04;
				hrt_LoadOBJPal((void*)b_idlePal, 16);
				hrt_LoadOBJGFX((void*)b_idleTiles, 64);
				hrt_LoadOBJGFX((void*)b_fireTiles, 16);
				hrt_LoadOBJGFX((void*)h_headTiles, 16);
				hrt_LoadOBJGFX((void*)h_flightTiles, 96);
				hrt_LoadOBJGFX((void*)h_xTiles, 16);
				hrt_LoadOBJGFX((void*)h_stageTiles, 128);
				hrt_LoadOBJGFX((void*)h_numsTiles, 16);
				game.genericptr = (u16*)&h_numsTiles + 48;
				hrt_LoadOBJGFX((void*)game.genericptr, 16);
				hrt_offsetOAMData += 32;
				game.genericptr = (u16*)&h_numsTiles + 16;
				hrt_LoadOBJGFX((void*)game.genericptr, 16);
				game.genericptr = (u16*)&h_numsTiles + 16;
				hrt_LoadOBJGFX((void*)game.genericptr, 16);
				hrt_LoadOBJGFX((void*)f_fullTiles, 112);
				hrt_LoadOBJGFX((void*)h_fullTiles, 64);
				hrt_LoadOBJGFX((void*)h_halfTiles, 64);
				hrt_LoadOBJGFX((void*)h_emptyTiles, 64);
				hrt_CreateOBJ(0, 120, 80, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				hrt_CreateOBJ(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 34);
				hrt_CreateOBJ(2, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 38);
				hrt_CreateOBJ(3, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 42);
				hrt_CreateOBJ(4, 40, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5);
				hrt_CreateOBJ(5, 48, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 12);
				hrt_CreateOBJ(6, 56, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 21);
				hrt_CreateOBJ(7, 80, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 13);
				hrt_CreateOBJ(8, 112, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 17);
				hrt_CreateOBJ(9, 128, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 25);
				hrt_CreateOBJ(10, 144, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 26);
				hrt_CreateOBJ(11, 208, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 27);
				hrt_CreateOBJ(12, 160, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 6);
				hrt_CreateOBJ(13, 192, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 10);
				for (game.i = 14; game.i < 128; game.i++)
				{
					hrt_CreateOBJ(game.i, 240, 160, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
				}
				mmStart(MOD_WORLD1, MM_PLAY_LOOP);
				gGameMap.numLayers = 1;
				gGameMap.layer->map = (void*)level1MetaMap;
				gGameMap.dimensions.x = 150;
				gGameMap.dimensions.y = 20;
				gGameMap.layer[1].scroll.y = 0;
				gGameMap.layer[1].scroll.x = 0;
				gGameMap.tileset = (void*)level1MetaTiles;
				u32 j, i;
				for (i = 0; i < gGameMap.numLayers; i++)
					for (j = 0; j < 32; j++)
						MapLayerDrawStripH(i, fptochar(gGameMap.layer[i].scroll.y) + j);
				bird.ypos = 120;
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(16 - game.i);
					hrt_SleepF(1);
				}
				bird.animstate = 1;
				while (1)
				{
					physics();
					game.frames++;
					hrt_VblankIntrWait();
					hrt_EditBG(0, demolevel.xscroll, demolevel.yscroll, 0, 0, 0, 0, 0);
					if (keyDown(KEY_L))
					{
						if ((!(bird.flight == 0)AND(bird.flightlock == 0)))
						{
							bird.flight--;
							animflight();
						}
					}
					else {
						if (!(bird.flight == 26))
						{
							if (bird.flightlock == 0)
							{
								bird.flight++;
								animflight();
							}
						}
					}
					if (bird.flight == 0)
					{
						bird.flightlock = 1;
					}
					if (bird.flightlock == 1)
					{
						if (!(bird.flight == 26))
						{
							bird.flight++;
							animflight();
						}
						else {
							bird.flightlock = 0;
						}
					}
				}
			}
		}
	}
}

void vblFunc(void)
{
	unsigned char *p = (unsigned char*)&game.rngvalue;
	game.rngvalue = hrt_CreateRNG();
	SaveFiles.RNGSeed = game.rngvalue;
	hrt_SaveByte(0x00, p[0]);
	hrt_SaveByte(0x01, p[1]);
	REG_IME = 1;
}