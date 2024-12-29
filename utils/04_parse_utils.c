/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_parse_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 21:06:39 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 02:28:40 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_texture_format(char *path)
{
	if (access(path, R_OK) == -1)
		return (0);
	return (1);
}

int	ft_repeated_textures(t_checks *checker)
{
	if (ft_strcmp(checker->n_texture, checker->s_texture) == 0)
		return (0);
	if (ft_strcmp(checker->e_texture, checker->s_texture) == 0)
		return (0);
	if (ft_strcmp(checker->w_texture, checker->s_texture) == 0)
		return (0);
	if (ft_strcmp(checker->n_texture, checker->w_texture) == 0)
		return (0);
	if (ft_strcmp(checker->n_texture, checker->e_texture) == 0)
		return (0);
	if (ft_strcmp(checker->e_texture, checker->w_texture) == 0)
		return (0);
	return (1);
}

int	ft_map_checks_01(t_checks *checker)
{
	int	width;
	int	heigth;
	int	idx;
	int	idy;

	idx = 0;
	width = 0;
	heigth = 0;
	while (checker->map[idx])
	{
		idy = 0;
		while (checker->map[idx][idy])
			idy++;
		if (idy > width)
			width = idy;
		idx++;
	}
	heigth = idx;
	return (ft_flood_fill(ft_map_copy(checker->map), heigth, width));
}

int	ft_rgb_last_checks(char **input, int c, int f)
{
	int	id;
	int	check;
	int	check2;

	id = 0;
	check = 0;
	check2 = 0;
	if (!input[c] || !input[f])
		return (0);
	while (input[c][id])
	{
		if (input[c][id] == ',')
			check++;
		id++;
	}
	id = 0;
	while (input[f][id])
	{
		if (input[f][id] == ',')
			check2++;
		id++;
	}
	if (check == 2 && check2 == 2)
		return (1);
	return (0);
}
