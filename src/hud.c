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

void inithud()
{
	hrt_DMA_Copy(3, b_fireTiles,  0x06014080, 16, 0x80000000);
	hrt_DMA_Copy(3, h_headTiles,  0x060140a0, 16, 0x80000000);
	hrt_DMA_Copy(3, h_flightTiles,  0x060140C0, 96, 0x80000000);
	hrt_DMA_Copy(3, h_xTiles,  0x06014180, 16, 0x80000000);
	hrt_DMA_Copy(3, h_stageTiles,  0x060141a0, 128, 0x80000000);
	hrt_DMA_Copy(3, h_numsTiles,  0x060142a0, 16, 0x80000000);
					game.genericptr = (u16*)&h_numsTiles + 48;
				hrt_DMA_Copy(3, game.genericptr,  0x06014300, 16, 0x80000000);
									game.genericptr = (u16*)&h_numsTiles + 16;
				hrt_DMA_Copy(3, game.genericptr,  0x06014320, 16, 0x80000000);
				game.genericptr = (u16*)&h_numsTiles + 16;
				hrt_DMA_Copy(3, game.genericptr,  0x06014340, 16, 0x80000000);
					hrt_DMA_Copy(3, f_fullTiles,  0x06014360, 112, 0x80000000);
	hrt_DMA_Copy(3, h_fullTiles,  0x060143e0, 64, 0x80000000);
hrt_DMA_Copy(3, h_halfTiles,  0x06014460, 64, 0x80000000);
hrt_DMA_Copy(3, h_emptyTiles,  0x060144e0, 64, 0x80000000);
				hrt_CreateOBJ(1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 31);
				hrt_CreateOBJ(2, 10, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 35);
				hrt_CreateOBJ(3, 20, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 39);
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

}