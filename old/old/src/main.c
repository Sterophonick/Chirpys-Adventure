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
void vblFunc(void);

extern mm_byte sndvolumetable[11];
extern mm_word musvolumetable[11];

int main()
{
    hrt_EnableRTC();
    hrt_Init();
    game.debug = 1; //This should only be used for debugging purposes, as it slows the game down.
    LoadGames();
    CheckSRAM();
    REG_BG2VOFS = 0;
    unsigned char *p = (unsigned char*)&SaveFiles.RNGSeed;
    p[0] = hrt_LoadByte(0x00);
    p[1] = hrt_LoadByte(0x01);
    hrt_SeedRNG(SaveFiles.RNGSeed);
    mmInitDefault((mm_addr)soundbank_bin, 8);
    mmSetVBlankHandler(vblFunc);
    hrt_DSPSetBGMode(3);
    hrt_DSPEnableBG(2);
    hrt_DSPDisableForceBlank();
    hrt_FXSetBlendMode(FX_MODE_BRIGHTEN);
    hrt_FXEnableBGTarget1(2);
    hrt_SetFXLevel(16);
    hrt_SetDSPMode(4, //Mode
                   0,								  //CGB Mode
                   0,								  //Frame Select
                   0,                               //Unlocked HBlank
                   0,                               //Linear OBJ Tile Mapping
                   0,                               //Force Blank
                   0,                               //BG 0
                   0,                               //BG 1
                   1,                               //BG 2
                   0,                               //BG 3
                   0,                               //OBJ
                   0,                               //Win 0
                   0,                               //Win 1
                   0);							  //OBJWin
    hrt_SetFXMode(1, 1, 1, 1, 1, 1, 2, 0, 0, 0, 0, 0, 0);
    hrt_SetFXLevel(31);
    hrt_LZ77UnCompVRAM((u32)disclaimerBitmap, (u32)VRAM); //hrt_LZ77 decompresses disclaimer img
    hrt_LoadBGPal((void*)disclaimerPal, 16);
    hrt_SetOffset(OFF_BGPAL, 0);
    for (game.i = 0; game.i < 17; game.i++) {
        hrt_SetFXLevel(16 - game.i);
        hrt_SleepF(1);
    }
    game.i = 0;
    while (!((game.i == 255) | (keyDown(KEY_A)))) {
        game.i++;
        hrt_SetBGPalEntry(2, hrt_GetBGPalEntry(2) + 3); //Color Changing text
        hrt_SleepF(1); //Waits one frame
    }
    for (game.i = 0; game.i < 17; game.i++) {
        hrt_SetFXLevel(game.i);
        hrt_SleepF(1);
    }
    mmSetModuleVolume(musvolumetable[SaveFiles.MusicVolume]);
    MainMenu();
}

void vblFunc(void)
{
    game.frames++;
    unsigned char *p = (unsigned char*)&game.rngvalue;
    game.rngvalue = hrt_CreateRNG();
    SaveFiles.RNGSeed = game.rngvalue;
    REG_IME = 1;
    mmFrame();
    hrt_CopyOAM();
    m_select.id = SFX_M_SELECT;
    m_select.rate = (int)(1.0f * (1 << 10));
    m_select.handle = 1;
    m_select.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_select.panning = 128;
    m_confirm.id = SFX_M_CONFIRM;
    m_confirm.rate = (int)(1.0f * (1 << 10));
    m_confirm.handle = 2;
    m_confirm.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_confirm.panning = 128;
    m_no.id = SFX_M_NO;
    m_no.rate = (int)(1.0f * (1 << 10));
    m_no.handle = 3;
    m_no.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_no.panning = 128;
    m_sndvoltst.id = SFX_M_SNDVOLTST;
    m_sndvoltst.rate = (int)(1.0f * (1 << 10));
    m_sndvoltst.handle = 4;
    m_sndvoltst.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_sndvoltst.panning = 128;
    s_pageflip.id = SFX_S_PAGE;
    s_pageflip.rate = (int)(1.0f * (1 << 10));
    s_pageflip.handle = 5;
    s_pageflip.volume = sndvolumetable[SaveFiles.SoundVolume];
    s_pageflip.panning = 128;
    map_select.id = SFX_M_TRAVEL;
    map_select.rate = (int)(1.0f * (1 << 10));
    map_select.handle = 6;
    map_select.volume = sndvolumetable[SaveFiles.SoundVolume];
    map_select.panning = 128;
    map_confirm.id = SFX_M_ENTER;
    map_confirm.rate = (int)(1.0f * (1 << 10));
    map_confirm.handle = 7;
    map_confirm.volume = sndvolumetable[SaveFiles.SoundVolume];
    map_confirm.panning = 128;
    g_pause.id = SFX_G_PAUSE;
    g_pause.rate = (int)(1.0f * (1 << 10));
    g_pause.handle = 8;
    g_pause.volume = sndvolumetable[SaveFiles.SoundVolume];
    g_pause.panning = 128;
    b_die.id = SFX_B_DED;
    b_die.rate = (int)(1.0f * (1 << 10));
    b_die.handle = 8;
    b_die.volume = sndvolumetable[SaveFiles.SoundVolume];
    b_die.panning = 128;
    b_step.id = SFX_B_STEP;
    b_step.rate = (int)(1.0f * (1 << 10));
    b_step.handle = 8;
    b_step.volume = sndvolumetable[SaveFiles.SoundVolume];
    b_step.panning = 128;
    b_jump.id = SFX_B_JUMP;
    b_jump.rate = (int)(1.0f * (1 << 10));
    b_jump.handle = 8;
    b_jump.volume = sndvolumetable[SaveFiles.SoundVolume];
    b_jump.panning = 128;
    b_hurt.id = SFX_B_HURT;
    b_hurt.rate = (int)(1.0f * (1 << 10));
    b_hurt.handle = 8;
    b_hurt.volume = sndvolumetable[SaveFiles.SoundVolume];
    b_hurt.panning = 128;
    m_save.id = SFX_M_SAVE;
    m_save.rate = (int)(1.0f * (1 << 10));
    m_save.handle = 8;
    m_save.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_save.panning = 128;
    m_load.id = SFX_M_LOAD;
    m_load.rate = (int)(1.0f * (1 << 10));
    m_load.handle = 8;
    m_load.volume = sndvolumetable[SaveFiles.SoundVolume];
    m_load.panning = 128;
    if((keyDown(KEY_A))AND(keyDown(KEY_B))AND(keyDown(KEY_SELECT))AND(keyDown(KEY_START))) {
        hrt_RegisterRamReset(hrt_ConfigRegisterRamReset(0,0,0,0,0,0,0,1));
        hrt_SoftReset();
    }
}