#include <libheart.h>
#include <string.h>
#include "main.h"
#include "chirpy.h"
#include "menu.h"
#include "sound.h"
#include "graphics.h"
u8 g_MenuPos = 0;

void g_InitMainMenu()
{
	mmStart(MOD_WORLD3, MM_PLAY_LOOP); //Start playing the menu theme
	//hrt_DMA_Copy(3, m_bg_Tiles, (u32*)0x600C000, 448, 0x80000000);
    //hrt_DMA_Copy(3, m_bg_Map, (u32*)0x6002000, 1024, 0x80000000);
    //hrt_DMA_Copy(3, m_titleTiles, (u32*)0x6008000, 800, 0x80000000);
    //hrt_DMA_Copy(3, m_titleMap, (u32*)0x6002800, 1024, 0x80000000);
	//hrt_LoadBGPal((void*)m_bgPalette, 16);
	//memcpy(m_bg_Tiles, VRAM[0xC000], 448);
	
	//hrt_LoadDataIntoVRAM(data, length, offset);
    hrt_InitTiledText(0);
    hrt_BGSetMapBase(2, 4);
    hrt_BGSetTileBase(2, 3);
    hrt_BGSetMapBase(1, 5);
    hrt_BGSetTileBase(1, 2);
    hrt_SetOffset(OFF_BGMAP, 0x3000);
	while(1)
	{
		hrt_VblankIntrWait();
	}
}