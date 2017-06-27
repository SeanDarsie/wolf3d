/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_thru_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/26 23:30:34 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	traverse_map(t_graphic *info, double x, double y, double s)
{
	int		mapx;
	int		mapy;

	y /= 5;
	x /= 5;
	mapx = (int)(info->posx + (x * s));
	mapy = (int)(info->posy + (y * s));
	if (mapx < MAP_W && mapx > 0 && mapy > 0 && mapy < MAP_H &&
			info->map[mapx][mapy] < 1)
	{
		info->posx += (x * s);
		info->posy += (y * s);
	}
	begin(info);
}

void	rotate_view(t_graphic *info, double ang)
{
	double	oldx;
	double	oldplanex;

	ang = RAD(ang);
	oldx = info->dirx;
	oldplanex = info->planex;
	info->dirx = info->dirx * cos(ang) - info->diry * sin(ang);
	info->diry = oldx * sin(ang) + info->diry * cos(ang);
	info->planex = info->planex * cos(ang) - info->planey * sin(ang);
	info->planey = oldplanex * sin(ang) + info->planey * cos(ang);
}

double	angle_p90(t_graphic *info, char dir)
{
	double	angle;
	double ret;

	angle = atan(info->diry / info->dirx);
	angle += RAD(90);
	if (dir == 'y')
		ret = (sin(angle));
	if (dir == 'x')
		ret = (cos(angle));
	if (info->dirx > 0)
	  ret *= -1;
	return (ret);
}
