#include <libheart.h>
#include "..\inc\defs.h"
extern GameMap gGameMap;

void MapLayerDrawStripH(int layerIdx, int srcY)   // srcY is in 8x8 tiles (even though source map tiles are 16x16) 
{
	int i;
	const MapLayer *layer = &gGameMap.layer[layerIdx];
	const u16 *src = layer->map + (srcY >> 1) * gGameMap.dimensions.x;
	u16 *dest = BG_SCRN_VRAM(28 + layerIdx) + (srcY & 31) * 32;
	const int scrollXChar = fptochar(layer->scroll.x);
	const int yOffset = ((srcY & 1) << 1);
	for (i = 0; i < 32; i++)
	{
		const int xOffset = ((scrollXChar + i) & 1);
		const u16 tile = src[(scrollXChar + i) >> 1];
		dest[(scrollXChar + i) & 31] = gGameMap.tileset[(tile << 2) + xOffset + yOffset];
	}
}

void MapLayerDrawStripV(int layerIdx, int srcX)
{
	int i;
	const MapLayer *layer = &gGameMap.layer[layerIdx];
	const u16 *src = layer->map + (srcX >> 1);
	u16 *dest = BG_SCRN_VRAM(28 + layerIdx) + (srcX & 31);
	const int scrollYChar = fptochar(layer->scroll.y);
	const int xOffset = (srcX & 1);
	for (i = 0; i < 32; i++)
	{
		const int yOffset = ((scrollYChar + i) & 1) << 1;
		const u16 tile = src[((scrollYChar + i) >> 1) * gGameMap.dimensions.x];
		dest[((scrollYChar + i) & 31) * 32] = gGameMap.tileset[(tile << 2) + xOffset + yOffset];
	}
}