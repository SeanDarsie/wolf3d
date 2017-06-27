/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/26 23:45:14 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		check_dir(float dir)
{
	if (dir < 0)
		return (-1);
	else if (dir == 0)
		return (0);
	else
		return (1);
}

void	init_wall(t_graphic *info, t_wall *walla)
{
	walla->deltax = sqrt(1 + (pow(info->raydiry, 2) / pow(info->raydirx, 2)));
	walla->deltay = sqrt(1 + (pow(info->raydirx, 2) / pow(info->raydiry, 2)));
	walla->dir_x = check_dir(info->raydirx);
	walla->dir_y = check_dir(info->raydiry);
	if (walla->dir_x < 0)
		walla->dist_to_x = (info->rayposx - info->mapx) *
			walla->deltax;
	else
		walla->dist_to_x = (info->mapx + 1 - info->rayposx) *
			walla->deltax;
	if (walla->dir_y < 0)
		walla->dist_to_y = (info->rayposy - info->mapy) *
			walla->deltay;
	else
		walla->dist_to_y = (info->mapy + 1 - info->rayposy) *
			walla->deltay;
}

t_wall	*wall(t_graphic *info)
{
	t_wall	*walla;

	walla = (t_wall*)malloc(sizeof(t_wall));
	walla->side = 2;
	init_wall(info, walla);
	while (info->map[info->mapy][info->mapx] < 1 &&
			info->mapx < MAP_W && info->mapy < MAP_H &&
			info->mapx >= 0 && info->mapy >= 0)
	{
		if (walla->dist_to_x < walla->dist_to_y)
		{
			walla->dist_to_x += walla->deltax;
			info->mapx += walla->dir_x;
			walla->side = 0;
		}
		else
		{
			walla->dist_to_y += walla->deltay;
			info->mapy += walla->dir_y;
			walla->side = 1;
		}
	}
	info->c_inc = color_check(info, info->mapx, info->mapy);
	return (walla);
}

double	wall_distance(t_graphic *info)
{
	t_wall	*get;
	double	dist;

	dist = 10;
	get = wall(info);
	if (get->side == 0)
	{
		dist = (info->mapx - info->rayposx +
				(1 - get->dir_x) / 2) / info->raydirx;
		info->c_inc = 0;
	}
	else
	{
		dist = (info->mapy - info->rayposy +
				(1 - get->dir_y) / 2) / info->raydiry;
		info->c_inc = 1;
	}
	free(get);
	return ((dist));
}
