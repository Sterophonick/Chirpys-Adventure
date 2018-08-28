#include <libheart.h>
#include "../inc/defs.h"
#include "../inc/soundbank.h"
extern rom game;
extern sram SaveFiles;
extern snd audio;
extern gmenu menu;

u8 mappos = 0;

const u8 xchange1[]=
{
	64,
	112,
	176,
	176,
};
	
const u8 ychange1[]=
{
	96,
	96,
	96,
	64,
};

mm_sound_effect map_select;
mm_sound_effect map_confirm;

void animcursormap()
{
    if (!(game.frames % 3)) {
        menu.arframe++;
        if (menu.arframe == 7) {
            menu.arframe = 0;
        }
        if (menu.arframe == 0) {
            hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 1) {
            hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 2) {
            hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 3) {
            hrt_DMA_Copy(3, (u16*)m_arrow4Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 4) {
            hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 5) {
            hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
        if (menu.arframe == 6) {
            hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014080, 16, 0x80000000);
        }
    }
}

void mappause()
{
		hrt_PrintOnTilemap(12, 8, gl_pause_r);
		hrt_PrintOnTilemap(13, 9, gl_pause_q);
		menu.selectionlimit = 1;
		menu.arpos = 0;
		hrt_SetOBJXY(0, 240, 160);
	while(1)
	{
		hrt_VblankIntrWait();
		MenuCursor();
		animcursormap();
		hrt_SetOBJXY(2, 88, (menu.arpos * 8) + 64);
		if(keyDown(KEY_A))
		{
			if(menu.arpos == 0)
			{
				audio.GamePause = mmEffectEx(&g_pause);
				break;
			}else{
				hrt_SoftReset();
			}
		}
	}
	hrt_SetOBJXY(2, 240, 160);
	hrt_DSPDisableBG(1);
	hrt_ClearTiledText();
	hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
}

void presses1()
{
	if(mappos > 3)
	{
		mappos = 3;
	}
	if(keyDown(KEY_RIGHT))
	{
		while(keyDown(KEY_RIGHT))
		{
				animbirdmap();
			hrt_VblankIntrWait();
		}
		if(mappos == 0)
		{
			audio.MapSelect = mmEffectEx(&map_select);
			mappos++;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
		else if(mappos == 1)
		{
		audio.MapSelect = mmEffectEx(&map_select);
					mappos++;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
		else if(mappos == 3)
		{
			if(SaveFiles.Files[game.currentfile].CompletedStages > 3)
			{
				for (game.i = 0; game.i < 17; game.i++) {
					hrt_SetFXLevel(game.i);
					hrt_SleepF(1);
				}
			}
		}
		else{
		}
	}
	if(keyDown(KEY_UP))
	{
			while(keyDown(KEY_UP))
		{
				animbirdmap();
			hrt_VblankIntrWait();
		}
		if(mappos == 2)
		{
		audio.MapSelect = mmEffectEx(&map_select);
			mappos++;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
	}
	if(keyDown(KEY_LEFT))
	{
			while(keyDown(KEY_LEFT))
		{
				animbirdmap();
			hrt_VblankIntrWait();
		}
		if(mappos == 0)
		{
		audio.MapSelect = mmEffectEx(&map_select);
					mappos=0;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
		else if(mappos == 1)
		{
		audio.MapSelect = mmEffectEx(&map_select);
					mappos--;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
		else if(mappos == 2)
		{
		audio.MapSelect = mmEffectEx(&map_select);
			mappos--;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
		else{
		}
	}
	if(keyDown(KEY_DOWN))
	{
			while(keyDown(KEY_DOWN))
		{
				animbirdmap();
			hrt_VblankIntrWait();
		}
		if(mappos == 3)
		{
		audio.MapSelect = mmEffectEx(&map_select);
			mappos--;
			hrt_SetOBJXY(0, xchange1[mappos], ychange1[mappos]);
		}
	}
}

void worldmap()
{
    hrt_RegisterRamReset(hrt_ConfigRegisterRamReset(0, 0, 0, 1, 0, 0, 0, 0));
	mmStart(MOD_MAP, MM_PLAY_LOOP);
    hrt_DSPSetBGMode(0);
    hrt_DSPEnableBG(0);
    hrt_DSPEnableBG(1);
    hrt_DSPEnableBG(2);
    hrt_DSPEnableBG(3);
    hrt_DSPEnableOBJ();
	hrt_DSPEnableLinearOBJ();
    hrt_DSPDisableForceBlank();
    hrt_InitTiledText(0);
    hrt_BGSetMapBase(2, 4);
    hrt_BGSetTileBase(2, 3);
    hrt_BGSetMapBase(1, 5);
    hrt_BGSetTileBase(1, 2);
	if(SaveFiles.Files[game.currentfile].StageOnMap < 4)
	{
		hrt_SetOffset(OFF_BGPAL, 16);
		hrt_DMA_Copy(3, worldmap1Tiles, (u32*)0x600C000, 448, 0x80000000);
		hrt_DMA_Copy(3, worldmap1Map, (u32*)0x6002000, 640,  0x80000000);
		hrt_LoadBGPal((void*)worldmap1Pal, 16);
	}
	if((SaveFiles.Files[game.currentfile].StageOnMap > 3)AND(SaveFiles.Files{game.currentfile].StageOnMap < 8))
	{
		hrt_SetOffset(OFF_BGPAL, 16);
		hrt_DMA_Copy(3, worldmap2Tiles, (u32*)0x600C000, 448, 0x80000000);
		hrt_DMA_Copy(3, worldmap2Map, (u32*)0x6002000, 640,  0x80000000);
		hrt_LoadBGPal((void*)worldmap2Pal, 16);
	}
	hrt_SetOffset(OFF_BGPAL, 32);
	hrt_DMA_Copy(3, pauseTiles, (u32*)0x6008000, 160, 0x80000000);
    hrt_DMA_Copy(3, pauseMap, (u32*)0x6002800, 640,  0x80000000);
	hrt_LoadBGPal((void*)pausePal, 16);
	for(game.i = 0; game.i < 1024; game.i++) {
        VRAM[0x2000+game.i] |= BIT12;
    }
	hrt_CreateOBJ(0, xchange1[0], ychange1[0], 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	hrt_CreateOBJ(2, 88, 64, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 4);
	hrt_SetOffset(OFF_OAMPAL, 0);
	hrt_SetOffset(OFF_OAMDATA, 0);	
	hrt_SetOBJXY(1, 240, 160);
	hrt_LoadOBJGFX((void*)b_idleTiles, 64);
	hrt_LoadOBJPal((void*)b_idlePal, 16);
	hrt_DSPDisableBG(1);
	game.world = 1;
	//hrt_ClearTiledText();
	for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
	while(1)
	{
		hrt_VblankIntrWait();
		animbirdmap();
		presses1();
		if(keyDown(KEY_START))
		{
			hrt_DSPEnableBG(1);
			audio.GamePause = mmEffectEx(&g_pause);
			mappause();
		}
	}
}