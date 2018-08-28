#include <libheart.h>
#include "..\inc\defs.h"
#include "..\inc\soundbank.h"
extern map demolevel;
extern rom game;
extern gmenu menu;
extern snd audio;
extern player bird;
extern GameMap gGameMap;
extern col collision;
extern sram SaveFiles;
extern gba_system __hrt_system;

mm_sound_effect s_pageflip;

void Story()
{
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = game.i;
        hrt_VblankIntrWait();
    }
	SaveGames();
	mmStart(MOD_STORY, MM_PLAY_LOOP);
    hrt_DSPDisableBG(0);
    hrt_DSPDisableBG(3);
    hrt_DSPSetBGMode(3);
    hrt_DSPDisableOBJ();
    hrt_DSPDisableBG(1);
    hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
    hrt_FXEnableBGTarget1(2);
    hrt_LZ77UnCompVRAM((void*)story1Bitmap, VRAM);
    hrt_PrintOnBitmap(0, 0, (char*)gl_story_1_1);
    hrt_PrintOnBitmap(0, 8, (char*)gl_story_1_2);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
    while(!(keyDown(KEY_A))) {
        hrt_VblankIntrWait();
    }
    audio.PageFlip = mmEffectEx(&s_pageflip);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = game.i;
        hrt_VblankIntrWait();
    }
    hrt_LZ77UnCompVRAM((void*)story2Bitmap, VRAM);
    hrt_PrintOnBitmap(0, 0, (char*)gl_story_2_1);
    hrt_PrintOnBitmap(0, 8, (char*)gl_story_2_2);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
    while(!(keyDown(KEY_A))) {
        hrt_VblankIntrWait();
    }
    audio.PageFlip = mmEffectEx(&s_pageflip);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = game.i;
        hrt_VblankIntrWait();
    }
    hrt_LZ77UnCompVRAM((void*)story3Bitmap, VRAM);
    hrt_PrintOnBitmap(0, 0, (char*)gl_story_3_1);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
    while(!(keyDown(KEY_A))) {
        hrt_VblankIntrWait();
    }
    audio.PageFlip = mmEffectEx(&s_pageflip);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = game.i;
        hrt_VblankIntrWait();
    }
    hrt_LZ77UnCompVRAM((void*)story4Bitmap, VRAM);
    hrt_PrintOnBitmap(0, 0, (char*)gl_story_4_1);
    hrt_PrintOnBitmap(0, 8, (char*)gl_story_4_2);
    hrt_PrintOnBitmap(0, 16, (char*)gl_story_4_3);
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
    while(!(keyDown(KEY_A))) {
        hrt_VblankIntrWait();
    }
    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = game.i;
        hrt_VblankIntrWait();
    }
	worldmap();
}