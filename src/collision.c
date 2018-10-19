#include <libheart.h>
#include "../inc/defs.h"
extern col collision;
extern map demolevel;
extern player bird;
extern rom game;

u8 spiketiles[64] = {
	//level1
	9,13,14,18,
	
	//level2
	14,9,11,13,
};

void detectcollisionright() {
		if (level1MetaMap[bird.tiley*150+bird.tilex]==0x0001)
		{
            demolevel.loadxlock = 0; 
            demolevel.xscroll-=2; 
			bird.xpos-=bird.xvel;
			bird.tilex--;
			bird.xvel = 0;
            demolevel.newX = demolevel.xscroll; 
		}	else {
			asm("nop");
		}
		if (level1MetaMap[bird.tilex+1]==0x0001)
		{
            demolevel.loadxlock = 0; 
            demolevel.xscroll-=2; 
			bird.xpos-=2;
			bird.tilex--;
            demolevel.newX = demolevel.xscroll; 
		}	else {
			asm("nop");
		}
}