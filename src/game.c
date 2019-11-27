#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"
#include "game.h"
u8 g_NewFrame = 0;
u32 g_Frames = 0;
u32 g_Index = 0;
PAD keypad;

void gInitMainGame()
{
	
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