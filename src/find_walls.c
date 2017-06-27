/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/26 23:35:49 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

double	angle_finder(double x, double y)
{
	double	angle;
	double	cosine;

	cosine = (x / (HYP(x, y)));
	angle = acos(cosine);
	return (angle);
}

double	wall_height(double distance)
{
	double	height;

	height = (WIND_H / distance);
	return (height);
}

void	assign_color(t_graphic *info, double dist, int x, int wall_color)
{
	int	i;
	int	code;
	int	wall_h;

	i = WIND_H - 1;
	wall_h = (int)wall_height(dist);
	code = 7;
	while (i >= 0)
	{
		if (i <= ((WIND_H / 2) + (wall_h / 2)) &&
				i >= ((WIND_H / 2) - (wall_h / 2)))
			info->addr[x] = info->color[wall_color] -
				0x424242 * info->c_inc;
		else
			info->addr[x] = info->color[code];
		if (i < (WIND_H / 2))
			code = 0;
		x += WIND_W;
		i--;
	}
}

void	begin(t_graphic *info)
{
	int		i;
	double	dist;

	i = 0;
	while (i < WIND_W)
	{
		info->camerax = ((2 * (double)i) / (double)WIND_W - 1);
		info->rayposx = info->posy;
		info->rayposy = info->posx;
		info->mapx = (int)(info->rayposx);
		info->mapy = (int)(info->rayposy);
		info->raydirx = info->dirx + (info->planex * info->camerax);
		info->raydiry = info->diry + (info->planey * info->camerax);
		dist = wall_distance(info);
		assign_color(info, dist, i, info->map[info->mapy][info->mapx]);
		i++;
	}
}
