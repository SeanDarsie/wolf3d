#include "../wolf3d.h"

int check_dir(float dir)
{
  if (dir < 0)
    return (-1);
  else
    return (0);
}

void init_wall(t_graphic *info, t_wall *walla, float ang)
{
  walla->side = 20;
  walla->deltax = DELT_DIST_X(ang);
  walla->deltay = DELT_DIST_Y(ang);
  walla->dir_x = check_dir(cos(ang));
  walla->dir_y = check_dir(sin(ang));
  if (walla->dir_x < 0)
    walla->dist_to_x = ((info->you->x_pos -
			floor(info->you->x_pos)) *
			walla->deltax);
  else
    walla->dist_to_x = ((ceil(info->you->x_pos) - 
			 info->you->x_pos) *
			walla->deltax);
  if (walla->dir_y < 0)
    walla->dist_to_y = ((info->you->y_pos -
			 floor(info->you->y_pos)) *
			 walla->deltay);
  else
    walla->dist_to_y = ((ceil(info->you->y_pos) - 
			 info->you->y_pos) *
			 walla->deltay);
}

t_wall *wall(t_graphic *info, float ang)
{
  // float dist;
  t_wall *walla;

  walla = (t_wall*)malloc(sizeof(t_wall));
  walla->x = (int)floor(info->you->x_pos);
  walla->y = (int)floor(info->you->y_pos);
  walla->dist = 0;
  init_wall(info, walla, ang);
  while (info->map[walla->y][walla->x] != 1)
    {
      if (walla->dist_to_x > walla->dist_to_y)
	{
	  walla->dist_to_x += walla->deltax;
	  walla->x++;
	  walla->side = 0;
	}
      else
	{
	  walla->dist_to_y += walla->deltax;
	  walla->y++;
	  walla->side = 1;
	}
    }
  return (walla);
}
  
double  wall_distance(t_graphic *info, float ang)
{
  t_wall *get;
  float dist;

  dist = 10;
  get = wall(info, ang);
  if (get->side == 0)
    dist = (get->x - (int)info->you->x_pos + (1 - get->dir_x) / 2 ) / info->raydirx;
  else
    dist = (get->x - (int)info->you->x_pos + (1 - get->dir_y) / 2 ) / info->raydiry;
  /* if (get->side == 0) */
  /*   { */
  /*     dist = 0; */
  /*     printf("angle %f\n", ang); */
  /*   } */
  free(get);
  //dist *= .5;
  return (dist);
}

/* int main() */
/* { */
/*   t_graphic *test; */

/*   test = (t_graphic*)malloc(sizeof(t_graphic)); */
/*   initialize_info_struct(test); */
  
/* } */
