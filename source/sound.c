#include <libheart.h>
#include "game.h"
#include "interrupt.h"
#include "lang.h"
#include "menus.h"
#include "animations.h"
#include "data.h"

mm_sound_effect gDebugConfirm;
mm_sound_effect gDebugUnlock;
mm_sound_effect gElevatorRun;
mm_sound_effect gElevatorStart;
mm_sound_effect gElevatorStop;
mm_sound_effect gEnemyCralenStop;
mm_sound_effect gMainGameKeyCollect;
mm_sound_effect gMainGamePause;
mm_sound_effect gMenuConfirm;
mm_sound_effect gMenuEnterStage;
mm_sound_effect gMenuLevelComplete;
mm_sound_effect gMenuLoadSave;
mm_sound_effect gMenuNo;
mm_sound_effect gMenuSaveGame;
mm_sound_effect gMenuSelect;
mm_sound_effect gMenuTestVolume;
mm_sound_effect gMenuMapMove;
mm_sound_effect gPlayerDeath;
mm_sound_effect gPlayerHurt;
mm_sound_effect gPlayerJump;
mm_sound_effect gPlayerLandGrass;
mm_sound_effect gPlayerLandStone;
mm_sound_effect gPlayerShoot;
mm_sound_effect gStoryPage;
mm_sound_effect gUnkSelect;
mm_sound_effect gUnkClock;
mm_sound_effect gUnkClockReverb;

void initSoundEffects()
{
	mmConfigDynamicEffect(gDebugConfirm, SFX_DBG_SELECT, (int)(1.0f * (1 << 10)), 1, 128, 0);
	mmConfigDynamicEffect(gDebugUnlock, SFX_DBG_UNLOCK, (int)(1.0f * (1 << 10)), 1, 128, 0);
	mmConfigDynamicEffect(gElevatorRun, SFX_ELVTR_RUN, (int)(1.0f * (1 << 10)), 1, 128, 0);
	mmConfigDynamicEffect(gElevatorStart, SFX_ELVTR_START, (int)(1.0f * (1 << 10)), 1, 128, 0);
	mmConfigDynamicEffect(gElevatorStop, SFX_ELVTR_STOP, (int)(1.0f * (1 << 10)), 1, 128, 0);
}