/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 23:15:46 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/27 10:58:33 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF3D_H
# define WOLF3D_H
# include "libft/libft.h"
# include "minilibx_macos/mlx.h"
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# define RAD(x) (M_PI / 180) * x
# define MAP_H 32
# define MAP_W 32
# define WIND_W 640
# define WIND_H 512
# define HYP(x, y) sqrt(pow(x, 2) + pow(y, 2))
# define DEG_30 M_PI/6
# define REAL_DIST(x, dist) (cos(x) * dist)
# define FLOAT_REM(x) ceil(x) - x
# define DELT_DIST_X(a) sqrt(1 + (pow(sin(a), 2)) / (pow(cos(a), 2)))
# define DELT_DIST_Y(a) sqrt(1 + (pow(cos(a), 2)) / (pow(sin(a), 2)))

typedef struct	s_wall
{
	double	deltax;
	double	deltay;
	double	dist_to_y;
	double	dist_to_x;
	double	dist;
	int		x;
	int		y;
	int		dir_x;
	int		dir_y;
	int		side;
}				t_wall;

typedef struct	s_graphic
{
	void		*mlx;
	void		*wind;
	void		*img;
	int			map_w;
	int			map_h;
	uint32_t	*addr;
	int			size_l;
	int			bpp;
	int			endian;
	int			c_inc;
	uint32_t	*color;
	uint32_t	map[MAP_W + 1][MAP_H + 1];
	int			mapx;
	int			mapy;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		rayposx;
	double		rayposy;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	double		camerax;
}				t_graphic;

void			display_start_screen(t_graphic *info);
void			initialize_player(t_graphic *info);
double			angle_finder(double x, double y);
void			make_colors(uint32_t *color);
int				color_check(t_graphic *info, int x, int y);
void			begin(t_graphic *info);
double			wall_distance(t_graphic *info);
void			traverse_map(t_graphic *info, double x, double y, double s);
void			rotate_view(t_graphic *info, double ang);
double			angle_p90(t_graphic *info, char dir);

void			makeworld(t_graphic *info);
void			makeworld2(t_graphic *info);
void			make_world3(t_graphic *info);
void			make_42_world(t_graphic *info);
void			make_cool_map(t_graphic *info);
void			map2(t_graphic *info);

void			make_horiz(t_graphic *info, int starty, int startx, int endx);
void			make_vert(t_graphic *info, int starty, int startx, int endy);
void			make_diag(t_graphic *info, int starty, int startx, int endy);

void			set_hooks(t_graphic *map);
int				key_press_hook(int key_event, t_graphic *map);
int				key_release_hook(t_graphic *map);
int				mouse_press_hook(int click, int x, int y, t_graphic *map);
int				mouse_release_hook(t_graphic *map);
int				motion_hook(t_graphic *map);
int				exit_hook(t_graphic *map);
void                          carlos_map(t_graphic *info);


#endif
