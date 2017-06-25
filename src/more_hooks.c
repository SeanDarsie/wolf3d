#include "../wolf3d.h"

int  motion_hook(t_graphic *map)
{
  // key_event = 0;
  map->map_w = 1;
  return (0);
}


int  exit_hook(t_graphic *map)
{
  // key_event = 0;
  map->map_w = 1;
  return (0);
}
