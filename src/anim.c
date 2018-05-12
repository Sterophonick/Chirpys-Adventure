#include <libheart.h>
#include "..\inc\defs.h"
extern player bird;
#define BIRD_OAM 0
#define HEART1_OAM 352
#define HEART2_OAM 416
#define HEART3_OAM 480

void animflight()
{
	switch (bird.flight)
	{
		case 0:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_0Tiles, 112);
		case 1:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_1Tiles, 112);
		case 2:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_2Tiles, 112);
		case 3:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_3Tiles, 112);
		case 4:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_4Tiles, 112);
		case 5:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_5Tiles, 112);
		case 6:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_6Tiles, 112);
		case 7:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_7Tiles, 112);
		case 8:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_8Tiles, 112);
		case 9:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_9Tiles, 112);
		case 10:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_10Tiles, 112);
		case 11:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_11Tiles, 112);
		case 12:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_12Tiles, 112);
		case 13:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_13Tiles, 112);
		case 14:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_14Tiles, 112);
		case 15:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_15Tiles, 112);
		case 16:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_16Tiles, 112);
		case 17:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_17Tiles, 112);
		case 18:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_18Tiles, 112);
		case 19:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_19Tiles, 112);
		case 20:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_20Tiles, 112);
		case 21:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_21Tiles, 112);
		case 22:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_22Tiles, 112);
		case 23:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_23Tiles, 112);
		case 24:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_24Tiles, 112);
		case 25:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_25Tiles, 112);
		case 26:
			hrt_offsetOAMData = 432;
			hrt_LoadOBJGFX((void*)f_fullTiles, 112);
	}
}

void animlife()
{

}

void animheart()
{

}

void animbird()
{

}