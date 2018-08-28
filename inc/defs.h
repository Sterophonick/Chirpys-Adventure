void physics(void);
void Credits(void);
void MainMenu(void);
void SaveGames(void);
void LoadGames(void);
void Story();
void worldmap();
extern void MenuCursor();
extern void AnimMenuCursor();
void CheckSRAM();

extern mm_sound_effect m_select;
extern mm_sound_effect m_confirm;
extern mm_sound_effect m_no;
extern mm_sound_effect m_sndvoltst;
extern mm_sound_effect s_pageflip;
extern mm_sound_effect map_select;
extern mm_sound_effect map_confirm;
extern mm_sound_effect g_pause;

extern unsigned short pausePal[16];
extern unsigned short pauseTiles[160];
extern unsigned short pauseMap[640];
extern u16 worldmap1Tiles[352];
extern unsigned short worldmap1Pal[16];
extern unsigned short worldmap1Map[640];
extern u16 worldmap2Tiles[592];
extern unsigned short worldmap2Pal[16];
extern unsigned short worldmap2Map[640];

extern char gl_pause_r[];
extern char gl_pause_b[];
extern char gl_pause_q[];
extern char gl_story_1_1[];
extern char gl_story_1_2[];
extern char gl_story_2_1[];
extern char gl_story_2_2[];
extern char gl_story_3_1[];
extern char gl_story_4_1[];
extern char gl_story_4_2[];
extern char gl_story_4_3[];

extern char gl_debug_erase[];
extern char gl_debug_build[];
extern char gl_debug_savenote_1[];
extern char gl_debug_savenote_2[];
extern char gl_debug_savenote_3[];
extern char gl_debug_savenote_4[];
extern char gl_debug_savenote_5[];
extern char gl_debug_savenote_6[];
extern char gl_debug_data_error[];
extern char gl_debug_erase[];
extern char gl_debug_restart[];
extern char gl_debug_abort[];
extern char gl_debug_erasing[];
extern char gl_debug_all[];


extern char gl_controls_a[];
extern char gl_controls_b[];
extern char gl_controls_dpad[];
extern char gl_controls_start[];
extern char gl_choice_y[];
extern char gl_choice_n[];
extern char gl_choice_a[];
extern char gl_pause_warn[];
extern char gl_continue_percent[];
extern char *gl_credits[112];
extern char gl_menu_cont_empt[];
extern char gl_options_audio_0[];
extern char gl_options_audio_1[];
extern char gl_options_audio_2[];
extern char gl_options_audio_3[];
extern char gl_options_audio_4[];
extern char gl_options_audio_5[];
extern char gl_options_audio_6[];
extern char gl_options_audio_7[];
extern char gl_options_audio_8[];
extern char gl_options_audio_9[];
extern char gl_options_audio_A[];
extern char gl_menu_press[];
extern char gl_menu_new[];
extern char gl_menu_cont[];
extern char gl_menu_opt[];
extern char gl_menu_exit[];
extern char gl_menu_opt_music[];
extern char gl_menu_opt_sound[];
extern char gl_menu_opt_credits[];
extern char gl_menu_opt_sndtst[];
extern char gl_options_controls[];
extern char gl_menu_f1[];
extern char gl_menu_f2[];
extern char gl_menu_f3[];

typedef struct
{
	u32 xpos;
	u32 ypos;
	s16 yvel;
	s16 xvel;
	u8 health;
	u8 lives;
	u8 animframe;
	u8 animstate;
	u8 flight;
	u8 continues;
	u8 jumpi;
	u8 flightlock;
	u8 oldx;
	u8 oldy;
	u8 tilex;
	u8 tiley;
	u8 ycoll;
	u8 animtimer;
	u8 firetimer;
	u8 firex;
	u8 firey;
	u8 firecol_l;
	u8 firecol_r;
	u32 screenx;
	u32 screeny;
}player;

typedef struct
{
	s32 xscroll;
	s32 yscroll;
	s32 oldY;
	s32 newY;
	s32 oldX;
	s32 newX;
	u16* tiledata;
	u16* mapData;
	u16* palData;
	u16 tileX;
	u16 tileY;
	u8 loadxlock;
	u8 loadylock;
	u8* colmap;
}map;

typedef struct
{
	mm_sfxhand MenuSelect;
	mm_sfxhand MenuConfirm;
	mm_sfxhand PageFlip;
	mm_sfxhand ChirpyJump;
	mm_sfxhand ChirpyStep;
	mm_sfxhand ChirpyStep2;
	mm_sfxhand ChirpyHurt;
	mm_sfxhand ChirpyDie;
	mm_sfxhand ChirpyShoot;
	mm_sfxhand EnemyDie;
	mm_sfxhand MapSelect;
	mm_sfxhand MapEnter;
	mm_sfxhand GamePause;
	mm_sfxhand MenuSFXVolumeChange;
	mm_sfxhand MenuUnavailable;
}snd;

typedef struct
{
	u8 type;
	u8 health;
	u8 xpos;
	u8 ypos;
}enemy;

typedef struct
{
	u8 level;
	u8 world;
	u16 rngvalue;
	u8 selection;
	u32 i;
	u32 i2;
	u8 alock;
	u8 block;
	u8 startlock;
	u8 llock;
	u8 rlock;
	u32 frames;
	u32* genericptr;
	u8 currentfile;
}rom;

