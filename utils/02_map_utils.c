/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   02_map_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:56:58 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 12:23:00 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_maptop(char **input)
{
	int	top;

	top = 0;
	while (input[top])
	{
		if (ft_mapline(input[top]) == 1)
			return (top);
		top++;
	}
	return (-1);
}

int	ft_mapbot(char **input, int start)
{
	int	s;

	s = start;
	while (input[s] && ft_mapline(input[s]) == 1)
		s++;
	return (s);
}

int	ft_mapline(char *line)
{
	if (line == NULL || strlen(line) == 1 || \
		strncmp(line, "NO ", 3) == 0 || \
		strncmp(line, "SO ", 3) == 0 || \
		strncmp(line, "WE ", 3) == 0 || \
		line[0] == '\n')
		return (0);
	if (strncmp(line, "EA ", 3) == 0 || \
	strncmp(line, "C ", 2) == 0 || \
	strncmp(line, "F ", 2) == 0)
		return (0);
	return (1);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		idx;

	idx = 0;
	if (!str || str[0] == '\0')
		return (NULL);
	newstr = (char *)malloc(sizeof(char *) * 4092);
	while (str[idx])
	{
		if (str[idx] == '\n' || str[idx] == '\0')
			break ;
		newstr[idx] = str[idx];
		idx++;
	}
	newstr[idx] = '\0';
	return (newstr);
}

int	ft_space_check(char **map, int idx, int idy)
{
	if (idx > 0 && map[idx - 1][idy] == '0')
		return (42);
	if (map[idx + 1][idy] == '0')
		return (42);
	if (idy > 0 && map[idx][idy - 1] == '0')
		return (42);
	if (idy < (int)(strlen(map[idx])) - 1 && map[idx][idy + 1] == '0')
		return (42);
	return (0);
}
