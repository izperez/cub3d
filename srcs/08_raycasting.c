/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   08_raycasting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:51:08 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 11:27:01 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	draw_colum_aux(t_data *data, int x, int y)
{
	int	flag;
	int	local_coord;
	int	start;
	int	end;
	int	color;

	start = (data->mlx->height_window / 2) - data->ray->dist_wall;
	end = (data->mlx->height_window / 2) + data->ray->dist_wall;
	if (y >= start && y <= end)
	{
		data->ray->y_text = (y - start) * 500 / (end - start);
		flag = ft_north_south(data->ray->x_current, data->ray->y_current);
		if (flag)
			local_coord = data->ray->y_current % TILE_SIZE;
		else
			local_coord = data->ray->x_current % TILE_SIZE;
		data->ray->x_text = local_coord * 500 / TILE_SIZE;
		color = ft_texture_color(data);
		my_mlx_pixel_put(data, x, y, color);
	}
}

void	draw_colum(t_data *data)
{
	static int	x;
	int			y;

	y = 0;
	if (x == data->mlx->width_window)
		x = 0;
	while (y <= data->mlx->height_window)
	{
		draw_colum_aux(data, x, y);
		y++;
	}
	x++;
}

void	ft_drawcf(t_data *data)
{
	int	x;
	int	y;
	int	horizonte;

	horizonte = data->mlx->height_window / 2;
	y = 0;
	while (y <= data->mlx->height_window)
	{
		x = 0;
		while (x <= data->mlx->width_window)
		{
			if (y <= horizonte)
				my_mlx_pixel_put(data, x, y, data->asset->cieling_rgb);
			else
				my_mlx_pixel_put(data, x, y, data->asset->floor_rgb);
			x++;
		}
		y++;
	}
}

int	ft_north_south(int x, int y)
{
	int	color;

	color = 0;
	if ((x % TILE_SIZE == 0 || (x + 1) % TILE_SIZE == 0) && \
		(y % TILE_SIZE == 0 || (y + 1) % TILE_SIZE == 0))
		color = 0;
	else if ((y % TILE_SIZE) == 0)
		color = 0;
	else if ((x % TILE_SIZE) == 0)
		color = 1;
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = 1;
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = 0;
	else
		color = 0;
	return (color);
}
