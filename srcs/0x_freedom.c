/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0x_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:51 by adrian            #+#    #+#             */
/*   Updated: 2024/12/06 11:33:32 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_split(char **data)
{
	int idx;

	idx = 0;
	while (data[idx])
		free(data[idx++]);
	free(data);
	return ;
}

void	ft_free_checker(t_checks *checker)
{
	free(checker->north_texture);
	free(checker->south_texture);
	free(checker->west_texture);
	free(checker->east_texture);
	ft_free_split(checker->map);
	free(checker);
	return ;
}

void	ft_free_semichecker(t_checks *checker)
{
	free(checker->north_texture);
	free(checker->south_texture);
	free(checker->west_texture);
	free(checker->east_texture);
	free(checker);
	printf("ERROR: Bad map format.\n");
}

void	ft_free_data(t_data *data)
{
	ft_free_split(data->map->grid);
	free(data->map);
	free(data->playerpos);
	free(data->asset->north_texture);
	free(data->asset->south_texture);
	free(data->asset->west_texture);
	free(data->asset->east_texture);
	free(data->asset);
	free(data->n_texture);
	free(data->s_texture);
	free(data->w_texture);
	free(data->e_texture);
	free(data->mlx);
	return ;
}
