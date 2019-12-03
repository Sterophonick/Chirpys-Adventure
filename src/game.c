#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"
#include "game.h"
#include "graphics.h"
u8 g_NewFrame = 0;
u32 g_Frames = 0;
u32 g_Index = 0;
PAD keypad;

void gInitMainGame()
{
	hrt_ConfigMapLayerDrawing(1, (void*)level1MetaTiles, 150, 20, (void*)level1MetaMap, 1, 1);
	hrt_DrawFullLargeScrollMap();
	hrt_DMACopy(3, level1Tiles, (u32*)0x600C000, 448, 0x80000000);
	hrt_LoadBGPal((void*)level1Pal, 16, 0);
	//hrt_DSPDisableBG(2);
	hrt_BGSetMapBase(2, 28);
    hrt_BGSetTileBase(2, 1);
	hrt_SetBGPalEntry(49, 0x0421);
	hrt_SetBGPalEntry(50, 0x7FFF);
	hrt_SetPaletteOfTiledText(3);
	hrt_SetLargeScrollMapY(inttofp(30), 1);
	hrt_DrawFullLargeScrollMap();
}

void VBLFunc()
{
	g_NewFrame = 0;
	g_Frames++;
	mmFrame();
	hrt_GetPad(&keypad);
	if(hrt_IsKeyPressed(A) AND hrt_IsKeyPressed(B) AND hrt_IsKeyPressed(SELECT) AND hrt_IsKeyPressed(START))
	{
		hrt_SoftReset();
	}
}