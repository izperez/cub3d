/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:38:14 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:17:56 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_load_image(void *potato)
{
	t_data	*data;

	data = (t_data *)potato;
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	ft_drawcf(data);
	calculate_fov(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->mlx->img, 0, 0);
	return (0);
}

char	*ft_clean_path(char *oldpath)
{
	int		idx;
	int		idy;
	char	*newpath;

	if (ft_strlen(oldpath) < 4)
		return (NULL);
	newpath = (char *)malloc(4092 * sizeof(char));
	idx = 2;
	idy = 0;
	while (oldpath[idx] != '\n' && oldpath[idx])
	{
		while (oldpath[idx] == ' ' || oldpath[idx] == '\t')
			idx++;
		newpath[idy++] = oldpath[idx++];
	}
	newpath[idy] = '\0';
	return (newpath);
}

void	ft_textures_mlxinit(t_data **data)
{
	(*data)->n_texture = ft_setup_texture((*data)->asset->north_texture, \
		(*data)->mlx);
	(*data)->s_texture = ft_setup_texture((*data)->asset->south_texture, \
		(*data)->mlx);
	(*data)->w_texture = ft_setup_texture((*data)->asset->west_texture, \
		(*data)->mlx);
	(*data)->e_texture = ft_setup_texture((*data)->asset->east_texture, \
		(*data)->mlx);
}

int	ft_flood_fill(char **map, int w, int h)
{
	int		idx;
	int		idy;

	(void)w;
	flood_fill(map, h, 1, 1);
	idx = 0;
	while (map[idx])
	{
		idy = 0;
		while (map[idx][idy])
		{
			if (map[idx][idy] == '1' || map[idx][idy] == 'F')
				idy++;
			else
			{
				ft_free_split(map);
				return (0);
			}
		}
		idx++;
	}
	ft_free_split(map);
	return (1);
}

void	flood_fill(char **map, int h, int x, int y)
{
	if (map[x][y] != '0' && map[x][y] != 'N' && map[x][y] != 'S' \
		&& map[x][y] != 'E' && map[x][y] != 'W' && map[x][y] != ' ')
		return ;
	map[x][y] = 'F';
	flood_fill(map, h, x + 1, y);
	flood_fill(map, h, x - 1, y);
	flood_fill(map, h, x, y + 1);
	flood_fill(map, h, x, y - 1);
}
