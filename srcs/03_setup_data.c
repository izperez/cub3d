/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:55:28 by adrian            #+#    #+#             */
/*   Updated: 2024/12/11 12:47:11 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*ft_setup_data(t_checks *checker)
{
	t_data	*voidata;

	voidata = malloc(sizeof(t_data));
	voidata->map = ft_clean_map(checker->map);
	voidata->asset = ft_setup_assets(checker);
	voidata->playerpos = ft_playerpos(checker->map);
	voidata->mlx = ft_mlx_init(voidata->map);
	return (voidata);
}

/* t_image_info	*ft_setup_textures(void)
{
	t_image_info *new;

	new = malloc(sizeof(t_image_info));
	new->address = NULL;
	new->bpp = 0;
	new->endian = 0;
	new->image_charge = NULL;
	new->line_s = 0;
	return (new);
} */

t_pos	*ft_playerpos(char **map)
{
	int		idx;
	int		idy;
	t_pos	*position;

	position = malloc(sizeof(t_pos));
	idx = 0;
	idy = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N' || map[idx][idy] == 'S' || map[idx][idy] == 'W' || map[idx][idy] == 'E')
			{
				position->x = idx + 0.5;
				position->y = idy + 0.5;
			}
			idy++;
		}
		idy = 0;
		idx++;
	}
	position->dir = ft_posdir(map);
	return (position);
}

t_mlx	*ft_mlx_init(t_map *map)
{
	t_mlx	*new;

	(void)map;
	new = (t_mlx *)malloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, 30 * WINDOW_RATIO, 10 * WINDOW_RATIO, "cub3d no payo");
	// new->win = mlx_new_window(new->mlx, map->width * 100, map->height * 100, "cubed");
	new->img =  mlx_new_image(new->mlx, 30 * WINDOW_RATIO, 10 * WINDOW_RATIO);
	if (new->img == NULL)
		printf("la img ta null\n");
	new->img_addr = mlx_get_data_addr(new->img, &new->bit_per_pixel, &new->size_line, &new->endian);
	new->width_window = 30 * WINDOW_RATIO;
	new->height_window = 10 * WINDOW_RATIO;
	return (new);
}

t_asset	*ft_setup_assets(t_checks *checker)
{
	t_asset	*new;

	new = malloc(sizeof(t_asset));
	new->north_texture = ft_strdup(checker->north_texture);
	new->south_texture = ft_strdup(checker->south_texture);
	new->west_texture = ft_strdup(checker->west_texture);
	new->east_texture = ft_strdup(checker->east_texture);
	new->cieling_rgb = ft_transform_rgb(checker->c_red, checker->c_green, checker->c_blue);
	new->floor_rgb = ft_transform_rgb(checker->f_red, checker->f_green, checker->f_blue);
	return (new);
}

int	ft_transform_rgb(int red, int green, int blue)
{
	int	rgb;

	rgb = (red << 16) | (green << 8) | blue;
	return (rgb);
}

t_image_info	*ft_setup_texture(char *path, t_mlx *mlx)
{
	t_image_info *new;
	
	new = malloc(sizeof(t_image_info));
	if (!new)
		return (NULL);
	int	temp_width = 0;
	new->image_charge = mlx_xpm_file_to_image(mlx->mlx, path, &temp_width, &(new->line_s));
	if (new->image_charge)
		new->created = 1;
	new->address = mlx_get_data_addr(new->image_charge, &(new->bpp), &(new->line_s), &(new->endian));
	free(path);
	printf("address %p\n", new->address);
	return (new);
}
