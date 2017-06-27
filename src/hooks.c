#include "../wolf3d.h"
 /* double oldDirX = dirX; */
 /*      dirX = dirX * cos(-rotSpeed) - dirY * sin(-rotSpeed); */
 /*      dirY = oldDirX * sin(-rotSpeed) + dirY * cos(-rotSpeed); */
 /*      double oldPlaneX = planeX; */
 /*      planeX = planeX * cos(-rotSpeed) - planeY * sin(-rotSpeed); */
 /*      planeY = oldPlaneX * sin(-rotSpeed) + planeY * cos(-rotSpeed); */

int key_press_hook(int key_event, t_graphic *map)
{
  // ft_bzero(map->addr, (WIND_W * WIND_H * 4));
  if (key_event == 53)
    {
      free(map);
      map = NULL;
      exit(1);
    }
  printf("%d\n", key_event);
  if (key_event == 2)
    traverse_map(map, angle_p90(map, 'y'), angle_p90(map, 'x'), 1);
  if (key_event == 0)
    traverse_map(map, angle_p90(map, 'y'), angle_p90(map, 'x'), -1);
  if (key_event == 126)
      traverse_map(map, map->diry, map->dirx, 1);
  if (key_event == 125)
      traverse_map(map, map->diry, map->dirx, -1);
  if (key_event == 123)
    {
      ft_bzero(map->addr, (WIND_W * WIND_H * 4));
      rotate_view(map, 15);
      // map->you->angle += RAD(15);
      //if (map->you->angle > 2 * M_PI)
      //	map->you->angle -= RAD(360);
      //map->you->x_dir = cos(RAD(15)) ;
      //map->you->y_dir = sin(map->you->angle);
      //map->you->y_pos -= sin(map->you->angle);
      begin(map);
      // mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
    }
   if (key_event == 124)
    {
      ft_bzero(map->addr, (WIND_W * WIND_H * 4));
      rotate_view(map, -15);
      /* map->you->angle -= RAD(15); */
      /* if (map->you->angle < 0) */
      /* 	map->you->angle += RAD(360);    */
      /* map->you->x_dir = cos(map->you->angle); */
      /* map->you->y_dir = sin(map->you->angle); */
      //map->you->y_pos -= sin(map->you->angle);
      begin(map);
      //mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
    }
   if (key_event == 49)
     ft_bzero(map->addr, WIND_W * WIND_H * 4);
   mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
   printf("dirx %f, diry %f x->%f y->%f\n", map->dirx, map->diry,  map->posx, map->posy);
   
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
