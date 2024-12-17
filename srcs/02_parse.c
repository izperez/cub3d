/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:30:20 by adrian            #+#    #+#             */
/*   Updated: 2024/11/29 13:14:15 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse(t_checks *checker)
{
	if (ft_voids_checks(checker) == 0)
		return (ft_interror(0));
	if (ft_textures_checks(checker) == 0)
		return (ft_interror(1));
	if (ft_rgb_checks(checker) == 0)
		return (ft_interror(2));
	if (ft_map_checks(checker) == 0)
		return (ft_interror(3));
	return (1);
}

int	ft_voids_checks(t_checks *checker)
{
	if (!checker->north_texture || !checker->south_texture || !checker->west_texture\
		|| !checker->east_texture || !checker->map[0])
		return (0);
	if (checker->c_blue == -1 || checker->c_green == -1 || checker->c_red == -1)
		return (0);
	if (checker->f_blue == -1 || checker->f_green == -1 || checker->f_red == -1)
		return (0);
	return (1);
}

int	ft_textures_checks(t_checks *checker)
{
	if (ft_texture_format(checker->north_texture) == 0)
		return (0);
	if (ft_texture_format(checker->south_texture) == 0)
		return (0);
	if (ft_texture_format(checker->west_texture) == 0)
		return (0);
	if (ft_texture_format(checker->east_texture) == 0)
		return (0);
	if (ft_repeated_textures(checker) == 0)
		return (0);
	return (1);
}

int	ft_rgb_checks(t_checks *checker)
{
	if (checker->c_blue > 255 || checker->c_blue < 0)
		return (0);
	if (checker->c_green > 255 || checker->c_green < 0)
		return (0);
	if (checker->c_red > 255 || checker->c_red< 0)
		return (0);
	if (checker->f_blue > 255 || checker->f_blue < 0)
		return (0);
	if (checker->f_green > 255 || checker->f_green < 0)
		return (0);
	if (checker->f_red > 255 || checker->f_red < 0)
		return (0);
	return (1);
}

int	ft_map_checks(t_checks *checker)
{
	int	players;
	int	idx;
	int	idy;

	idx = 0;
	idy = 0;
	players = 0;
	while (checker->map[idx])
	{
		while (checker->map[idx][idy])
		{
			if (checker->map[idx][idy] == 'N' || checker->map[idx][idy] == 'S' || \
				checker->map[idx][idy] == 'W' || checker->map[idx][idy] == 'E')
				players++;
			idy++;
		}
		idy = 0;
		idx++;
	}
	if (players != 1)
		return (0);
	return (1);
}
