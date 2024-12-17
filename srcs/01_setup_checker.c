/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_setup_checker.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:31:13 by adrian            #+#    #+#             */
/*   Updated: 2024/12/06 12:37:12 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_checks	*ft_setup_checker(int fd)
{
	t_checks	*newchecker;
	char		buff[4092];
	char		**input;

	newchecker = (t_checks *)malloc(sizeof(t_checks));
	if (!read(fd, buff, 4092))
		return (NULL);
	input = ft_split(buff, '\n');
	newchecker->north_texture = ft_texture_data(input, 0);
	newchecker->south_texture = ft_texture_data(input, 1);
	newchecker->west_texture = ft_texture_data(input, 2);
	newchecker->east_texture = ft_texture_data(input, 3);
	ft_setup_rgbs(&newchecker, input);
	if (newchecker->c_red && newchecker->f_green && newchecker->north_texture && \
		newchecker->south_texture && newchecker->west_texture && newchecker->east_texture)
		newchecker->map = ft_setup_map(input);
	else
	{
		ft_free_split(input);
		ft_free_semichecker(newchecker);
		return (NULL);
	}
	ft_free_split(input);
	return (newchecker);
	// newchecker->map = ft_setup_map(input);
	// ft_setup_rgbs(&newchecker, input);
	// ft_free_split(input);
	// return (newchecker);
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

int	ft_rgbdata(char **input, int flag, int flag_d)
{
	int	cieling_id;
	int	floor_id;

	cieling_id = ft_rgb_pos(input, 0);
	floor_id = ft_rgb_pos(input, 1);
	if (flag_d == 0 && flag == 0)
		return (ft_rgbreturn(input[cieling_id], flag));
	if (flag_d == 0 && flag == 1)
		return (ft_rgbreturn(input[cieling_id], flag));
	if (flag_d == 0 && flag == 2)
		return (ft_rgbreturn_2(input[cieling_id]));
	if (flag_d == 1 && flag == 0)
		return (ft_rgbreturn(input[floor_id], flag));
	if (flag_d == 1 && flag == 1)
		return (ft_rgbreturn(input[floor_id], flag));
	if (flag_d == 1 && flag == 2)
		return (ft_rgbreturn_2(input[floor_id]));
	return (0);
}

char	**ft_setup_map(char **input)
{
	int		map_top;
	int		map_bot;
	int		idx;
	char	**newmap;

	idx = 0;
	newmap = (char **)malloc(sizeof(char) * 4092);
	map_top = ft_maptop(input);
	map_bot = ft_mapbot(input, map_top);
	if (map_bot == -1 || map_bot == -1)
		return (NULL);
	while (map_top != map_bot)
		newmap[idx++] = ft_strdup(input[map_top++]);
	newmap[idx] = '\0';
	return (newmap);
}

char	*ft_texture_data(char **input, int flag)
{
	int		idx;
	char	*texture;

	idx = 0;
	texture = NULL;
	while (input[idx])
	{
		if (flag == 0 && ft_strncmp(input[idx], "NO", 2) == 0)
			texture = ft_strdup(input[idx]);
		if (flag == 1 && ft_strncmp(input[idx], "SO", 2) == 0)
			texture = ft_strdup(input[idx]);
		if (flag == 2 && ft_strncmp(input[idx], "WE", 2) == 0)
			texture = ft_strdup(input[idx]);
		if (flag == 3 && ft_strncmp(input[idx], "EA", 2) == 0)
			texture = ft_strdup(input[idx]);
		idx++;
	}
	return (texture);
}
