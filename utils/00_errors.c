/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:48:12 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 10:40:03 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int id)
{
	if (id == 0)
		printf("Format error.\nUSAGE: './cub3d mapXX.cub'\n");
	exit (0);
}

int	ft_interror(int id, t_checks *c)
{
	if (id == 0)
		printf("ERROR: Bad map format.\n");
	if (id == 1)
		printf("ERROR: Textures error.\n");
	if (id == 2)
		printf("ERROR: RGBs error.\n");
	if (id == 3)
		printf("ERROR: Map error.\n");
	if (id == 4)
	{
		printf("ERROR: Void map.\n");
		free(c->map);
	}
	return (0);
}

int	ft_cub(char *argv)
{
	int	idx;

	idx = 0;
	if (!argv)
		return (0);
	while (argv[idx])
	{
		if (argv[idx] == '.')
		{
			if (argv[idx + 1] && argv[idx + 1] == 'c' && argv[idx + 2] \
				&& argv[idx + 2] == 'u' && argv[idx + 3] \
				&& argv[idx + 3] == 'b')
			{
				return (1);
			}
		}
		idx++;
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int					i;
	int					sign;
	unsigned long long	result;

	result = 0;
	sign = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\t' \
		|| str[i] == '\n' || str[i] == '\v' || str[i] == '\f')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (result > 2147483647)
			sign = -2;
		result *= 10;
		result += (str[i] - '0');
		i++;
	}
	return (result * sign);
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
