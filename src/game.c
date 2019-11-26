#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sound.h"
#include "game.h"
u8 g_NewFrame = 0;
u32 g_Frames = 0;

void gInitMainGame()
{
	
}

void VBLFunc()
{
	g_NewFrame = 0;
	g_Frames++;
	mmFrame();
}