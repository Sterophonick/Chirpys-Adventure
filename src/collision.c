#include <libheart.h>
#include "../inc/defs.h"
extern col collision;
extern map demolevel;
extern player bird;

void detectcollision() {
	collision.topl = l1_1colmap[bird.tiley-1][bird.tilex];
	collision.topr = l1_1colmap[bird.tiley-1][bird.tilex+1];
	collision.rightu = l1_1colmap[bird.tiley][bird.tilex+2];
	collision.rightd = l1_1colmap[bird.tiley+1][bird.tilex + 2];
	collision.bottomr = l1_1colmap[bird.tiley+2][bird.tilex+1];
	collision.bottoml = l1_1colmap[bird.tiley+2][bird.tilex];
	collision.leftu = l1_1colmap[bird.tiley][bird.tilex-1];
	collision.leftd = l1_1colmap[bird.tiley+1][bird.tilex-1];
}