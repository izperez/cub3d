/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   04_setup_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:49:44 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:15:41 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_map	*ft_setup_map(t_checks *checker)
{
	t_map	*newmap;
	int		idx;
	char	**newgrid;
	int		max;
	int		size;

	size = 0;
	max = 0;
	newmap = (t_map *)malloc(sizeof(t_map));
	newgrid = (char **)malloc(sizeof(char *) * 1024);
	idx = 0;
	while (checker->map[idx])
	{
		newgrid[idx] = ft_strdup(checker->map[idx]);
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

t_pos	*ft_playerpos(char **map)
{
	t_pos	*newpos;
	int		id;
	int		id2;

	id = 0;
	id2 = 0;
	newpos = (t_pos *)malloc(sizeof(t_pos));
	while (map[id])
	{
		while (map[id][id2])
		{
			if (map[id][id2] == 'N' || map[id][id2] == 'S' || \
				map[id][id2] == 'W' || map[id][id2] == 'E')
			{
				newpos->x = id2 + 0.5;
				newpos->y = id + 0.5;
			}
			id2++;
		}
		id2 = 0;
		id++;
	}
	newpos->dir = ft_pos_dir(map);
	return (newpos);
}

float	ft_pos_dir(char **map)
{
	float	dir;
	int		idx;
	int		idy;

	idx = 0;
	idy = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N')
				dir = 0;
			if (map[idx][idy] == 'S')
				dir = PI;
			if (map[idx][idy] == 'W')
				dir = PI / 2;
			if (map[idx][idy] == 'E')
				dir = 3 * PI / 2;
			idy++;
		}
		idy = 0;
		idx++;
	}
	return (dir);
}

int	ft_trans_rgb(int red, int green, int blue)
{
	int	rgb;

	rgb = (red << 16) | (green << 8) | blue;
	return (rgb);
}

t_ray	*ft_ray_init(t_ray *ray)
{
	t_ray	*new;

	(void)ray;
	new = malloc(sizeof(t_ray));
	new->color = 0;
	new->x_text = 0;
	new->y_text = 0;
	new->dist_wall = 0;
	new->x_current = 0;
	new->y_current = 0;
	new->angle = 0.0;
	return (new);
}
