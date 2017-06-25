#include "../wolf3d.h"

int key_press_hook(int key_event, t_graphic *map)
{
  if (key_event == 53)
    exit(1);
  //key_event = 0;
  //  map->map_w = 1;
  // printf("%d\n", key_event);
  if (key_event == 126)
    {
      ft_bzero(map->addr, (WIND_H * WIND_H));
      map->you->x_pos += (cos(map->you->angle) / 2);
      map->you->y_pos += (sin(map->you->angle) / 2);
      begin(map);
      mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
      printf("x->%f y->%f\n", map->you->x_pos, map->you->y_pos);
    }
  if (key_event == 125)
    {
      ft_bzero(map->addr, (WIND_H * WIND_H));
      map->you->x_pos -= (cos(map->you->angle) / 2);
      map->you->y_pos -= (sin(map->you->angle) / 2);
      begin(map);
       mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
      printf("x->%f y->%f\n", map->you->x_pos, map->you->y_pos);
    }
  if (key_event == 123)
    {
      ft_bzero(map->addr, (WIND_H * WIND_H));
      map->you->angle += DEG_30;
      map->you->x_dir = cos(map->you->angle);
      map->you->y_dir = sin(map->you->angle);
      //map->you->y_pos -= sin(map->you->angle);
      begin(map);
      mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
    }
   if (key_event == 124)
    {
      ft_bzero(map->addr, (WIND_H * WIND_H));
      map->you->angle -= DEG_30;
      map->you->x_dir = cos(map->you->angle);
      map->you->y_dir = sin(map->you->angle);
      //map->you->y_pos -= sin(map->you->angle);
      begin(map);
      mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
    }
  /* if (key_event == 124) */
  /*   move_you_left(map); */
  /* if (key_event == 125) */
  /*   move_you_right(map); */
  return (0);
}

/* int  key_release_hook(t_graphic *map) */
/* { */
/*   //key_event = 0; */
/*   map->map_w = 1; */
/*   return (0); */
/* } */

/* int  mouse_press_hook(int click, int x, int y, t_graphic *map) */
/* { */
/*   click = 0; */
/*   map->map_w = 1; */
/*   x = 0; */
/*   y = 0; */
/*   if (click == 1) // and x and y are in the box at the top right) */
/*     exit(1); */
/*   return (0); */
/* } */


/* int  mouse_release_hook(t_graphic *map) */
/* { */
/*   return (0); */
/* } */


void	set_hooks(t_graphic *map)
{
	mlx_do_key_autorepeatoff(map->mlx);
	mlx_hook(map->wind, 2, 3, key_press_hook, map);
	//	mlx_hook(map->wind, 3, 0, key_release_hook, map);
	//	mlx_hook(map->wind, 4, 0, mouse_press_hook, map);
	//mlx_hook(map->wind, 5, 0, mouse_release_hook, map);
	//	mlx_hook(map->wind, 6, 0, motion_hook, map);
	//	mlx_hook(map->wind, 12, 0, expose_hook, map);
	mlx_hook(map->wind, 17, 0, exit_hook, map);
}
