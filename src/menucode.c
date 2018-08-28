#include <libheart.h>
#include "../inc/defs.h"
#include "../inc/soundbank.h"
extern map demolevel;
extern rom game;
extern gmenu menu;
extern snd audio;
extern player bird;
extern GameMap gGameMap;
extern col collision;
extern sram SaveFiles;
extern gba_system __hrt_system;

mm_sound_effect m_select;
mm_sound_effect m_confirm;
mm_sound_effect m_no;
mm_sound_effect m_sndvoltst;
mm_sound_effect g_pause;

const mm_byte sndvolumetable[11]= {
    0,
    0x0F,
    0x1F,
    0x3F,
    0x4F,
    0x5F,
    0x7F,
    0x8F,
    0xAF,
    0xCF,
    0xFF,
};

const mm_word musvolumetable[11]= {
    0,
    100,
    200,
    300,
    400,
    500,
    600,
    700,
    800,
    900,
    1024,
};
void musicvolume()
{
    if(SaveFiles.MusicVolume == 0) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_0);
    }
    if(SaveFiles.MusicVolume == 1) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_1);
    }
    if(SaveFiles.MusicVolume == 2) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_2);
    }
    if(SaveFiles.MusicVolume == 3) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_3);
    }
    if(SaveFiles.MusicVolume == 4) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_4);
    }
    if(SaveFiles.MusicVolume == 5) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_5);
    }
    if(SaveFiles.MusicVolume == 6) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_6);
    }
    if(SaveFiles.MusicVolume == 7) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_7);
    }
    if(SaveFiles.MusicVolume == 8) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_8);
    }
    if(SaveFiles.MusicVolume == 9) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_9);
    }
    if(SaveFiles.MusicVolume == 10) {
        hrt_PrintOnTilemap(1, 7, "%s %s", (char*)gl_menu_opt_music, (char*)gl_options_audio_A);
    }
    if(keyDown(KEY_LEFT)) {
        if(!(SaveFiles.MusicVolume == 0)) {
            SaveFiles.MusicVolume--;
        }
		SaveGames();
        while(keyDown(KEY_LEFT)) {
            hrt_VblankIntrWait();
            AnimMenuCursor();
        }
    }
    if(keyDown(KEY_RIGHT)) {
        if(!(SaveFiles.MusicVolume == 10)) {
            SaveFiles.MusicVolume++;
        }
		SaveGames();
        while(keyDown(KEY_RIGHT)) {
            hrt_VblankIntrWait();
			AnimMenuCursor();
        }
    }
    mmSetModuleVolume(musvolumetable[SaveFiles.MusicVolume]);
}

void soundvolume()
{
    if(SaveFiles.SoundVolume == 0) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_0);
    }
    if(SaveFiles.SoundVolume == 1) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_1);
    }
    if(SaveFiles.SoundVolume == 2) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_2);
    }
    if(SaveFiles.SoundVolume == 3) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_3);
    }
    if(SaveFiles.SoundVolume == 4) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_4);
    }
    if(SaveFiles.SoundVolume == 5) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_5);
    }
    if(SaveFiles.SoundVolume == 6) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_6);
    }
    if(SaveFiles.SoundVolume == 7) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_7);
    }
    if(SaveFiles.SoundVolume == 8) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_8);
    }
    if(SaveFiles.SoundVolume == 9) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_9);
    }
    if(SaveFiles.SoundVolume == 10) {
        hrt_PrintOnTilemap(1, 8, "%s %s", (char*)gl_menu_opt_sound, (char*)gl_options_audio_A);
    }
    if(keyDown(KEY_LEFT)) {
        if(!(SaveFiles.SoundVolume == 0)) {
            SaveFiles.SoundVolume--;
			hrt_VblankIntrWait();
            audio.MenuSFXVolumeChange = mmEffectEx(&m_sndvoltst);
			SaveGames();
        }
        while(keyDown(KEY_LEFT)) {
            hrt_VblankIntrWait();
            AnimMenuCursor();
        }
    }
    if(keyDown(KEY_RIGHT)) {
        if(!(SaveFiles.SoundVolume == 10)) {
            SaveFiles.SoundVolume++;
			hrt_VblankIntrWait();
            audio.MenuSFXVolumeChange = mmEffectEx(&m_sndvoltst);
			SaveGames();
        }
        while(keyDown(KEY_RIGHT)) {
            hrt_VblankIntrWait();
            AnimMenuCursor();
        }
    }
}

