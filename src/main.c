#include "../wolf3d.h"

/* void define_the_map(t_graphic *info) */
/* { */
  
/* } */

void initialize_player(t_graphic *info)
{
  info->you->y = (WIND_H / 2);
  info->you->x = (WIND_W / 2);
  info->you->x_pos = 3;
  info->you->y_pos = 3;
  info->you->x_dir = 1;
  info->you->y_dir = 0;
  info->you->angle = angle_finder(info->you->y_dir, info->you->x_dir);
  printf("angle init %f\n", info->you->angle * (180 / M_PI));
}

void initialize_info_struct(t_graphic *info)
{
  //t_world *world;
  info->camerax = 0;
  info->planex = 0;
  info->planey = 0.66;
  info->color = (uint32_t*)malloc(sizeof(uint32_t) * 5);
  info->you = (t_person*)malloc(sizeof(t_person));
  // world->next = NULL;
  info->mlx = mlx_init();
  info->wind = mlx_new_window(info->mlx, WIND_W, WIND_H, "woof3d");
  info->img = mlx_new_image(info->mlx, WIND_W, WIND_H);
  info->addr = (unsigned int*)mlx_get_data_addr(info->img, &info->bpp,
			&info->size_l, &info->endian);
  make_colors(info->color);
  initialize_player(info);
  info->map_w = 24;
  info->map_h = 24;
  set_hooks(info);
  
  /* world->z = 64; */
  /* world->x = 0; */
  /* world->y = 0; */
  makeworld(info);
  int i, k;
  i = 0;
  k = 0;
  while (i <= IMG_H)
    {
      k = 0;
      while (k <= IMG_W)
  	{
  	  printf("%u", info->map[i][k]);
  	  k++;
  	}
      printf("\n");
      i++;
    }
  // worldmaker(world);
  //  traverse_map(info, world);
  //prevent_mem_leaks(world);
}

int main(void)
{
  t_graphic *info;

  info = (t_graphic*)malloc(sizeof(t_graphic));
  initialize_info_struct(info);
  begin(info);
  mlx_put_image_to_window(info->mlx, info->wind, info->img, 0, 0);
  set_hooks(info);
  mlx_loop(info->mlx);
  free(info);
  return (0);
}
