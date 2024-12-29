/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   06_render_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:50:32 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:18:48 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_square_utils(t_data *data, int d_x, int d_y, int color)
{
	int	x;
	int	y;

	y = 0;
	while (y < TILE_SIZE)
	{
		x = 0;
		while (x < TILE_SIZE)
		{
			if (x == 0 || x == TILE_SIZE - 1 || y == 0 || y == TILE_SIZE - 1)
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE,
					y + d_y * TILE_SIZE, NEGRO);
			else
				my_mlx_pixel_put(data, x + d_x * TILE_SIZE,
					y + d_y * TILE_SIZE, color);
			x++;
		}
		y++;
	}
}

void	draw_square(t_data *data, char c, int d_x, int d_y)
{
	int	color;

	if (c == '1')
		color = GRIS;
	else if (c == '0')
		color = BLANCO;
	else if (c == 'N' || c == 'S' || c == 'E' || c == 'O')
		color = BLANCO;
	else
		color = NEGRO;
	draw_square_utils(data, d_x, d_y, color);
}

void	calculate_fov(t_data *data)
{
	float	start_des;
	float	end_des;
	int		i;
	float	j;

	i = 0;
	start_des = 35 * (PI / 180.0) + (PI / 2);
	end_des = -35 * (PI / 180.0) + (PI / 2);
	j = (start_des - end_des) / data->mlx->width_window;
	while (start_des >= end_des)
	{
		prepare_rays(data, start_des, 5000);
		start_des -= j;
		i++;
	}
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
}

static void	draw_line_aux(t_data *data)
{
	if (((ft_distance(data->ray->x_current, data->ray->y_current, \
			data->playerpos)) / cos(data->ray->angle * (PI / 360))) == 0)
		return ;
	data->ray->dist_wall = ((TILE_SIZE * data->mlx->height_window)
			/ (ft_distance(data->ray->x_current, data->ray->y_current,
					data->playerpos)) / cos(data->ray->angle * (PI / 360))) / 2;
}

void	draw_line(t_data *data, float x_start, float y_start, float steps)
{
	float	x_end;
	float	y_end;
	int		i;
	float	t;

	i = 0;
	x_end = x_start + steps * cos(data->ray->angle);
	y_end = y_start + steps * sin(data->ray->angle);
	while (i++ < steps)
	{
		t = (float)i / (float)steps;
		data->ray->x_current = (int)(x_start + t * (x_end - x_start));
		data->ray->y_current = (int)(y_start + t * (y_end - y_start));
		if (ft_knock(data) == 1)
			break ;
	}
	draw_line_aux(data);
	draw_colum(data);
}
