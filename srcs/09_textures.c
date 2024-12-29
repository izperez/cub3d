/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   09_textures.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:51:25 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 11:47:44 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_texture_color(t_data *data)
{
	int	color;
	int	x;
	int	y;
	int	x_text;
	int	y_text;

	color = BLANCO;
	x = data->ray->x_current;
	y = data->ray->y_current;
	x_text = data->ray->x_text;
	y_text = data->ray->y_text;
	if ((x % TILE_SIZE == 0 || (x + 1) % TILE_SIZE == 0) \
		&& (y % TILE_SIZE == 0 || (y + 1) % TILE_SIZE == 0))
		color = NEGRO;
	else if ((y % TILE_SIZE) == 0)
		color = ft_textures_color_ext(x_text, y_text, data->e_texture);
	else if ((x % TILE_SIZE) == 0)
		color = ft_textures_color_ext(x_text, y_text, data->s_texture);
	else if (((x + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_color_ext(x_text, y_text, data->n_texture);
	else if (((y + 1) % (TILE_SIZE)) == 0)
		color = ft_textures_color_ext(x_text, y_text, data->w_texture);
	else
		color = MORADO;
	return (color);
}

int	ft_textures_color_ext(int x_text, int y_text, t_image_info *data)
{
	char	*pixel;
	int		color;

	pixel = data->address + (y_text * data->line_s) \
		+ (x_text * (data->bpp / 8));
	if (data->endian == 0)
		color = *(unsigned int *)pixel;
	else
		color = ((unsigned char)pixel[2] << 16) | \
				((unsigned char)pixel[1] << 8) | \
				((unsigned char)pixel[0]);
	return (color);
}

int	ft_transform_rgb(int red, int green, int blue)
{
	int	rgb;

	rgb = (red << 16) | (green << 8) | blue;
	return (rgb);
}

int	ft_knock(t_data *data)
{
	int	x_index;
	int	y_index;

	x_index = (int)(data->ray->x_current / TILE_SIZE);
	y_index = (int)(data->ray->y_current / TILE_SIZE);
	if (x_index < 0 || x_index >= data->map->width || \
		y_index < 0 || y_index >= data->map->height)
		return (1);
	if (data->map->grid[y_index][x_index] == '1')
		return (1);
	if (data->map->grid[y_index][x_index] == ' ')
		return (1);
	return (0);
}

char	**ft_map_copy(char **map)
{
	char	**newmap;
	int		id;

	id = 0;
	newmap = malloc(sizeof(char **) * 42);
	while (map[id])
	{
		newmap[id] = ft_strdup(map[id]);
		id++;
	}
	newmap[id] = NULL;
	return (newmap);
}
