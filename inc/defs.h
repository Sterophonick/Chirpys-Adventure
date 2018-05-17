void hrt_InitNoIntro();
void physics(void);

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
	mm_sfxhand menusel;
	mm_sfxhand menuconf;
	mm_sfxhand pageflip;
	mm_sfxhand b_jump;
	mm_sfxhand b_step;
	mm_sfxhand b_step2;
	mm_sfxhand b_hurt;
	mm_sfxhand b_ded;
	mm_sfxhand b_shoot;
	mm_sfxhand credits;
	mm_sfxhand e_ded;
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
	u16* genericptr;
}rom;

typedef struct
{
	u8 arpos;
	u8 arframe;
	u8 selection;
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
	u8 world;
	u8 stage;
	u8 lives;
	u8 health;
}savefile;

typedef struct
{
	savefile save1;
	savefile save2;
	savefile save3;
	u16 RNGSeed;
}sram;

void MapLayerDrawStripH(int layerIdx, int srcY);
void MapLayerDrawStripV(int layerIdx, int srcX);
void detectcollision();
void animbird();

#define BG_SCRN_VRAM(n) ((u16*)(0x6000000 + ((n) << 11))) 
#define fptochar(x) ((x) >> 11) 
#define inttofp(x) ((x) << 8) 

typedef struct _s16xy { s16 x, y; } s16xy;

typedef struct _Vector2 { s32 x, y; } Vector2;

typedef struct _MapLayer { u16 *map; Vector2 scroll; } MapLayer;

typedef struct _GameMap
{
	s16xy dimensions;
	const u16 *tileset; // Pointer to map file output from gfx2gba for the tileset bitmap 
	u8 numLayers; // Number of layers actually in use for the current map. Max 4 since that's all the hardware BGs 
	MapLayer layer[4];

} GameMap;

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
const unsigned short m_continueTiles[256];
const unsigned short m_continuePal[16];
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
const unsigned short m_title_Map[1024];
const unsigned char m_title_Tiles[1600];
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