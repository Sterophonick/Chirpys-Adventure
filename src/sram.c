#include <libheart.h>
#include "main.h"
#include "chirpy.h"
#include "sram.h"
sram saves;

void Save()
{
	hrt_DMACopy(0, &saves, SRAM, 19, 0x80000000);
}

void Load()
{
	hrt_DMACopy(0, SRAM, &saves, 19, 0x80000000);
}