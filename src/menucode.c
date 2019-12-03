#include <libheart.h>
#include <string.h>
#include "main.h"  
#include "chirpy.h"  
#include "menu.h" 
#include "sound.h"  
#include "graphics.h"
#include "game.h"
u8 g_MenuPos = 0;  
u8 g_MenuArrowPos = 0;
u8 g_MenuKeyLockUp = 0;
u8 g_MenuKeyLockDown = 0;
u8 g_MenuKeyLockLeft = 0;
u8 g_MenuKeyLockRight = 0;
u8 g_MenuKeyLockA = 0;

//void (*jMainMenuHomeTable[])(void) = {g_MainMenuNewGame,g_MainMenuContinueGame,g_MainMenuOptions};
//void (*jMainMenuOptionsTable[])(void) = {g_MainMenuOptionsMusicVolume,g_MainMenuOptionsSoundVolume,g_MainMenuOptionsSoundTest,g_MainMenuOptionsCredits,g_MainMenuOptionsControls};

void g_InitMainMenu()  
{ 
	mmStart(MOD_THEME, MM_PLAY_LOOP); //Start playing the menu theme
	mmSetModuleVolume(2048);
	hrt_InitTiledText(0);
	hrt_SetBGY(1,105);
	//Load the Graphics and Map
	hrt_DMACopy(3, (u16*)m_bg_Tiles, (u32*)0x600C000, 448, 0x80000000);
    hrt_DMACopy(3, (u16*)m_bg_Map, (u32*)0x6002000, 1024, 0x80000000);
	hrt_DMACopy(3, (u16*)m_titleTiles, (u32*)0x6008000, 800, 0x80000000);
    hrt_DMACopy(3, (u16*)m_titleMap, (u32*)0x6002800, 1024, 0x80000000);
	hrt_LoadBGPal((void*)m_bgPalette, 16, 16);	
	hrt_BGSetMapBase(2, 4);
    hrt_BGSetTileBase(2, 3);
    hrt_BGSetMapBase(1, 5);
    hrt_BGSetTileBase(1, 2);
    for (g_Index = 0; g_Index < 16; g_Index++) {
        hrt_SetFXLevel(15-g_Index);
        hrt_VblankIntrWait();
    }
	g_MainMenuMoveTitleCard();
	while(1)
	{
		hrt_VblankIntrWait();
		if(hrt_IsKeyPressed(A))
		{
			gInitMainGame();
		}
	}
}

void g_MainMenuMoveTitleCard()
{
	long double g_Index2 = 8;
	register u16 pos=100;
	hrt_DSPEnableBG(1);
	while(g_Index2>0)
	{
		hrt_VblankIntrWait();
		if(!(g_Frames % 13))
		{
			g_Index2*=0.59;
		}
		pos+=g_Index2;
		hrt_SetBGY(1, pos);
	}
}