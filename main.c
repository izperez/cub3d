/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:38 by adrian            #+#    #+#             */
/*   Updated: 2024/12/11 13:55:04 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


int	load_image(void *patata)
{
	t_data *data;
	
	data = (t_data*)patata;
	
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	ft_drawcf(data);
	calculate_fov(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win, data->mlx->img, 0, 0);
	return (0);
}

char	*ft_clean_path(char *oldpath)
{
	int		idx;
	int		idy;
	char	*newpath;

	newpath = malloc(sizeof(char *) * 1024);
	idx = 3;
	idy = 0;
	while (oldpath[idx])
	{
		//while (oldpath[idx] && oldpath[idy] == ' ')
		//	idx++;
		newpath[idy] = oldpath[idx];
		idx++;
		idy++;
	}
	newpath[idy] = '\0';
	return (newpath);
}

void	ft_textures_mlxinit(t_data **data)
{
	(*data)->n_texture = ft_setup_texture(ft_clean_path((*data)->asset->north_texture), (*data)->mlx);
	(*data)->s_texture = ft_setup_texture(ft_clean_path((*data)->asset->south_texture), (*data)->mlx);
	(*data)->w_texture = ft_setup_texture(ft_clean_path((*data)->asset->west_texture), (*data)->mlx);
	(*data)->e_texture = ft_setup_texture(ft_clean_path((*data)->asset->east_texture), (*data)->mlx);
}

void	ft_cub3d(t_data *data)
{
	ft_textures_mlxinit(&data);
	// printf("n_texture %s\n", data->n_texture->address);
	// printf("s_texture %s\n", data->s_texture->address);
	// printf("w_texture %s\n", data->w_texture->address);
	// printf("e_texture %s\n", data->e_texture->address);
	load_image(data);
	mlx_hook(data->mlx->win, 2, 3, *ft_hooks, data);
	mlx_key_hook(data->mlx->win, *ft_close, data);
	mlx_loop_hook(data->mlx->mlx, load_image, data);
	mlx_loop(data->mlx->mlx);
		
}

/* void	ft_print_data(t_data *data)
{
	int	idx = 0;
	while (data->map->grid[idx])
	{
		printf("map [%i] -> %s\n", idx, data->map->grid[idx]);
		idx++;
	}
	printf("map W -> %i\n", data->map->width);
	printf("map H -> %i\n", data->map->height);
	printf("assets -> NO %s\n", data->asset->north_texture);
	printf("assets -> SO %s\n", data->asset->south_texture);
	printf("assets -> WE %s\n", data->asset->west_texture);
	printf("assets -> EA %s\n", data->asset->east_texture);
	printf("Floor rgbs %i, %i, %i\n", data->asset->floor_rgb[0], data->asset->floor_rgb[1], data->asset->floor_rgb[2]);
	printf("Cieling rgbs %i, %i, %i\n", data->asset->cieling_rgb[0], data->asset->cieling_rgb[1], data->asset->cieling_rgb[2]);
	printf("Player pos x -> %f\n", data->playerpos->x);
	printf("Player pos y -> %f\n", data->playerpos->y);
	printf("Player orientation -> %f (0 no, 1 so, 2 we, 3 ea)\n", data->playerpos->dir);
} */

/* void	ft_print_checker(t_checks *checker)
{
	printf("north texture -> %s\n", checker->north_texture);
	printf("south texture -> %s\n", checker->south_texture);
	printf("west texture -> %s\n", checker->west_texture);
	printf("east texture -> %s\n", checker->east_texture);
	printf("floor rgbs -> %i, %i, %i\n", checker->f_red, checker->f_green, checker->f_blue);
	printf("cieling rgbs -> %i, %i, %i\n", checker->c_red, checker->c_green, checker->c_blue);
	printf("map[0] %s\nmap[1] %s\nmap[2] %s\n...\n", checker->map[0], checker->map[1], checker->map[2]);
	return ;
} */

int	main(int argc, char **argv)
{
	t_data		*data;
	t_checks	*checker;
	int			fd;

	if (argc == 1 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	checker = ft_setup_checker(fd);
	// ft_print_checker(checker)
	if (ft_parse(checker) == 1)
		data = ft_setup_data(checker);
	//ft_free_checker(checker);
	//ft_print_data(data);
	printf("rgb cielo %d\nrgb suelo %d\n", data->asset->cieling_rgb, data->asset->floor_rgb);
	if (data)
	{
		ft_cub3d(data);
		printf("north texture address %s\n", data->n_texture->address);
		ft_free_data(data);
	}
	return (1);
}