typedef struct
{
	u8 arpos;
	u8 arframe;
	u8 selection;
	u8 uplock;
	u8 downlock;
	u8 selectionlimit;
	u8 menuid;
	u8 temparpos;
	u8 temparpos2;
}gmenu;

typedef struct
{
	u8 topl;
	u8 bottoml;
	u8 leftu;
	u8 rightu;
	u8 topr;
	u8 bottomr;
	u8 leftd;
	u8 rightd;
}col;

typedef struct
{
	u8 Allocated;
	u8 CompletedStages;
	u8 StageOnMap;
	s8 Lives;
	u8 Health;
}savefile;

typedef struct
{
	s16 RNGSeed;
	u8 MusicVolume;
	u8 SoundVolume;
	savefile Files[3];
}sram;
void detectcollision();
void animbird();

extern const u8 soundbank_bin_end[];
extern const u8 soundbank_bin[];
extern const u32 soundbank_bin_size;

const unsigned short level1Tiles[816];
const unsigned short level1MetaTiles[84];
const unsigned short level1MetaMap[3000];
const unsigned short level1Pal[16];

const unsigned short level2Tiles[736];
const unsigned short level2MetaTiles[80];
const unsigned short level2MetaMap[3000];
const unsigned short level2Pal[16];

const unsigned short f_0Tiles[64];
const unsigned short f_0Pal[16];
const unsigned short f_1Tiles[64];
const unsigned short f_2Tiles[64];
const unsigned short f_3Tiles[64];
const unsigned short f_4Tiles[64];
const unsigned short f_5Tiles[64];
const unsigned short f_6Tiles[64];
const unsigned short f_7Tiles[64];
const unsigned short f_8Tiles[64];
const unsigned short f_9Tiles[64];
const unsigned short f_10Tiles[64];
const unsigned short f_11Tiles[64];
const unsigned short f_12Tiles[64];
const unsigned short f_13Tiles[64];
const unsigned short f_14Tiles[64];
const unsigned short f_15Tiles[64];
const unsigned short f_16Tiles[64];
const unsigned short f_17Tiles[64];
const unsigned short f_18Tiles[64];
const unsigned short f_19Tiles[64];
const unsigned short f_20Tiles[64];
const unsigned short f_21Tiles[64];
const unsigned short f_22Tiles[64];
const unsigned short f_23Tiles[64];
const unsigned short f_24Tiles[64];
const unsigned short f_25Tiles[64];
const unsigned short f_fullTiles[64];

const unsigned short h_halfTiles[64];
const unsigned short h_fullTiles[64];
const unsigned short h_emptyTiles[64];
const unsigned short heartPal[16];

const unsigned short b_idlePal[16];
const unsigned short h_headTiles[16];
const unsigned short b_idleTiles[64];
const unsigned short b_idle_fTiles[64];
const unsigned short b_run3Tiles[64];
const unsigned short b_run2_fTiles[64];
const unsigned short b_run2Tiles[64];
const unsigned short b_run1_fTiles[64];
const unsigned short b_run1Tiles[64];
const unsigned short b_flapTiles[64];
const unsigned short b_fall_fTiles[64];
const unsigned short b_fallTiles[64];
const unsigned short b_dieTiles[64];
const unsigned short b_fireTiles[16];

const unsigned short e_cralen1Tiles[64];
const unsigned short e_cralen2Tiles[64];

const unsigned short hudTextPal[16];
const unsigned short h_numsTiles[160];
const unsigned short h_xTiles[16];
const unsigned short h_stageTiles[128];
const unsigned short h_flightTiles[512];

extern int hrt_offsetOAMData;
extern int hrt_offsetOAMPal;
extern int hrt_offsetBGMap;
extern int hrt_offsetBGTile;
extern int hrt_offsetBGPal;
void animflight();

const unsigned short m_yearTiles[576];
const unsigned short m_creditsTiles[112];
const unsigned short m_musvolTiles[208];
const unsigned short m_sfxvolTiles[176];
const unsigned short m_optionsTiles[256];
const unsigned short m_newgameTiles[256];
const unsigned short m_continuePal[16];
const unsigned short m_continueTiles[176];
const unsigned short m_continueMap[640];
const unsigned short m_exitTiles[128];
const unsigned short m_arrow4Tiles[16];
const unsigned short m_arrow4Pal[16];
const unsigned short m_arrow3Tiles[16];
const unsigned short m_arrow2Tiles[16];
const unsigned short m_arrow1Tiles[16];
const unsigned short m_startgameTiles[160];
const unsigned short m_pressstartTiles[192];
const unsigned short m_bg_Map[1024];
const unsigned char m_bg_Tiles[864];
const unsigned short m_titleMap[1024];
const unsigned char m_titleTiles[800];
const unsigned short m_bgPalette[16];

const unsigned short disclaimerBitmap[2514];
const unsigned short disclaimerPal[16];
const unsigned short creditsBitmap[2466];
const unsigned short creditsPal[16];

const unsigned char l1_1colmap[40][300];

const unsigned short story1Bitmap[4632];
const unsigned short story2Bitmap[4796];
const unsigned short story3Bitmap[4798];
const unsigned short story4Bitmap[4796];

const unsigned short continueBitmap[4560];