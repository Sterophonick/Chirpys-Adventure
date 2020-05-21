#include <libheart.h>
#include "../inc/defs.h"
extern rom game;
extern sram SaveFiles;

void CheckSRAM()
{
    u8 temp;
    if(((SaveFiles.Files[0].Allocated == 0)AND(SaveFiles.Files[1].Allocated == 0)AND(SaveFiles.Files[2].Allocated == 0))OR((SaveFiles.Files[0].Allocated == 0xFF)AND(SaveFiles.Files[1].Allocated == 0xFF)AND(SaveFiles.Files[2].Allocated == 0xFF))) {
        hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
        hrt_FXEnableBGTarget1(0);
        hrt_FXEnableBGTarget1(1);
        hrt_FXEnableBackdropTarget1();
        hrt_SetFXLevel(16);
        hrt_DSPDisableForceBlank();
        hrt_DSPEnableBG(0);
        hrt_DSPEnableBG(1);
        hrt_DSPSetBGMode(0);
        hrt_InitTiledText(0);
        hrt_SetOffset(OFF_BGPAL, 16);
        hrt_DMA_Copy(3, m_bg_Tiles, (u32*)0x600C000, 448, 0x80000000);
        hrt_DMA_Copy(3, m_bg_Map, (u32*)0x6002000, 1024, 0x80000000);
        hrt_BGSetMapBase(1, 4);
        hrt_BGSetTileBase(1, 3);
        hrt_LoadBGPal((void*)m_bgPalette, 16);
        for(game.i = 0; game.i < 1024; game.i++) {
            VRAM[0x2000+game.i] |= BIT12;
        }
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_1)), 2);
        hrt_PrintOnTilemap(temp, 7, (char*)gl_debug_savenote_1);
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_2)), 2);
        hrt_PrintOnTilemap(temp, 8, (char*)gl_debug_savenote_2);
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_3)), 2);
        hrt_PrintOnTilemap(temp, 9, (char*)gl_debug_savenote_3);
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_4)), 2);
        hrt_PrintOnTilemap(temp, 10, (char*)gl_debug_savenote_4);
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_5)), 2);
        hrt_PrintOnTilemap(temp, 11, (char*)gl_debug_savenote_5);
        temp = hrt_Div((30-strlen((char*)gl_debug_savenote_6)), 2);
        hrt_PrintOnTilemap(temp, 12, (char*)gl_debug_savenote_6);
        for (game.i = 0; game.i < 16; game.i++) {
            REG_BLDY = 16-game.i;
            hrt_VblankIntrWait();
        }
        while(!(KEY_ANY_PRESSED)) {
            hrt_VblankIntrWait();
        }
        hrt_RegisterRamReset(hrt_ConfigRegisterRamReset(0, 0, 1, 1, 0, 0, 0, 0));
        hrt_SetOffset(OFF_BGPAL, 0);
    }
    else if((SaveFiles.MusicVolume > 10)OR(SaveFiles.SoundVolume > 10)OR(SaveFiles.Files[0].Allocated > 1)OR(SaveFiles.Files[1].Allocated > 1)OR(SaveFiles.Files[2].Allocated > 1)) {
        hrt_DSPEnableBG(0);
        hrt_DSPDisableForceBlank();
        hrt_DSPSetBGMode(0);
        hrt_InitTiledText(0);
        temp = hrt_Div((30-strlen((char*)gl_debug_data_error)), 2);
        hrt_PrintOnTilemap(temp, 10, (char*)gl_debug_data_error);
        hrt_Memcpy(SRAM, 0x02000100, 0xFFFF);
        game.frames = 0;
        hrt_Memcpy(SRAM, 0x02000100, 0xFFFF); //clears SRAM
        while(!(KEY_ANY_PRESSED)) {
            hrt_VblankIntrWait();
            game.frames++;
            if(!(game.frames % 20)) {
                temp++;
                if(temp == 1) {
                    hrt_DSPEnableBG(0);
                }
                else {
                    hrt_DSPDisableBG(0);
                    temp = 0;
                }
            }
        }
        hrt_RegisterRamReset(hrt_ConfigRegisterRamReset(0, 0, 1, 1, 0, 0, 0, 0));
        hrt_SetOffset(OFF_BGPAL, 0);
    }
    if((keyDown(KEY_A))AND(keyDown(KEY_B))) {
        if(!(keyDown(KEY_START))) {
            hrt_DSPDisableForceBlank();
            hrt_DSPEnableBG(0);
            hrt_DSPEnableBG(1);
            hrt_DSPSetBGMode(0);
            hrt_InitTiledText(0);
            hrt_PrintOnTilemap(0, 0, (char*)gl_debug_erase);
            while ((((keyDown(KEY_A))OR(keyDown(KEY_B))))) {
                hrt_VblankIntrWait();
            }
            while (!((((keyDown(KEY_A))OR(keyDown(KEY_B)))))) {
                hrt_VblankIntrWait();
            }
            if ((keyDown(KEY_A))AND(!(keyDown(KEY_B)))) {
                hrt_ClearTiledText();
                hrt_PrintOnTilemap(0, 0, (char*)gl_choice_a); //draws text
                hrt_PrintOnTilemap(0, 1, (char*)gl_debug_all); //draws text
                while (((keyDown(KEY_A))OR(keyDown(KEY_B)))) {
                    hrt_VblankIntrWait();
                } //waits until a or b is not pressed
                while (!(((keyDown(KEY_A))OR(keyDown(KEY_B))))) {
                    hrt_VblankIntrWait();
                } //waits until a or b is pressed
                if (keyDown(KEY_A)) {
                    while (((keyDown(KEY_A))OR(keyDown(KEY_B)))) {
                        hrt_VblankIntrWait();
                    } //waits until a or b is not pressed
                    hrt_ClearTiledText();
                    hrt_PrintOnTilemap(0, 0, (char*)gl_debug_erasing); //draws text
                    hrt_Memcpy(SRAM, 0x02000100, 0xFFFF); //clears SRAM
                    hrt_SleepF(240); //Sleeps for 4 seconds
                    hrt_SaveByte(2, 8);
                    hrt_SaveByte(3, 8);
                    hrt_ClearTiledText();
                    hrt_PrintOnTilemap(0, 0, (char*)gl_debug_restart); //draw text
                    while (!(KEY_ANY_PRESSED)) {
                        hrt_VblankIntrWait();
                    }//waits until any key is pressed
                    hrt_ColdReset(); //resets console
                }
                else {
                    hrt_ClearTiledText();
                    hrt_PrintOnTilemap(0, 0, (char*)gl_debug_abort); //draws text
                    hrt_PrintOnTilemap(0, 1, (char*)gl_debug_restart); //draws text
                    while (!(KEY_ANY_PRESSED)) {
                        hrt_VblankIntrWait();
                    } //waits until any key is pressed
                    hrt_ColdReset(); //resets console
                }
            }
            else if ((keyDown(KEY_B))AND(!(keyDown(KEY_A)))) {
                hrt_ClearTiledText();
                hrt_PrintOnTilemap(0, 0, (char*)gl_debug_abort); //draws text
                hrt_PrintOnTilemap(0, 1, (char*)gl_debug_restart); //draws text
                while (!(KEY_ANY_PRESSED)) {
                    hrt_VblankIntrWait();
                } //waits until any key pressed
                hrt_ColdReset();//resets console
            }
        }
    }
}