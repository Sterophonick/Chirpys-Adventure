void hrt_InitNoIntro();
typedef struct
{
	u32 xpos;
	u32 ypos;
	u8 yvel;
	u8 xvel;
	u8 health;
	u8 lives;
	u8 animframe;
	u8 animstate;
	u8 flight;
}player;

typedef struct
{
	u32 xscroll;
	u32 yscroll;
	u32 oldY;
	u32 newY;
	u32 oldX;
	u32 newX;
	u16* tiledata;
	u16* mapData;
	u16* palData;
}map;

typedef struct
{
	mm_sfxhand world1;
	mm_sfxhand world2;
	mm_sfxhand world3;
	mm_sfxhand world4;
	mm_sfxhand b_jump;
	mm_sfxhand b_step;
	mm_sfxhand b_hurt;
	mm_sfxhand b_ded;
	mm_sfxhand b_shoot;
	mm_sfxhand credits;
	mm_sfxhand e_ded;
	mm_sfxhand theme;
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
	u16 rngseed;
	u8 selection;
	u32 i;
}rom;

typedef struct
{
	u8 level;
	u8 world;
	u16 rngseed;
}sram;
void MapLayerDrawStripH(int layer, int srcY);
void MapLayerDrawStripV(int layerIdx, int srcX);

extern const u8 soundbank_bin_end[];
extern const u8 soundbank_bin[];
extern const u32 soundbank_bin_size;
const unsigned short level1Tiles[832];
const unsigned short level1Map[12000];
const unsigned short level1Pal[16];
const unsigned short f_0Tiles[128];
const unsigned short f_0Pal[16];
const unsigned short f_1Tiles[128];
const unsigned short f_2Tiles[128];
const unsigned short f_3Tiles[128];
const unsigned short f_4Tiles[128];
const unsigned short f_5Tiles[128];
const unsigned short f_6Tiles[128];
const unsigned short f_7Tiles[128];
const unsigned short f_8Tiles[128];
const unsigned short f_9Tiles[128];
const unsigned short f_10Tiles[128];
const unsigned short f_11Tiles[128];
const unsigned short f_12Tiles[128];
const unsigned short f_13Tiles[128];
const unsigned short f_14Tiles[128];
const unsigned short f_15Tiles[128];
const unsigned short f_16Tiles[128];
const unsigned short f_17Tiles[128];
const unsigned short f_18Tiles[128];
const unsigned short f_19Tiles[128];
const unsigned short f_20Tiles[128];
const unsigned short f_21Tiles[128];
const unsigned short f_22Tiles[128];
const unsigned short f_23Tiles[128];
const unsigned short f_24Tiles[128];
const unsigned short f_25Tiles[128];
const unsigned short f_fullTiles[128];
extern int hrt_offsetOAMData;
extern int hrt_offsetOAMPal;
extern int hrt_offsetBGMap;
extern int hrt_offsetBGTile;
extern int hrt_offsetBGPal;