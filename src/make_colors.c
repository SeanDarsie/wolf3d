#include "../wolf3d.h"

void make_colors(uint32_t *color)
{
  color[0] = 0xADADAD; //floor;
  color[1] = 0x00FF00; //wall1
  color[2] = 0xD14242; //wall2
  color[3] = 0x4242FF; //wall3
  color[4] = 0xFFFFFF; //wall4
  color[5] = 0xFFFFFF;
  color[6] = 0xFF00FF;
  color[7] = 0xD8926E; //ceiling
}

int color_check(t_graphic *info, int x, int y)
{
  if (info->map[y][x] == 1)
    return (2);
  if (info->map[y][x] == 2)
    return(4);
  if (info->map[y][x] == 3)
    return (5);
  if (info->map[y][x] == 4)
    return (6);
  else
    return (2);
}
