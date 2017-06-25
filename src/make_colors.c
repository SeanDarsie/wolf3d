#include "../wolf3d.h"

void make_colors(uint32_t *color)
{
  color[0] = 0xADADAD; //floor;
  color[1] = 0x30FF42; //wall1
  color[2] = 0x3040FF; //wall2
  color[3] = 0x000000; //ceiling
}
