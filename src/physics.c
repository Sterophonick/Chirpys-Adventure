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

mm_sound_effect b_jump;
mm_sound_effect b_hurt;

void physics(void)
{
	hrt_VblankIntrWait(); 
	animbird();
	if (bird.oldx / 8 != bird.xpos / 8)
	{
		bird.tilex = bird.xpos / 8;
	}
	if (bird.oldy / 8 != bird.ypos / 8)
	{
		bird.tiley = bird.ypos / 8;
	}

	if (keyDown(KEY_LEFT))
	{
		hrt_CreateOBJ(0, bird.screenx, bird.screeny, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		bird.xvel-=2;
	}
	if (keyDown(KEY_RIGHT))
	{
		hrt_CreateOBJ(0, bird.screenx, bird.screeny, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0);
		bird.xvel+=2;
	}
	if (bird.xvel < 0)
	{
		bird.xvel++;
		bird.animstate = 1;
		animbird();
	}
	if (bird.xvel > 0)
	{
		bird.xvel--;
		bird.animstate = 1;
		animbird();
	}
	if (bird.xvel == 0)
	{
		bird.animstate = 0;
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
	bird.screenx += bird.xvel / 4;
	bird.xpos += bird.xvel / 4;
	if(game.debug == 1)
	{
		hrt_PrintOnTilemap(0, 5, "%s %d    ", (char*)gl_debug_px, bird.xpos);
		hrt_PrintOnTilemap(0, 6, "%s2 %d    ", (char*)gl_debug_px, bird.screenx);
		hrt_PrintOnTilemap(0, 7, "%s2 %d    ", (char*)gl_debug_sx, demolevel.xscroll);
		hrt_PrintOnTilemap(0, 8, "%d       ", level2MetaMap[7*150+103]);
	}
      if (keyDown(KEY_UP)) 
      { 
         if (!(demolevel.yscroll == 0)) 
         { 
            demolevel.loadylock = 0; 
            demolevel.yscroll--; 
            demolevel.newY = demolevel.yscroll; 
            if ((demolevel.oldY / 8 != demolevel.newY / 8)AND(demolevel.loadylock == 0)) 
            { 
			demolevel.oldY = demolevel.newY;
              hrt_SetLargeScrollMapY(hrt_GetLargeMapY(game.i)-1, game.i);
               for (game.i = 0; game.i < hrt_GetNumLayers(); game.i++) 
               { 
		   hrt_SetLargeScrollMapY(inttofp(demolevel.yscroll), game.i);
                  hrt_DrawMapLayerStripH(game.i, fptochar(hrt_GetLargeMapY(game.i))); 
               } 
               demolevel.loadylock++; 
            } 
         } 
      } 
      if (keyDown(KEY_DOWN)) 
      { 
         if (!(demolevel.yscroll == 160)) 
         { 
            demolevel.loadylock = 0; 
            demolevel.yscroll++; 
            demolevel.newY = demolevel.yscroll; 
            if ((demolevel.oldY / 8 != demolevel.newY / 8)AND(demolevel.loadylock == 0)) 
            { 
			demolevel.oldY = demolevel.newY;
               hrt_SetLargeScrollMapY(hrt_GetLargeMapY(game.i)+1, game.i);
               for (game.i = 0; game.i < hrt_GetNumLayers(); game.i++) 
               { 
					hrt_SetLargeScrollMapY(inttofp(demolevel.yscroll), game.i);
                  hrt_DrawMapLayerStripH(game.i, fptochar(hrt_GetLargeMapY(game.i)) + 31); 
               } 
               demolevel.loadylock++; 
            } 
         } 
      } 
      if (bird.screenx < 100) 
      { 
	  	if (bird.screenx <= 0)
		{
			if (keyDown(KEY_LEFT))
			{
				bird.screenx = 0;
				bird.xvel = 0;
				bird.xpos = 0;
				demolevel.xscroll = 0;
			}
		}
         if (!(demolevel.xscroll <= 0)) 
         { 
            demolevel.loadxlock = 0; 
            demolevel.xscroll = 100 - bird.screenx; 
			bird.screenx = 100;
			if (demolevel.xscroll < 0)
			{
				demolevel.xscroll = 0;
			}
			demolevel.newX = demolevel.xscroll;
            if ((demolevel.oldX / 8 != demolevel.newX / 8)AND(demolevel.loadxlock == 0)) 
            { 
				demolevel.oldX = demolevel.newX;
               for (game.i = 0; game.i < hrt_GetNumLayers(); game.i++) 
               { 
				 hrt_SetLargeScrollMapX(inttofp(demolevel.xscroll), game.i);
                 hrt_DrawMapLayerStripV(game.i, fptochar(hrt_GetLargeMapX(game.i))); 
               } 
               demolevel.loadxlock++; 
            } 
         } 
      }
      if (bird.screenx > 120) 
      { 
	  	if (bird.screenx >= 224)
		{
			if (keyDown(KEY_RIGHT))
			{
				bird.screenx = 224;
				bird.xpos = 2384;
				bird.xvel = 0;
				demolevel.xscroll = 2160;
			}
		}
         if (!(demolevel.xscroll >= 2160)) 
         { 
            demolevel.loadxlock = 0; 
            demolevel.xscroll+= bird.screenx-120; 
			bird.screenx = 120;
            demolevel.newX = demolevel.xscroll; 
            if ((demolevel.oldX / 8 != demolevel.newX / 8)AND(demolevel.loadxlock == 0)) 
            { 
				demolevel.oldX = demolevel.newX;
               for (game.i = 0; game.i < hrt_GetNumLayers(); game.i++) 
               { 
				 hrt_SetLargeScrollMapX(inttofp(demolevel.xscroll), game.i);
                 hrt_DrawMapLayerStripV(game.i, fptochar(hrt_GetLargeMapX(game.i))+31); 
               } 
               demolevel.loadxlock++; 
            } 
         } 
      }
	hrt_EditBG(2, demolevel.xscroll, demolevel.yscroll, 0, 0, 0, 0, 0);
	//detectcollisionright();
	hrt_SetOBJXY(0, bird.screenx, 32);
}