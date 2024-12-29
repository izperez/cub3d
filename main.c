/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:37:48 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:16:49 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_cub3d(t_data *data)
{
	ft_textures_mlxinit(&data);
	ft_load_image(data);
	mlx_hook(data->mlx->win, 2, 3, *ft_hooks, data);
	mlx_key_hook(data->mlx->win, *ft_close, data);
	mlx_loop_hook(data->mlx->mlx, ft_load_image, data);
	mlx_loop(data->mlx->mlx);
}

int	main(int argc, char **argv)
{
	t_data		*data;
	t_checks	*checker;
	int			fd;

	if (argc != 2 || ft_cub(argv[1]) == 0)
		ft_error(0);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		printf("ERROR: Can't open this x.cub path.\n");
		exit(0);
	}
	checker = ft_setup_checker(fd);
	if (checker != NULL && ft_parse(checker) == 1)
		data = ft_setup_data(checker);
	if (checker)
		ft_free_checker(checker);
	if (data)
	{
		ft_cub3d(data);
		ft_free_data(data);
	}
	return (1);
}