void MenuCursor()
{
    if ((keyDown(KEY_UP))AND(!(menu.arpos == 0))AND(menu.uplock == 0)) {
        menu.arpos--;
        menu.uplock = 1;
        audio.MenuSelect = mmEffectEx(&m_select);
    }
    if (!(keyDown(KEY_UP))) {
        menu.uplock = 0;
    }
    if ((keyDown(KEY_DOWN))AND(!(menu.arpos == menu.selectionlimit))AND(menu.downlock == 0)) {
        menu.arpos++;
        menu.downlock = 1;
        audio.MenuSelect = mmEffectEx(&m_select);
    }
    if (!(keyDown(KEY_DOWN))) {
        menu.downlock = 0;
    }
}

const u8 overwrite[] = {
    40,
    160,
};

const u8 percentages[17]= {
    0,
    6,
    13,
    19,
    25,
    31,
    38,
    44,
    50,
    56,
    63,
    69,
    75,
    81,
    88,
    94,
    100,
};

const u8 contheights[3] = {
    24,
    80,
    136,
};

void AnimMenuCursor()
{
    if (!(game.frames % 3)) {
        menu.arframe++;
        if (menu.arframe == 7) {
            menu.arframe = 0;
        }
        if (menu.arframe == 0) {
            hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 1) {
            hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 2) {
            hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 3) {
            hrt_DMA_Copy(3, (u16*)m_arrow4Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 4) {
            hrt_DMA_Copy(3, (u16*)m_arrow3Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 5) {
            hrt_DMA_Copy(3, (u16*)m_arrow2Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
        if (menu.arframe == 6) {
            hrt_DMA_Copy(3, (u16*)m_arrow1Tiles, (u16*)0x06014420, 16, 0x80000000);
        }
    }
}
void MainMenu()
{
    mmStart(MOD_THEME, MM_PLAY_LOOP);
    hrt_RegisterRamReset(hrt_ConfigRegisterRamReset(0, 0, 0, 1, 0, 0, 0, 0));
    hrt_DSPSetBGMode(0);
    hrt_DSPEnableBG(0);
    hrt_DSPEnableBG(1);
    hrt_DSPEnableBG(2);
    hrt_DSPEnableBG(3);
    hrt_DSPEnableOBJ();
    hrt_DSPDisableForceBlank();
    hrt_InitTiledText(0);
    hrt_BGSetMapBase(2, 4);
    hrt_BGSetTileBase(2, 3);
    hrt_BGSetMapBase(1, 5);
    hrt_BGSetTileBase(1, 2);
    hrt_SetOffset(OFF_BGMAP, 0x3000);
    REG_BG1VOFS = 96;
    //__hrt_system.hrt_offsetBGTile = 0x8000;
    hrt_SetOffset(OFF_BGPAL, 16);
    hrt_DMA_Copy(3, m_bg_Tiles, (u32*)0x600C000, 448, 0x80000000);
    hrt_DMA_Copy(3, m_bg_Map, (u32*)0x6002000, 1024, 0x80000000);
    hrt_DMA_Copy(3, m_titleTiles, (u32*)0x6008000, 800, 0x80000000);
    hrt_DMA_Copy(3, m_titleMap, (u32*)0x6002800, 1024, 0x80000000);
    hrt_LoadBGPal((void*)m_bgPalette, 16);
    for(game.i = 0; game.i < 1024; game.i++) {
        VRAM[0x2000+game.i] |= BIT12;
    }
	    for (game.i = 0; game.i < 16; game.i++) {
        REG_BLDY = 15-game.i;
        hrt_VblankIntrWait();
    }
    hrt_SleepF(60);
    for (game.i = 96; game.i < 257; game.i += 2) {
        hrt_VblankIntrWait();
        REG_BG1VOFS = game.i;
    }
    hrt_LoadOBJGFX((void*)m_yearTiles, 576);
    hrt_SetOBJPalEntry(2, 0x0421);
    hrt_SetOBJPalEntry(1, 0x7FFF);
    hrt_SleepF(30);
    hrt_CreateOBJ(0, 104, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0);
    hrt_CreateOBJ(1, 120, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 4);
    hrt_CreateOBJ(2, 136, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 8);
    hrt_CreateOBJ(3, 152, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 12);
    hrt_CreateOBJ(4, 168, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 16);
    hrt_CreateOBJ(5, 184, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 20);
    hrt_CreateOBJ(6, 200, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 24);
    hrt_CreateOBJ(7, 216, 255, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 28);
    hrt_CreateOBJ(8, 232, 255, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 32);
    for (game.i = 0; game.i < 9; game.i++) {
        for (game.i2 = 0; game.i2 < 9; game.i2++) {
            hrt_SetOBJXY(game.i2, (game.i2 * 16) + 104, 160 - game.i);
        }
        hrt_VblankIntrWait();
    }
    hrt_PrintOnTilemap(9, 14, (char*)gl_menu_press);
    u8 effecta = 0, effectb = 0;
    int effectinc = 0;
    hrt_SetFXMode(1, //BG 0 Target 1
                  0,                             //BG 1 Target 1
                  0,                             //BG 2 Target 1
                  0,                             //BG 3 Target 1
                  0,                             //OBJ Target 1
                  0,                             //Backdrop Target 1
                  1,                             //Blend Mode
                  0,                             //BG 0 Target 2
                  0,                             //BG 1 Target 2
                  1,                             //BG 2 Target 2
                  0,                             //BG 3 Target 2
                  0,                             //OBJ Target 2
                  1);                           //Backdrop Target 2
				 REG_BG0VOFS = 128;
    for (game.i = 128; game.i < 257; game.i += 2) {
        hrt_VblankIntrWait();
        REG_BG0VOFS = game.i;
        if (16 == effecta) {
            effectinc = -1;
        }
        if (0 == effecta) {
            effectinc = 1;
        }
        hrt_SetFXAlphaLevel(effecta,             // Source intensity
                            16 - effectb);
        effecta += effectinc;
        effectb += effectinc;
    }
    while (!(keyDown(KEY_START))) {
        hrt_VblankIntrWait();
        if (16 == effecta) {
            effectinc = -1;
        }
        if (0 == effecta) {
            effectinc = 1;
        }
        hrt_SetFXAlphaLevel(effecta,             // Source intensity
                            16 - effectb);
        effecta += effectinc;
        effectb += effectinc;
    }
    audio.MenuConfirm = mmEffectEx(&m_confirm);
    hrt_SetFXMode(0, //BG 0 Target 1
                  0,                             //BG 1 Target 1
                  0,                             //BG 2 Target 1
                  0,                             //BG 3 Target 1
                  0,                             //OBJ Target 1
                  0,                             //Backdrop Target 1
                  0,                             //Blend Mode
                  0,                             //BG 0 Target 2
                  0,                             //BG 1 Target 2
                  0,                             //BG 2 Target 2
                  0,                             //BG 3 Target 2
                  0,                             //OBJ Target 2
                  0);                           //Backdrop Target 2
    hrt_PrintOnTilemap(9, 14, "            ");
    REG_BG0VOFS = 96;
    hrt_SetFXAlphaLevel(0,             // Source intensity
                        16);
    effectinc = 0;
    effecta = 0;
    effectb = 0;
    hrt_PrintOnTilemap(1, 7, (char*)gl_menu_new);
    hrt_PrintOnTilemap(1, 8, (char*)gl_menu_cont);
    hrt_PrintOnTilemap(1, 9, (char*)gl_menu_opt);
    hrt_PrintOnTilemap(1, 10, (char*)gl_menu_exit);
    for (game.i = 128; game.i < 257; game.i += 2) {
        hrt_VblankIntrWait();
        REG_BG0VOFS = game.i;
    }
    hrt_SetOffset(OFF_OAMPAL, 16);
    hrt_LoadOBJPal((void*)m_arrow4Pal, 16);
    hrt_CreateOBJ(9, 0, 56, 0, 0, 0, 0, 0, 0, 0, 1, 0, OBJ_MODE_ALPHA, 0, 545-512);
    menu.selectionlimit = 3;
    menu.menuid = 0;
    hrt_FXSetBlendMode(FX_MODE_ALPHA);
    hrt_FXEnableBGTarget2(2);
    while(1) {
        hrt_VblankIntrWait();
        AnimMenuCursor();
        if ((keyDown(KEY_UP))AND(!(menu.arpos == 0))AND(menu.uplock == 0)) {
            menu.arpos--;
            menu.uplock = 1;
            audio.MenuSelect = mmEffectEx(&m_select);
        }
        if (!(keyDown(KEY_UP))) {
            menu.uplock = 0;
        }
        if ((keyDown(KEY_DOWN))AND(!(menu.arpos == menu.selectionlimit))AND(menu.downlock == 0)) {
            menu.arpos++;
            menu.downlock = 1;
            audio.MenuSelect = mmEffectEx(&m_select);
        }
        if (!(keyDown(KEY_DOWN))) {
            menu.downlock = 0;
        }
        hrt_SetOBJXY(9, 0, (menu.arpos * 8) + 56);
        if(keyDown(KEY_A)) {
            if(menu.menuid == 0) {
                if((menu.arpos == 0)OR(menu.arpos == 1)) {
                    if((menu.arpos == 1)AND(SaveFiles.Files[0].Allocated == 0)AND(SaveFiles.Files[1].Allocated == 0)AND(SaveFiles.Files[2].Allocated == 0)) {
                        audio.MenuUnavailable = mmEffectEx(&m_no);
                    }
                    else {
                        audio.MenuConfirm = mmEffectEx(&m_confirm);
                        hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
                        hrt_FXEnableBGTarget1(2);
                        hrt_FXEnableBGTarget1(1);
                        hrt_FXEnableBGTarget1(0);
                        hrt_FXEnableOBJTarget1();
                        hrt_FXEnableBackdropTarget1();
                        for (game.i = 0; game.i < 16; game.i++) {
                            REG_BLDY = game.i;
                            hrt_VblankIntrWait();
                            AnimMenuCursor();
                        }
                        hrt_DSPDisableBG(1);
                        hrt_SetOffset(OFF_BGPAL, 16);
                        hrt_DMA_Copy(3, m_continueTiles, (u32*)0x600C000, 448, 0x80000000);
                        hrt_DMA_Copy(3, m_continueMap, (u32*)0x6002000, 1024, 0x80000000);
                        hrt_LoadBGPal((void*)m_continuePal, 16);
                        for(game.i = 0; game.i < 1024; game.i++) {
                            VRAM[0x2000+game.i] |= BIT12;
                        }
                        hrt_ClearTiledText();
                        hrt_PrintOnTilemap(2, 3, gl_menu_f1);
                        hrt_PrintOnTilemap(2, 10, gl_menu_f2);
                        hrt_PrintOnTilemap(2, 17, gl_menu_f3);
                        u8 temp;
                        if(SaveFiles.Files[0].Allocated == 0) {
                            hrt_PrintOnTilemap(10, 3, gl_menu_cont_empt);
                        }
                        else {
                            temp = percentages[SaveFiles.Files[0].CompletedStages];
                            hrt_PrintOnTilemap(10, 3, "%d%s", temp, gl_continue_percent);
                        }
                        if(SaveFiles.Files[1].Allocated == 0) {
                            hrt_PrintOnTilemap(10, 10, gl_menu_cont_empt);
                        }
                        else {
                            temp = percentages[SaveFiles.Files[1].CompletedStages];
                            hrt_PrintOnTilemap(10, 10, "%d%s", temp, gl_continue_percent);
                        }
                        if(SaveFiles.Files[2].Allocated == 0) {
                            hrt_PrintOnTilemap(10, 17, gl_menu_cont_empt);
                        }
                        else {
                            temp = percentages[SaveFiles.Files[2].CompletedStages];
                            hrt_PrintOnTilemap(10, 17, "%d%s", temp, gl_continue_percent);
                        }
                        menu.temparpos = menu.arpos;
                        menu.arpos = 0;
                        hrt_SetOBJXY(9, 8, 24);
                        for (game.i = 0; game.i < 16; game.i++) {
                            REG_BLDY = 16-game.i;
                            hrt_VblankIntrWait();
                        }
                        menu.selectionlimit = 2;
                        while(!(keyDown(KEY_B))) {
                            hrt_VblankIntrWait();
                            AnimMenuCursor();
                            hrt_SetOBJXY(9, 8, contheights[menu.arpos]);
                            MenuCursor();
                            if(keyDown(KEY_A)) {
                                if(menu.temparpos == 0) {
                                    if(SaveFiles.Files[menu.arpos].Allocated == 1) {
                                        audio.MenuConfirm = mmEffectEx(&m_confirm);
                                        menu.temparpos2 = menu.arpos;
                                        menu.arpos = 0;
                                        hrt_ClearTiledText();
                                        hrt_SetOBJXY(9, 240, 160);
                                        hrt_PrintOnTilemap(hrt_Div(30-strlen((char*)gl_pause_warn), 2), 9, gl_pause_warn);
                                        hrt_PrintOnTilemap(6, 10, (char*)gl_choice_y);
                                        hrt_PrintOnTilemap(21, 10, (char*)gl_choice_n);
                                        while(keyDown(KEY_A)) {
                                            AnimMenuCursor();
                                            hrt_VblankIntrWait();
                                        }
                                        while(!(keyDown(KEY_A))) {
                                            if ((keyDown(KEY_LEFT))AND(!(menu.arpos == 0))AND(menu.uplock == 0)) {
                                                menu.arpos--;
                                                menu.uplock = 1;
                                                audio.MenuSelect = mmEffectEx(&m_select);
                                            }
                                            if (!(keyDown(KEY_LEFT))) {
                                                menu.uplock = 0;
                                            }
                                            if ((keyDown(KEY_RIGHT))AND(!(menu.arpos == 1))AND(menu.downlock == 0)) {
                                                menu.arpos++;
                                                menu.downlock = 1;
                                                audio.MenuSelect = mmEffectEx(&m_select);
                                            }
                                            if (!(keyDown(KEY_RIGHT))) {
                                                menu.downlock = 0;
                                            }
                                            hrt_SetOBJXY(9, overwrite[menu.arpos], 80);
                                            AnimMenuCursor();
                                            hrt_VblankIntrWait();
                                        }
                                        audio.MenuConfirm = mmEffectEx(&m_confirm);
                                        if(menu.arpos == 0) {
											SaveFiles.Files[menu.temparpos2].Allocated = 1;
                                            SaveFiles.Files[menu.temparpos2].CompletedStages = 0;
                                            SaveFiles.Files[menu.temparpos2].StageOnMap = 0;
                                            SaveFiles.Files[menu.temparpos2].Lives = 5;
                                            SaveFiles.Files[menu.temparpos2].Health = 6;
											Story();
                                        }
                                        hrt_ClearTiledText();
                                        hrt_PrintOnTilemap(2, 3, gl_menu_f1);
                                        hrt_PrintOnTilemap(2, 10, gl_menu_f2);
                                        hrt_PrintOnTilemap(2, 17, gl_menu_f3);
                                        u8 temp;
                                        if(SaveFiles.Files[0].Allocated == 0) {
                                            hrt_PrintOnTilemap(10, 3, gl_menu_cont_empt);
                                        }
                                        else {
                                            temp = percentages[SaveFiles.Files[0].CompletedStages];
                                            hrt_PrintOnTilemap(10, 3, "%d%s", temp, gl_continue_percent);
                                        }
                                        if(SaveFiles.Files[1].Allocated == 0) {
                                            hrt_PrintOnTilemap(10, 10, gl_menu_cont_empt);
                                        }
                                        else {
                                            temp = percentages[SaveFiles.Files[1].CompletedStages];
                                            hrt_PrintOnTilemap(10, 10, "%d%s", temp, gl_continue_percent);
                                        }
                                        if(SaveFiles.Files[2].Allocated == 0) {
                                            hrt_PrintOnTilemap(10, 17, gl_menu_cont_empt);
                                        }
                                        else {
                                            temp = percentages[SaveFiles.Files[2].CompletedStages];
                                            hrt_PrintOnTilemap(10, 17, "%d%s", temp, gl_continue_percent);
                                        }
                                        menu.arpos = menu.temparpos;
                                        hrt_SetOBJXY(9, 8, 24);
                                        while(keyDown(KEY_A)) {
                                            hrt_VblankIntrWait();
                                            AnimMenuCursor();
                                        }
                                    }
                                    else {
											SaveFiles.Files[menu.temparpos2].Allocated = 1;
                                            SaveFiles.Files[menu.temparpos2].CompletedStages = 0;
                                            SaveFiles.Files[menu.temparpos2].StageOnMap = 0;
                                            SaveFiles.Files[menu.temparpos2].Lives = 5;
                                            SaveFiles.Files[menu.temparpos2].Health = 6;
											Story();
                                    }
                                }else{
											game.currentfile = menu.temparpos2;
											worldmap();
										}
                            }
                        }
                        for (game.i = 0; game.i < 16; game.i++) {
                            REG_BLDY = game.i;
                            hrt_VblankIntrWait();
                            AnimMenuCursor();
                        }
                        hrt_SetOffset(OFF_BGPAL, 16);
                        hrt_DMA_Copy(3, m_bg_Tiles, (u32*)0x600C000, 448, 0x80000000);
                        hrt_DMA_Copy(3, m_bg_Map, (u32*)0x6002000, 1024, 0x80000000);
                        hrt_DMA_Copy(3, m_titleTiles, (u32*)0x6008000, 800, 0x80000000);
                        hrt_DMA_Copy(3, m_titleMap, (u32*)0x6002800, 1024, 0x80000000);
                        hrt_LoadBGPal((void*)m_bgPalette, 16);
                        for(game.i = 0; game.i < 1024; game.i++) {
                            VRAM[0x2000+game.i] |= BIT12;
                        }
                        hrt_DSPEnableBG(1);
                        hrt_BGSetMapBase(2, 4);
                        hrt_BGSetTileBase(2, 3);
                        hrt_BGSetMapBase(1, 5);
                        hrt_BGSetTileBase(1, 2);
                        hrt_ClearTiledText();
                        hrt_PrintOnTilemap(1, 7, (char*)gl_menu_new);
                        hrt_PrintOnTilemap(1, 8, (char*)gl_menu_cont);
                        hrt_PrintOnTilemap(1, 9, (char*)gl_menu_opt);
                        hrt_PrintOnTilemap(1, 10, (char*)gl_menu_exit);
                        menu.arpos = menu.temparpos;
                        hrt_SetOBJXY(9, 0, (menu.arpos * 8) + 56);
                        hrt_CopyOAM();
                        for (game.i = 0; game.i < 16; game.i++) {
                            REG_BLDY = 16-game.i;
                            hrt_VblankIntrWait();
                            AnimMenuCursor();
                        }
                    }
                }
                else if(menu.arpos == 2) {
                    audio.MenuConfirm = mmEffectEx(&m_confirm);
                    for (game.i = 257; game.i > 128; game.i -= 2) {
                        hrt_VblankIntrWait();
                        AnimMenuCursor();
                        REG_BG0VOFS = game.i;
                        if(game.i > 257-33) {
                            if (16 == effecta) {
                                effectinc = -1;
                            }
                            if (0 == effecta) {
                                effectinc = 1;
                            }
                            hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                16 - effectb);
                            effecta += effectinc;
                            effectb += effectinc;
                        }
                    }
                    menu.temparpos = menu.arpos;
                    menu.arpos = 0;
                    menu.selectionlimit = 4;
                    hrt_PrintOnTilemap(1, 7, (char*)gl_menu_opt_music);
                    hrt_PrintOnTilemap(1, 8, (char*)gl_menu_opt_sound);
                    hrt_PrintOnTilemap(1, 9, (char*)gl_menu_opt_credits);
                    hrt_PrintOnTilemap(1, 10, (char*)gl_options_controls);
                    hrt_PrintOnTilemap(1, 11, (char*)gl_menu_exit);
                    hrt_SetOBJXY(9, 0, (menu.arpos * 8) + 56);
                    for (game.i = 128; game.i < 257; game.i += 2) {
                        hrt_VblankIntrWait();
                        REG_BG0VOFS = game.i;
                        AnimMenuCursor();
                        if(game.i < 128+33) {
                            if (16 == effecta) {
                                effectinc = -1;
                            }
                            if (0 == effecta) {
                                effectinc = 1;
                            }
                            hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                16 - effectb);
                            effecta += effectinc;
                            effectb += effectinc;
                        }
                    }
                    effectinc = 0;
                    effecta = 0;
                    effectb = 0;
                    while(!((keyDown(KEY_A))AND(menu.arpos == 4))) {
                        hrt_VblankIntrWait();
                        AnimMenuCursor();
						MenuCursor();
                        hrt_SetOBJXY(9, 0, (menu.arpos * 8) + 56);
                        if(menu.arpos == 0) {
                            musicvolume();
                        }
                        if(menu.arpos == 1) {
                            soundvolume();
                        }
                        if(keyDown(KEY_A)) {
                            if(menu.arpos == 2) {
                                Credits();
                            }
                            if(menu.arpos == 3) {
                                audio.MenuConfirm = mmEffectEx(&m_confirm);
                                for (game.i = 257; game.i > 128; game.i -= 2) {
                                    hrt_VblankIntrWait();
                                    AnimMenuCursor();
                                    REG_BG0VOFS = game.i;
                                    if(game.i > 257-33) {
                                        if (16 == effecta) {
                                            effectinc = -1;
                                        }
                                        if (0 == effecta) {
                                            effectinc = 1;
                                        }
                                        hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                            16 - effectb);
                                        effecta += effectinc;
                                        effectb += effectinc;
                                    }
                                }
                                hrt_ClearTiledText();
                                hrt_PrintOnTilemap(1, 7, (char*)gl_controls_a);
                                hrt_PrintOnTilemap(1, 8, (char*)gl_controls_b);
                                hrt_PrintOnTilemap(1, 9, (char*)gl_controls_dpad);
                                hrt_PrintOnTilemap(1, 10, (char*)gl_controls_start);
                                for (game.i = 128; game.i < 257; game.i += 2) {
                                    hrt_VblankIntrWait();
                                    REG_BG0VOFS = game.i;
                                    AnimMenuCursor();
                                }
                                while(!(keyDown(KEY_A))) {
                                    hrt_VblankIntrWait();
                                }
                                for (game.i = 257; game.i > 128; game.i -= 2) {
                                    hrt_VblankIntrWait();
                                    AnimMenuCursor();
                                    REG_BG0VOFS = game.i;
                                }
                                hrt_ClearTiledText();
                                hrt_PrintOnTilemap(1, 7, (char*)gl_menu_opt_music);
                                hrt_PrintOnTilemap(1, 8, (char*)gl_menu_opt_sound);
                                hrt_PrintOnTilemap(1, 9, (char*)gl_menu_opt_credits);
                                hrt_PrintOnTilemap(1, 10, (char*)gl_options_controls);
                                hrt_PrintOnTilemap(1, 11, (char*)gl_menu_exit);
                                for (game.i = 128; game.i < 257; game.i += 2) {
                                    hrt_VblankIntrWait();
                                    REG_BG0VOFS = game.i;
                                    AnimMenuCursor();
                                    if(game.i < 128+33) {
                                        if (16 == effecta) {
                                            effectinc = -1;
                                        }
                                        if (0 == effecta) {
                                            effectinc = 1;
                                        }
                                        hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                            16 - effectb);
                                        effecta += effectinc;
                                        effectb += effectinc;
                                    }
                                }
                                effectinc = 0;
                                effecta = 0;
                                effectb = 0;
                            }
                        }
                    }
                    audio.MenuConfirm = mmEffectEx(&m_confirm);
                    for (game.i = 257; game.i > 128; game.i -= 2) {
                        hrt_VblankIntrWait();
                        AnimMenuCursor();
                        REG_BG0VOFS = game.i;
                        if(game.i > 257-33) {
                            if (16 == effecta) {
                                effectinc = -1;
                            }
                            if (0 == effecta) {
                                effectinc = 1;
                            }
                            hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                16 - effectb);
                            effecta += effectinc;
                            effectb += effectinc;
                        }
                    }
                    menu.arpos = menu.temparpos;
                    menu.selectionlimit = 3;
                    hrt_ClearTiledText();
                    hrt_PrintOnTilemap(1, 7, (char*)gl_menu_new);
                    hrt_PrintOnTilemap(1, 8, (char*)gl_menu_cont);
                    hrt_PrintOnTilemap(1, 9, (char*)gl_menu_opt);
                    hrt_PrintOnTilemap(1, 10, (char*)gl_menu_exit);
                    hrt_SetOBJXY(9, 0, (menu.arpos * 8) + 56);
                    for (game.i = 128; game.i < 257; game.i += 2) {
                        hrt_VblankIntrWait();
                        REG_BG0VOFS = game.i;
                        AnimMenuCursor();
                        if(game.i < 128+33) {
                            if (16 == effecta) {
                                effectinc = -1;
                            }
                            if (0 == effecta) {
                                effectinc = 1;
                            }
                            hrt_SetFXAlphaLevel(effecta,             // Source intensity
                                                16 - effectb);
                            effecta += effectinc;
                            effectb += effectinc;
                        }
                    }
                    effecta = 0;
                    effectb = 0;
                    effectinc = 0;
                }
                else {
                    hrt_EZ4Exit();
                }
            }
        }
    }
}