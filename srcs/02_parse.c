/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:49:08 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:17:41 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_parse(t_checks *checker)
{
	if (ft_voids_checks(checker) == 0)
		return (ft_interror(0, NULL));
	if (ft_voids_checks(checker) == 2)
		return (ft_interror(4, checker));
	if (ft_textures_checks(checker) == 0)
		return (ft_interror(1, NULL));
	if (ft_rgb_checks(checker) == 0)
		return (ft_interror(2, NULL));
	if (ft_map_checks_00(checker) == 0)
		return (ft_interror(3, NULL));
	if (ft_map_checks_01(checker) == 0)
		return (ft_interror(3, NULL));
	return (1);
}

int	ft_voids_checks(t_checks *checker)
{
	if (!checker->n_texture || !checker->s_texture || !checker->w_texture || \
		!checker->e_texture)
		return (0);
	if (checker->c_blue == -1 || checker->c_green == -1 || checker->c_red == -1)
		return (0);
	if (checker->f_blue == -1 || checker->f_green == -1 || checker->f_red == -1)
		return (0);
	if (!checker->map)
		return (2);
	return (1);
}

int	ft_textures_checks(t_checks *checker)
{
	if (ft_texture_format(checker->n_texture) == 0)
		return (0);
	if (ft_texture_format(checker->s_texture) == 0)
		return (0);
	if (ft_texture_format(checker->w_texture) == 0)
		return (0);
	if (ft_texture_format(checker->e_texture) == 0)
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
	if (checker->c_red > 255 || checker->c_red < 0)
		return (0);
	if (checker->f_blue > 255 || checker->f_blue < 0)
		return (0);
	if (checker->f_green > 255 || checker->f_green < 0)
		return (0);
	if (checker->f_red > 255 || checker->f_red < 0)
		return (0);
	return (1);
}

int	ft_map_checks_00(t_checks *checkr)
{
	int	players;
	int	idx;
	int	idy;

	idx = 0;
	players = 0;
	while (checkr->map[idx])
	{
		idy = 0;
		while (checkr->map[idx][idy])
		{
			if (checkr->map[idx][idy] == 'N' || checkr->map[idx][idy] == 'S' || \
				checkr->map[idx][idy] == 'W' || checkr->map[idx][idy] == 'E')
				players++;
			if (checkr->map[idx][idy] == ' ' || checkr->map[idx][idy] == '\t')
				players += ft_space_check(checkr->map, idx, idy);
			idy++;
		}
		idx++;
	}
	if (players != 1)
		return (0);
	return (1);
}
