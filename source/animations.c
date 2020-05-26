#include <libheart.h>
#include "game.h"
#include "interrupt.h"
#include "lang.h"
#include "menus.h"
#include "animations.h"
#include "data.h"

u8 animPlayerState;
u8 animPlayerFrame;

void animPlayer()
{
	hrt_LoadDataIntoPalette((u16*)chirpy_pal_bin, 256, 16);
	switch (animPlayerState)
	{
	case 0:
		hrt_LoadDataIntoVRAM((u16*)chirpy_gfx_bin, OBJ_TILE_BASE(0), 64);
	case 1:
		animPlayerFrame++;
	}
}