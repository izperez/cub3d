/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:51 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/29 11:42:29 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_press_aux(t_data *data, double move_x, double move_y, int mode)
{
	t_pos	*player;
	float	tmp_x;
	float	tmp_y;

	player = data->playerpos;
	if (mode == 1)
	{
		tmp_x = player->x - (move_x * 0.1);
		tmp_y = player->y - (move_y * 0.1);
	}
	else
	{
		tmp_x = player->x + (move_x * 0.1);
		tmp_y = player->y + (move_y * 0.1);
	}
	if (ft_isinmap(data->map, tmp_y + 0.01, tmp_x) == 1 && \
		ft_isinmap(data->map, tmp_y - 0.01, tmp_x) == 1 && \
		ft_isinmap(data->map, tmp_y, tmp_x + 0.01) == 1 && \
		ft_isinmap(data->map, tmp_y, tmp_x - 0.01) == 1)
	{
		player->x = tmp_x;
		player->y = tmp_y;
	}
	data->playerpos = player;
}

int	ft_isinmap(t_map *map, float x, float y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map->grid[map_x][map_y] == '1')
		return (0);
	return (1);
}

static void	ft_hooks_utils(int keycode, t_data *data)
{
	double	move_x;
	double	move_y;

	if (keycode == D)
	{
		move_x = cos(data->playerpos->dir);
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 2);
	}
	else if (keycode == A)
	{
		move_x = cos(data->playerpos->dir);
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 1);
	}
}

int	ft_hooks(int keycode, t_data *data)
{
	double	move_x;
	double	move_y;

	if (keycode == S)
	{
		move_x = cos(data->playerpos->dir + PI / 2);
		move_y = sin(data->playerpos->dir + PI / 2);
		key_press_aux(data, move_x, move_y, 1);
	}
	else if (keycode == W)
	{
		move_x = cos(data->playerpos->dir - PI / 2);
		move_y = sin(data->playerpos->dir - PI / 2);
		key_press_aux(data, move_x, move_y, 1);
	}
	else if (keycode == D || keycode == A)
		ft_hooks_utils(keycode, data);
	else
		ft_rotation(keycode, data);
	return (keycode);
}

int	ft_rotation(int keycode, t_data *data)
{
	float	angle;

	angle = data->playerpos->dir;
	if (keycode == RIGHT)
		angle -= 0.065;
	else if (keycode == LEFT)
		angle += 0.065;
	data->playerpos->dir = angle;
	return (keycode);
}
