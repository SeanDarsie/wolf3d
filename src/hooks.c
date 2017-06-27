/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sdarsie <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/26 19:46:54 by sdarsie           #+#    #+#             */
/*   Updated: 2017/06/27 11:24:21 by sdarsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../wolf3d.h"

int		key2(int key_event, t_graphic *map)
{
	if (key_event == 2)
		traverse_map(map, angle_p90(map, 'y'), angle_p90(map, 'x'), 1);
	if (key_event == 36)
		begin(map);
	if (key_event == 0)
		traverse_map(map, angle_p90(map, 'y'), angle_p90(map, 'x'), -1);
	if (key_event == 126)
		traverse_map(map, map->diry, map->dirx, 1);
	if (key_event == 125)
		traverse_map(map, map->diry, map->dirx, -1);
	if (key_event == 123)
	{
		ft_bzero(map->addr, (WIND_W * WIND_H * 4));
		rotate_view(map, 5);
		begin(map);
	}
	return (0);
}

int		key_press_hook(int key_event, t_graphic *map)
{
	if (key_event == 53)
	{
		free(map);
		map = NULL;
		exit(0);
	}
	if (key_event == 124)
	{
		ft_bzero(map->addr, (WIND_W * WIND_H * 4));
		rotate_view(map, -5);
		begin(map);
	}
	if (key_event == 49)
		ft_bzero(map->addr, WIND_W * WIND_H * 4);
	key2(key_event, map);
	mlx_put_image_to_window(map->mlx, map->wind, map->img, 0, 0);
	if (key_event == 36)
		mlx_string_put(map->mlx, map->wind, WIND_W / 4, WIND_H / 2,
				0xFF4242, "TURN AROUND. move with arrows");
	return (0);
}

int		exit_hook(t_graphic *map)
{
	mlx_destroy_window(map->mlx, map->wind);
	free(map);
	map = NULL;
	exit(0);
	return (0);
}

void	set_hooks(t_graphic *map)
{
	mlx_hook(map->wind, 2, 3, key_press_hook, map);
	mlx_hook(map->wind, 17, 0, exit_hook, map);
}
