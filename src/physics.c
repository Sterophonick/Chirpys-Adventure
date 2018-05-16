#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
map demolevel;
rom game;
snd audio;
player bird;
GameMap gGameMap;
gmenu menu;
col collision;
sram SaveFiles;

void physics(void)
{
	if (bird.oldx / 8 != bird.xpos / 8)
	{
		bird.tilex = bird.xpos / 8;
	}
	if (bird.oldy / 8 != bird.ypos / 8)
	{
		bird.tiley = bird.ypos / 8;
	}
	
	if (!((collision.bottoml == 1)OR(collision.bottomr == 1)))
	{
		
		if (bird.yvel > -8)
		{
			bird.yvel = -8;
		}
	}
	if (keyDown(KEY_A))
	{
		if ((collision.bottoml == 1)OR(collision.bottomr == 1))
		{
			bird.yvel = 20;
		}
	}
	if (keyDown(KEY_LEFT))
	{
		hrt_CreateOBJ(0, bird.screenx, bird.screeny, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (NOT((collision.leftu == 1)OR(collision.leftd == 1)))
		{
			bird.xvel-=2;
		}
	}
	if (keyDown(KEY_RIGHT))
	{
		hrt_CreateOBJ(0, bird.screenx, bird.screeny, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		if (NOT((collision.rightu == 1)OR(collision.rightd == 1)))
		{
			bird.xvel+=2;
		}
	}
	if (bird.xvel < 0)
	{
		bird.xvel++;
		animbird();
	}
	if (bird.xvel > 0)
	{
		bird.xvel--;
		animbird();
	}
	if (bird.xvel > 8)
	{
		bird.xvel = 8;
	}
	if (bird.xvel < -8)
	{
		bird.xvel = -8;
	}
	if ((collision.bottoml == 1)OR(collision.bottomr == 1))
	{
		bird.yvel = 0;
	}
	if ((collision.topl == 1)OR(collision.topr == 1))
	{
		bird.yvel = 0;
	}
	bird.screenx += bird.xvel / 4;
	bird.screeny += bird.yvel / 4;
	if (bird.screenx > 152)
	{
		if (bird.screenx > 220)
		{
			if (keyDown(KEY_RIGHT))
			{
				bird.screenx = 224;
				bird.xvel = 0;
			}
		}
		if (!(demolevel.xscroll == 2400 - 240))
		{
			demolevel.loadxlock = 0;
			demolevel.xscroll += bird.screenx-152;
			bird.screenx = 152;
			demolevel.newX = demolevel.xscroll;
			if ((demolevel.oldX / 8 != demolevel.newX / 8)AND(demolevel.loadxlock == 0))
			{
				demolevel.oldX = demolevel.newX;
				for (game.i = 0; game.i < gGameMap.numLayers; game.i++)
				{
					gGameMap.layer[game.i].scroll.x = inttofp(demolevel.xscroll);
					MapLayerDrawStripV(game.i, fptochar(gGameMap.layer[game.i].scroll.x) + 30);
				}
				demolevel.loadxlock++;
			}
		}
	}
	if (bird.screenx < 72)
	{
		if (bird.screenx < 4)
		{
			if (keyDown(KEY_LEFT))
			{
				bird.screenx = 0;
				bird.xvel = 0;
			}
		}
		if (!(demolevel.xscroll == 0))
		{
			demolevel.loadxlock = 0;
			demolevel.xscroll -= 72 - bird.screenx;
			bird.screenx = 72;
			if (demolevel.xscroll < 0)
			{
				demolevel.xscroll = 0;
			}
			demolevel.newX = demolevel.xscroll;
			if ((demolevel.oldX / 8 != demolevel.newX / 8)AND(demolevel.loadxlock == 0))
			{
				demolevel.oldX = demolevel.newX;
				for (game.i = 0; game.i < gGameMap.numLayers; game.i++)
				{
					gGameMap.layer[game.i].scroll.x = inttofp(demolevel.xscroll);
					MapLayerDrawStripV(game.i, fptochar(gGameMap.layer[game.i].scroll.x));
				}
				demolevel.loadxlock++;
			}
		}
	}
	if (bird.screeny > 128)
	{
		bird.screeny = 128;
		if (!(demolevel.yscroll == 160))
		{
			demolevel.loadylock = 0;
			demolevel.yscroll += 3;
			if (demolevel.yscroll > 160)
			{
				demolevel.yscroll = 160;
			}
			demolevel.newY = demolevel.yscroll;
			if ((demolevel.oldY / 8 != demolevel.newY / 8)AND(demolevel.loadylock == 0))
			{
				demolevel.oldY = demolevel.newY;
				for (game.i = 0; game.i < gGameMap.numLayers; game.i++)
				{
					gGameMap.layer[game.i].scroll.y = inttofp(demolevel.yscroll);
					MapLayerDrawStripH(game.i, fptochar(gGameMap.layer[game.i].scroll.y) + 31);
				}
				demolevel.loadylock++;
			}
		}
	}
	if (bird.screeny < 32)
	{
		bird.screeny = 32;
		if (!(demolevel.yscroll == 0))
		{
			demolevel.loadylock = 0;
			demolevel.yscroll -= 3;
			if (demolevel.yscroll < 0)
			{
				demolevel.yscroll = 0;
			}
			demolevel.newY = demolevel.yscroll;
			if ((demolevel.oldY / 8 != demolevel.newY / 8)AND(demolevel.loadylock == 0))
			{
				demolevel.oldY = demolevel.newY;
				for (game.i = 0; game.i < gGameMap.numLayers; game.i++)
				{
					gGameMap.layer[game.i].scroll.y = inttofp(demolevel.yscroll);
					MapLayerDrawStripH(game.i, fptochar(gGameMap.layer[game.i].scroll.y));
				}
				demolevel.loadylock++;
			}
		}
	}
	
}