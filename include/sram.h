typedef struct {
    u8 Allocated;
    u8 CompletedStages;
    u8 StageOnMap;
    s8 Lives;
    u8 Health;
} savefile;

typedef struct {
    s16 RNGSeed;
    u8 MusicVolume;
    u8 SoundVolume;
    savefile Files[3];
} sram;

extern sram saves;