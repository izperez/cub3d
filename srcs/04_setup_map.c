/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_setup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:59:07 by adrian            #+#    #+#             */
/*   Updated: 2024/12/06 11:58:33 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*ft_clean_map(char **checkermap)
{
	t_map	*newmap;
	int		idx;
	char	**newgrid;
	int		max;
	int		size;

	size = 0;
	max = 0;
	newmap = malloc(sizeof(t_map));
	newgrid = (char **)malloc(sizeof(char *) * 1024);
	idx = 0;
	while (checkermap[idx])
	{

		newgrid[idx] = ft_strdup(checkermap[idx]);
		size = ft_strlen(newgrid[idx]);
		if (size > max)
			max = size;
		idx++;
	}
	newgrid[idx] = NULL;

	newmap->grid = newgrid;
	newmap->height = idx;
	newmap->width = max;
	return (newmap);
}
