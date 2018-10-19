#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
map demolevel;
rom game;
snd audio;
player bird;
extern GameMap gGameMap;
gmenu menu;
col collision;
sram SaveFiles;

mm_sound_effect b_die;

void die()
{
	hrt_CreateOBJ(0, bird.screenx, bird.screeny, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
	audio.ChirpyDie = mmEffectEx(&b_die);
	hrt_DMA_Copy(3, b_dieTiles, 0x06014000, 64, 0x80000000);
	bird.screeny = 32;
	u8 by = bird.screeny;
	f32 yvel;
	yvel = -3;
	for(by = bird.screeny; by < 160;)
	{
		hrt_VblankIntrWait();
		yvel+=0.25;
		by+=yvel;
		hrt_SetOBJY(0, by);
	}
}