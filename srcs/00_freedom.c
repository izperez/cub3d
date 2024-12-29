/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_freedom.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:47:15 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 11:10:10 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_free_split(char **data)
{
	int	idx;

	idx = 0;
	if (!data)
		return ;
	while (data[idx])
		free(data[idx++]);
	free(data);
	return ;
}

void	ft_free_checker(t_checks *checker)
{
	if (checker->n_texture)
		free(checker->n_texture);
	if (checker->s_texture)
		free(checker->s_texture);
	if (checker->w_texture)
		free(checker->w_texture);
	if (checker->e_texture)
		free(checker->e_texture);
	if (checker->map)
		ft_free_split(checker->map);
	free(checker);
	return ;
}

void	ft_free_semichecker(t_checks **checker)
{
	if ((*checker)->n_texture)
		free((*checker)->n_texture);
	if ((*checker)->s_texture)
		free((*checker)->s_texture);
	if ((*checker)->w_texture)
		free((*checker)->w_texture);
	if ((*checker)->e_texture)
		free((*checker)->e_texture);
	free(*checker);
	printf("ERROR: Bad map.cub format.\n");
	exit (1);
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
	free(data->ray);
	return ;
}
