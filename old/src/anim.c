#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
extern player bird;
extern snd audio;
#define BIRD_OAM 0
#define HEART1_OAM 352
#define HEART2_OAM 416
#define HEART3_OAM 480

mm_sound_effect b_step;

void animbirdmap()
{
    bird.animtimer++;
    if (!(bird.animtimer % 10)) {
        bird.animframe++;
        if (bird.animframe == 4) {
            bird.animframe = 0;
        }
        if (bird.animframe == 0) {
            hrt_DMA_Copy(3, b_run1Tiles, 0x06014000, 64, 0x80000000);
        }
        else if (bird.animframe == 1) {
            hrt_DMA_Copy(3, b_run2Tiles, 0x06014000, 64, 0x80000000);
        }
        else if (bird.animframe == 2) {
            hrt_DMA_Copy(3, b_run3Tiles, 0x06014000, 64, 0x80000000);
        }
        else if (bird.animframe == 3) {
            hrt_DMA_Copy(3, b_idleTiles,  0x06014000, 64, 0x80000000);
        }
    }
}

void animflight()
{
    switch (bird.flight) {
        case 0:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_0Tiles, 112);
        case 1:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_1Tiles, 112);
        case 2:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_2Tiles, 112);
        case 3:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_3Tiles, 112);
        case 4:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_4Tiles, 112);
        case 5:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_5Tiles, 112);
        case 6:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_6Tiles, 112);
        case 7:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_7Tiles, 112);
        case 8:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_8Tiles, 112);
        case 9:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_9Tiles, 112);
        case 10:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_10Tiles, 112);
        case 11:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_11Tiles, 112);
        case 12:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_12Tiles, 112);
        case 13:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_13Tiles, 112);
        case 14:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_14Tiles, 112);
        case 15:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_15Tiles, 112);
        case 16:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_16Tiles, 112);
        case 17:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_17Tiles, 112);
        case 18:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_18Tiles, 112);
        case 19:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_19Tiles, 112);
        case 20:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_20Tiles, 112);
        case 21:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_21Tiles, 112);
        case 22:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_22Tiles, 112);
        case 23:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_23Tiles, 112);
        case 24:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_24Tiles, 112);
        case 25:
            hrt_SetOffset(OFF_OAMDATA, 432);
            hrt_LoadOBJGFX((void*)f_25Tiles, 112);
        case 26:
            hrt_SetOffset(OFF_OAMDATA, 432);
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
    mm_sound_effect step = {
        { SFX_B_STEP },			// id
        (int)(1.0f * (1 << 10)),	// rate
        0,		// handle
        255,	// volume
        128,	// panning
    };
    hrt_SetOffset(OFF_OAMDATA, 0);
    if (bird.animstate == 0) {
        hrt_DMA_Copy(3, b_idleTiles,  0x06014000, 64, 0x80000000);
    }
    else if (bird.animstate == 1) {
        bird.animtimer++;
        if (!(bird.animtimer % 10)) {
            bird.animframe++;
            if (bird.animframe == 4) {
                bird.animframe = 0;
            }
            if (bird.animframe == 0) {
                hrt_DMA_Copy(3, b_run1Tiles,  0x06014000, 64, 0x80000000);
            }
            else if (bird.animframe == 1) {
                audio.ChirpyStep = mmEffectEx(&b_step);
                hrt_DMA_Copy(3, b_run2Tiles,  0x06014000, 64, 0x80000000);
            }
            else if (bird.animframe == 2) {
                hrt_DMA_Copy(3, b_run3Tiles,  0x06014000, 64, 0x80000000);
            }
            else if (bird.animframe == 3) {
                audio.ChirpyStep = mmEffectEx(&b_step);
                hrt_DMA_Copy(3, b_idleTiles,  0x06014000, 64, 0x80000000);
            }
        }
    }
    else if (bird.animstate == 2) {
        if (bird.yvel > 0) {
            hrt_DMA_Copy(3, b_run1Tiles, 0x06014000, 64, 0x80000000);
        }
        else {
            hrt_DMA_Copy(3, b_fallTiles,  0x06014000, 64, 0x80000000);
        }
    }
}

void glideSprite(int spr, int x1, int y1, int x2, int y2, int frames)
{
    hrt_SetOBJXY(spr, x1, y1);
    int i, deltax, deltay, numpixels;
    int d, dinc1, dinc2;
    int x, xinc1, xinc2;
    int y, yinc1, yinc2;
    //calculate deltaX and deltaY
    deltax = abs(x2 - x1);
    deltay = abs(y2 - y1);
    //initialize
    if (deltax >= deltay) {
        //If x is independent variable
        numpixels = deltax + 1;
        d = (2 * deltay) - deltax;
        dinc1 = deltay << 1;
        dinc2 = (deltay - deltax) << 1;
        xinc1 = 1;
        xinc2 = 1;
        yinc1 = 0;
        yinc2 = 1;
    }
    else {
        //if y is independent variable
        numpixels = deltay + 1;
        d = (2 * deltax) - deltay;
        dinc1 = deltax << 1;
        dinc2 = (deltax - deltay) << 1;
        xinc1 = 0;
        xinc2 = 1;
        yinc1 = 1;
        yinc2 = 1;
    }
    //move the right direction
    if (x1 > x2) {
        xinc1 = -xinc1;
        xinc2 = -xinc2;
    }
    if (y1 > y2) {
        yinc1 = -yinc1;
        yinc2 = -yinc2;
    }
    x = x1;
    y = y1;
    //draw the pixels
    for (i = 1; i < numpixels; i++) {
        hrt_VblankIntrWait();
        hrt_SetOBJXY(spr, x, y);
        if (d < 0) {
            d = d + dinc1;
            x = x + xinc1;
            y = y + yinc1;
        }
        else {
            d = d + dinc2;
            x = x + xinc2;
            y = y + yinc2;
        }
    }
}