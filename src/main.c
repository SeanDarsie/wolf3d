#include "../wolf3d.h"

/* void define_the_map(t_graphic *info) */
/* { */
  
/* } */

void initialize_player(t_graphic *info)
{
  info->posx = 2;
  info->posy = 2;
  info->dirx = -1;
  info->diry = 0;
  info->planex = 0;
  info->planey = 0.66;
  info->mapx = 0;
  info->mapy = 0;
}

void display_map(t_graphic *info)
{
  int i;
  int k;
  
  k = 0;
  i = 0;
  while (k <= MAP_H)
    {
      i = 0;
      while (i <= MAP_W)
	{
	  ft_putnbr(info->map[k][i]);
	  ft_putchar(' ');
	  i++;
	}
      ft_putchar('\n');
      k++;
    }
}
void initialize_info_struct(t_graphic *info)
{
  initialize_player(info);
  info->camerax = 0;
  info->c_inc = 2;
  info->planex = 0;
  info->color = (uint32_t*)malloc(sizeof(uint32_t) * 8);
  info->mlx = mlx_init();
  info->wind = mlx_new_window(info->mlx, WIND_W, WIND_H, "woof3d");
  info->img = mlx_new_image(info->mlx, WIND_W, WIND_H);
  info->addr = (unsigned int*)mlx_get_data_addr(info->img, &info->bpp,
			&info->size_l, &info->endian);
  make_colors(info->color);
  //  makeworld2(info);
  makeworld(info);
  map2(info);
  // make_cool_map(info);
  display_map(info);
  //makeworld3(info);
  //make_42_world(info);
}

int main(int ac, char **av)
{
  t_graphic *info;

  if (ac != 2)
    {
      ft_putstr("Please specify 1 map\nValid options: 1, 2, 3\n");
      exit(1);
    }
  av = NULL;
  info = (t_graphic*)malloc(sizeof(t_graphic));
  initialize_info_struct(info);
  set_hooks(info);
  begin(info);
  mlx_put_image_to_window(info->mlx, info->wind, info->img, 0, 0);
  mlx_do_key_autorepeatoff(info->mlx);

  mlx_loop(info->mlx);
  free(info);
  return (0);
}
