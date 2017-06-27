/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/27 11:53:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	make_colors(uint32_t *color)
{
	color[0] = 0x672A1D; //floor;
	color[1] = 0x42FF42; //wall1
	color[2] = 0xD14242; //wall2
	color[3] = 0x4242FF; //wall3
	color[4] = 0xFF4242; //wall4
	color[5] = 0xFFFFFF;
	color[6] = 0xFF00FF;
	color[7] = 0x1AB9FF; //ceiling
}

int		color_check(t_graphic *info, int x, int y)
{
	if (info->map[y][x] == 1)
		return (2);
	if (info->map[y][x] == 2)
		return (4);
	if (info->map[y][x] == 3)
		return (5);
	if (info->map[y][x] == 4)
		return (6);
	else
		return (2);
}

void	display_start_screen(t_graphic *info)
{
	char	*s;

	s = "Welcome To Wolf3D";
	mlx_string_put(info->mlx, info->wind, WIND_W / 3, WIND_H / 3, 0x5CC355, s);
	s = "Press ->RETURN<- to begin the game";
	mlx_string_put(info->mlx, info->wind,
			WIND_W / 5, WIND_H * 2 / 3, 0x5CC355, s);
	s = "A demo of the ray-casting technique used to simulate a 3D space";
	mlx_string_put(info->mlx, info->wind, WIND_W / 60, WIND_H / 2, 0x5CC355, s);
}

void	make_world3(t_graphic *info)
{
	int	x;
	int	y;
	int	wall_length;

	x = 0;
	y = 5;
	wall_length = MAP_W - 5;
	make_horiz(info, y, x, wall_length);
	make_vert(info, y, wall_length, wall_length);
	make_horiz(info, wall_length, 5, wall_length);
	make_vert(info, 10, 5, wall_length);
	make_horiz(info, 10, 5, wall_length - 10);
	make_vert(info, 10, wall_length - 10, wall_length - 5);
	make_horiz(info, wall_length - 5, 10, wall_length - 5);
}
