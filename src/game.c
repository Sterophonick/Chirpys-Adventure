#include <libheart.h>
#include "../inc/defs.h"
#include "../inc/soundbank.h"
extern rom game;
extern player bird;
extern snd audio;
extern sram SaveFiles;

void InitializeMainGame()
{
		hrt_ConfigMapLayerDrawing(1, (void*)level1MetaTiles, 150, 20, (void*)level1MetaMap, 1, 1);
		hrt_DrawFullLargeScrollMap();
		hrt_SetOffset(OFF_BGPAL, 0);
		bird.xpos = 0;
		bird.ypos = 0;
		//hrt_DMA_Copy(3, level1Tiles, (u32*)0x600C000, 448, 0x80000000);
		hrt_LoadBGTiles((void*)level1Tiles, 832);
		hrt_SetOffset(OFF_BGTILE, 0);
		hrt_LoadBGPal((void*)level1Pal, 16);
		hrt_BGSetMapBase(2, 28);
		hrt_BGSetTileBase(2, 1);
		BGPaletteMem[49] = 0x0421;
		BGPaletteMem[50] = 0x7FFF;
		hrt_SetPaletteOfTiledText(3);
		mmStart(MOD_WORLD1, MM_PLAY_LOOP);
		inithud();
		while(1)
		{
			physics();
				  if(keyDown(KEY_R))
	  {
		die();
	}
		}
}