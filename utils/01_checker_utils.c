/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   01_checker_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:48:35 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 02:35:33 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_rgbdata(char **input, int flag, int flag_d)
{
	int	cieling_id;
	int	floor_id;

	cieling_id = ft_rgb_pos(input, 0);
	floor_id = ft_rgb_pos(input, 1);
	if (cieling_id == -1 || floor_id == -1)
		return (-1);
	if (ft_rgb_last_checks(input, cieling_id, floor_id) == 0)
		return (-1);
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
	return (-1);
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
		while (input[idx] && input[idx] != ',')
			idx++;
		idx++;
		while (input[idx] && input[idx] != ',')
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
			idy++;
		}
		idy = 0;
		idx++;
	}
	return (res);
}
