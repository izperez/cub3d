/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_utiles_todo.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 16:23:27 by adrian            #+#    #+#             */
/*   Updated: 2024/12/11 11:28:10 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static int	count_words(const char *str, char c)
{
	int i;
	int trigger;

	i = 0;
	trigger = 0;
	while (*str)
	{
		if (*str != c && trigger == 0)
		{
			trigger = 1;
			i++;
		}
		else if (*str == c)
			trigger = 0;
		str++;
	}
	return (i);
}

static char	*word_dup(const char *str, int start, int finish)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char		**ft_split(char const *s, char c)
{
	int		i;
	int		j;
	int		index;
	char	**split;

	if (!s || !(split = malloc((count_words(s, c) + 1) * sizeof(char *))))
		return (0);
	i = 0;
	j = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[j++] = word_dup(s, index, i);
			index = -1;
		}
		i++;
	}
	split[j] = 0;
	return (split);
}

int	ft_strlen(const char *s)
{
	int	idx;

	idx = 0;
	while (s[idx])
		idx++;
	return (idx);
}

char	*ft_strdup(char *str)
{
	char	*newstr;
	int		idx;

	idx = 0;
	if (!str)
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
	while (ft_mapline(input[s]) == 1)
		s++;
	return (s);
}

int	ft_mapline(char *line)
{
	int	id;
	
	id = 0;
	if (!line || line[0] == '\0')
		return (0);
	while (line[id])
	{
		if (line[id] == '0' || line[id] == '1' || line[id] == ' ' || line[id] == '\t' ||\
			line[id] == 'N' || line[id] == 'S' || line[id] == 'E' || line[id] == 'W' || line[id] == '\n')
			id++;
		else
			break ;
	}
	if (id == ft_strlen(line))
		return (1);
	return (0);
}

int	ft_rgb_pos(char **input, int flag)
{
	int	idx;

	idx = 0;
	if (flag == 0)
	{
		while (input[idx])
		{
			if (ft_strncmp(input[idx], "C", 1) == 0)
				return (idx);
			idx++;
		}
	}
	if (flag == 1)
	{
		while (input[idx])
		{
			if (ft_strncmp(input[idx], "F", 1) == 0)
				return (idx);
			idx++;
		}
	}
	return (0);
}

int	ft_rgbreturn(char *input, int flag)
{
	int		idx;
	int		idy;
	char	str[42];

	idx = 1;
	idy = 0;
	if (flag == 0)
	{
		while (input[idx] != ',')
			str[idy++] = input[idx++];
		str[idy] = '\0';
		return (atoi(str));
	}
	if (flag == 1)
	{
		while (input[idx] != ',')
			idx++;
		idx++;
		while (input[idx] != ',')
			str[idy++] = input[idx++];
		str[idy] = '\0';
		return (atoi(str));
	}
	return (0);
}

int	ft_rgbreturn_2(char *input)
{
	int		idx;
	int		idy;
	char	str[42];

	idx = 0;
	idy = 0;
	while (input[idx] != ',')
		idx++;
	idx++;
	while (input[idx] != ',')
		idx++;
	idx++;
	while (input[idx] && input[idx] != '\0')
		str[idy++] = input[idx++];
	str[idy] = '\0';
	return (atoi(str));
}

int	ft_strncmp(const char *str, const char *str2, size_t c)
{
	size_t			i;
	unsigned int	diff;

	diff = 0;
	i = 0;
	while ((str[i] != '\0') && (str2[i] != '\0')
		&& (diff == 0) && (i < c))
	{
		diff = (unsigned char)str[i] - (unsigned char)str2[i];
		i++;
	}
	if ((diff == 0) && (i < c))
		diff = (unsigned char)str[i] - (unsigned char)str2[i];
	return (diff);
}

int	ft_texture_format(char *texture)
{
	(void)texture;
	return (1);
}

int	ft_repeated_textures(t_checks *checker)
{
	(void)checker;
	return (1);
}

float	ft_posdir(char **map)
{
	int		idx;
	int		idy;
	float	res;

	idx = 0;
	idy = 0;
	while (map[idx])
	{
		while (map[idx][idy])
		{
			if (map[idx][idy] == 'N')
				res = PI / 2;
			if (map[idx][idy] == 'S')
				res = 3 * (PI / 2);
			if (map[idx][idy] == 'W')
				res = PI;
			if (map[idx][idy] == 'E')
				res = 2 * PI;
			idy++;;
		}
		idy = 0;
		idx++;
	}
	return (res);
}
