/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/26 23:47:18 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	make_horiz(t_graphic *info, int starty, int startx, int endx)
{
	int	y;
	int	x;

	y = starty;
	x = startx;
	while (y <= starty + 1)
	{
		x = startx;
		while (x <= endx)
		{
			info->map[y][x] = 4;
			x++;
		}
		y++;
	}
}

void	make_vert(t_graphic *info, int starty, int startx, int endy)
{
	int	y;
	int	x;

	y = starty;
	x = startx;
	while (x <= startx + 1)
	{
		y = starty;
		while (y <= endy)
		{
			info->map[y][x] = 3;
			y++;
		}
		x++;
	}
}

void	make_diag(t_graphic *info, int starty, int startx, int endy)
{
	int	y;
	int	x;
	int	endx;
	int	incx;
	int	incy;

	endx = startx + (endy - starty);
	incy = 1;
	incx = 1;
	if (startx > endx)
		incx = -1;
	if (starty > endy)
		incy = -1;
	y = starty;
	x = startx;
	while (x < endx)
	{
		make_horiz(info, y, x, y + incx);
		y += incy;
		x += incx;
	}
}

void	make_cool_map(t_graphic *info)
{
	int	x;
	int	y;

	y = 4;
	while (y < MAP_H)
	{
		x = 4;
		while (x < MAP_W)
		{
			make_horiz(info, y, x, x + 2);
			x += 5;
		}
		y += 5;
	}
}

void	map2(t_graphic *info)
{
	make_vert(info, 1, 5, MAP_H / 4);
	make_horiz(info, (MAP_H / 4) + 5, 1, MAP_W / 2);
	make_vert(info, 5, 13, MAP_H / 2);
	make_horiz(info, (MAP_H / 2), (MAP_W / 2) + 5, MAP_W);
	make_vert(info, (MAP_H / 2), (MAP_W / 2) + 1, (MAP_H * 4) / 5);
	make_horiz(info, (MAP_H * 4) / 5, (MAP_W / 2) + 1, (MAP_W - 4));
	make_horiz(info, (MAP_H * 4) / 5, (MAP_W / 10) + 1, (MAP_W / 3));
	make_vert(info, (MAP_H * 4 / 5) - 2,
			(MAP_W / 10) + 3, (MAP_H * 9 / 10) + 1);
}
