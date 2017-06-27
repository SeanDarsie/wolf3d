/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/26 23:48:00 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

void	makeworld(t_graphic *info)
{
	uint32_t	y;
	uint32_t	x;

	y = 0;
	while (y <= MAP_H)
	{
		x = 0;
		while (x <= MAP_W)
		{
			if (y == 0 || y == MAP_H || x == 0 || x == MAP_W)
				info->map[y][x] = 1;
			else
				info->map[y][x] = 0;
			x++;
		}
		y++;
	}
}
