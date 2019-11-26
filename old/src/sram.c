#include <libheart.h>
#include "..\inc\defs.h"
extern sram SaveFiles;
extern rom game;

void SaveGames()
{
	unsigned char *p = (unsigned char*)&SaveFiles.RNGSeed;
	hrt_SaveByte(0, p[0]);
	hrt_SaveByte(1, p[1]);
	hrt_SaveByte(2, SaveFiles.MusicVolume);
	hrt_SaveByte(3, SaveFiles.SoundVolume);
	
	hrt_SaveByte(4, SaveFiles.Files[0].Allocated);
	hrt_SaveByte(5, SaveFiles.Files[0].CompletedStages);
	hrt_SaveByte(6, SaveFiles.Files[0].StageOnMap);
	hrt_SaveByte(7, SaveFiles.Files[0].Lives);
	hrt_SaveByte(8, SaveFiles.Files[0].Health);
	
	hrt_SaveByte(9, SaveFiles.Files[1].Allocated);
	hrt_SaveByte(10, SaveFiles.Files[1].CompletedStages);
	hrt_SaveByte(11, SaveFiles.Files[1].StageOnMap);
	hrt_SaveByte(12, SaveFiles.Files[1].Lives);
	hrt_SaveByte(13, SaveFiles.Files[1].Health);
	
	hrt_SaveByte(14, SaveFiles.Files[2].Allocated);
	hrt_SaveByte(15, SaveFiles.Files[2].CompletedStages);
	hrt_SaveByte(16, SaveFiles.Files[2].StageOnMap);
	hrt_SaveByte(17, SaveFiles.Files[2].Lives);
	hrt_SaveByte(18, SaveFiles.Files[2].Health);
}

void LoadGames()
{
	SaveFiles.RNGSeed = hrt_LoadByte(0);
	SaveFiles.MusicVolume = hrt_LoadByte(2);
	SaveFiles.SoundVolume = hrt_LoadByte(3);
	
	SaveFiles.Files[0].Allocated = hrt_LoadByte(4);
	SaveFiles.Files[0].CompletedStages = hrt_LoadByte(5);
	SaveFiles.Files[0].StageOnMap = hrt_LoadByte(6);
	SaveFiles.Files[0].Lives = hrt_LoadByte(7);
	SaveFiles.Files[0].Health = hrt_LoadByte(8);
	
	SaveFiles.Files[1].Allocated = hrt_LoadByte(9);
	SaveFiles.Files[1].CompletedStages = hrt_LoadByte(10);
	SaveFiles.Files[1].StageOnMap = hrt_LoadByte(11);
	SaveFiles.Files[1].Lives = hrt_LoadByte(12);
	SaveFiles.Files[1].Health = hrt_LoadByte(13);
	
	SaveFiles.Files[2].Allocated =hrt_LoadByte(14);
	SaveFiles.Files[2].CompletedStages = hrt_LoadByte(15);
	SaveFiles.Files[2].StageOnMap = hrt_LoadByte(16);
	SaveFiles.Files[2].Lives = hrt_LoadByte(17);
	SaveFiles.Files[2].Health = hrt_LoadByte(18);
}