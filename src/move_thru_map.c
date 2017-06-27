#include "../wolf3d.h"

void traverse_map(t_graphic *info, double x, double y, double s)
{
  int mapx;
  int mapy;

  /* ft_bzero(info->addr, (WIND_W * WIND_H * 4)); */
  mapx = (int)(info->posx + (x * s));
  mapy = (int)(info->posy + (y * s));
  if (mapx < MAP_W && mapx > 0 && mapy > 0 && mapy < MAP_H &&
      info->map[mapx][mapy] < 1)
    {
      info->posx += (x * s);
      info->posy += (y * s);
    }
  begin(info);
}

void rotate_view(t_graphic *info, double ang)
{
  double oldx;
  double oldplanex;

  // ft_bzero(info->addr, 4 * WIND_H * WIND_W);
  ang = RAD(ang);
  oldx = info->dirx;
  oldplanex = info->planex;
  info->dirx = info->dirx * cos(ang) - info->diry * sin(ang);
  
  info->diry = oldx * sin(ang) + info->diry * cos(ang);
  
  info->planex = info->planex * cos(ang) - info->planey * sin(ang);
  
  info->planey = oldplanex * sin(ang) + info->planey * cos(ang);
  // printf("planey %f\tplanex%f\n", info->planey, info->planex);
}

double angle_p90(t_graphic *info, char dir)
{
  double angle;
  
  angle = atan(info->diry / info->dirx);
  angle += RAD(90);
  if (dir == 'y')
    return (sin(angle));
  if (dir == 'x')
    return (cos(angle));
  return (0);
}
