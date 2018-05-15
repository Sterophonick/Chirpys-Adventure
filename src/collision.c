#include <libheart.h>
#include "../inc/defs.h"
extern col collision;
extern map demolevel;
extern player bird;

void detectcollsion() {
	collision.topl = demolevel.colmap[bird.tiley--][bird.tilex];
	collision.topr = demolevel.colmap[bird.tiley--][bird.tilex++];
	collision.rightu = demolevel.colmap[bird.tiley][bird.tilex+2];
	collision.rightd = demolevel.colmap[bird.tiley++][bird.tilex + 2];
	collision.bottomr = demolevel.colmap[bird.tiley+2][bird.tilex+1];
	collision.bottoml = demolevel.colmap[bird.tiley+2][bird.tilex];
	collision.leftu = demolevel.colmap[bird.tiley][bird.tilex-1];
	collision.leftd = demolevel.colmap[bird.tiley+1][bird.tilex-1];
}