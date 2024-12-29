/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_setup_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:47:38 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 10:44:37 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_checks	*ft_setup_checker(int fd)
{
	t_checks	*newchecker;
	char		buff[4092];
	char		**input;

	if (!read(fd, buff, 4092))
		return (NULL);
	newchecker = (t_checks *)malloc(sizeof(t_checks));
	input = ft_split(buff, '\n');
	newchecker->n_texture = ft_texture_data(input, 0);
	newchecker->s_texture = ft_texture_data(input, 1);
	newchecker->w_texture = ft_texture_data(input, 2);
	newchecker->e_texture = ft_texture_data(input, 3);
	ft_setup_rgbs(&newchecker, input);
	if (newchecker->c_red != -1 && newchecker->f_green != -1 \
		&& newchecker->n_texture && newchecker->s_texture && \
		newchecker->w_texture && newchecker->e_texture)
		newchecker->map = ft_setup_map_c(input);
	else
	{
		ft_free_split(input);
		ft_free_semichecker(&newchecker);
	}
	ft_free_split(input);
	return (newchecker);
}

void	ft_setup_rgbs(t_checks **checker, char **input)
{
	(*checker)->c_red = ft_rgbdata(input, 0, 0);
	(*checker)->c_green = ft_rgbdata(input, 1, 0);
	(*checker)->c_blue = ft_rgbdata(input, 2, 0);
	(*checker)->f_red = ft_rgbdata(input, 0, 1);
	(*checker)->f_green = ft_rgbdata(input, 1, 1);
	(*checker)->f_blue = ft_rgbdata(input, 2, 1);
	return ;
}

char	**ft_setup_map_c(char **input)
{
	int		map_top;
	int		map_bot;
	int		idx;
	char	**newmap;

	idx = 0;
	newmap = (char **)malloc(sizeof(char) * 4092);
	map_top = ft_maptop(input);
	if (map_top == -1)
	{
		free(newmap);
		return (NULL);
	}
	map_bot = ft_mapbot(input, map_top);
	while (map_top != map_bot)
		newmap[idx++] = ft_strdup(input[map_top++]);
	newmap[idx] = '\0';
	return (newmap);
}

char	*ft_texture_data(char **input, int flag)
{
	int		idx;

	idx = 0;
	while (input[idx])
	{
		if (flag == 0 && ft_strncmp(input[idx], "NO", 2) == 0)
			return (ft_clean_path(input[idx]));
		if (flag == 1 && ft_strncmp(input[idx], "SO", 2) == 0)
			return (ft_clean_path(input[idx]));
		if (flag == 2 && ft_strncmp(input[idx], "WE", 2) == 0)
			return (ft_clean_path(input[idx]));
		if (flag == 3 && ft_strncmp(input[idx], "EA", 2) == 0)
			return (ft_clean_path(input[idx]));
		idx++;
	}
	return (NULL);
}
