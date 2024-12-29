/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_start_game.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:10 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 11:56:41 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit (0);
	}
	return (keycode);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	if ((x < 0 || x > data->mlx->width_window) \
	|| (y < 0 || y > data->mlx->height_window))
		return ;
	dst = data->mlx->img_addr + (y * data->mlx->size_line) \
	+ (x * (data->mlx->bit_per_pixel / 8));
	*(unsigned int *) dst = color;
}

int	ft_distance(int x, int y, t_pos *player)
{
	int	num;
	int	num2;

	num = (x - (player->x * TILE_SIZE)) * (x - (player->x * TILE_SIZE));
	num2 = (y - (player->y * TILE_SIZE)) * (y - (player->y * TILE_SIZE));
	return (sqrt(num + num2));
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
	int	p_x;
	int	p_y;

	p_x = data->playerpos->x * TILE_SIZE;
	p_y = data->playerpos->y * TILE_SIZE;
	y = 0;
	while (y < data->mlx->height_window)
	{
		x = 0;
		while (x < data->mlx->width_window)
		{
			if (sqrt((x - p_y) * (x - p_y) + (y - p_x) * (y - p_x)) <= 10)
			{
				my_mlx_pixel_put(data, x, y, ROJO);
			}
			x++;
		}
		y++;
	}
}

void	prepare_rays(t_data *data, float desf, int lenght)
{
	float	pos_x;
	float	pos_y;

	pos_x = data->playerpos->x * TILE_SIZE;
	pos_y = data->playerpos->y * TILE_SIZE;
	data->ray->angle = data->playerpos->dir + desf;
	draw_line(data, pos_x, pos_y, lenght);
}
