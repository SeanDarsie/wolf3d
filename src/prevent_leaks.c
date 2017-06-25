#include "../wolf3d.h"

void prevent_mem_leaks(t_world *map)
{
  t_world *tmp;

  tmp = map;
  while (map)
    {
      tmp = map;
      map = map->next;
      free(tmp);
      tmp = NULL;
    }
}
