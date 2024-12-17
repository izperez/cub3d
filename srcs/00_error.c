/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   00_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:26:54 by adrian            #+#    #+#             */
/*   Updated: 2024/11/29 13:10:02 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_error(int id)
{
	if (id == 0)
		printf("Format error.\nUSAGE: './cub3d map.cub'\n");
	exit (0);
}

int	ft_interror(int id)
{
	if (id == 0)
		printf("ERROR: Bad map format.\n");
	if (id == 1)
		printf("ERROR: Textures error.\n");
	if (id == 2)
		printf("ERROR: RGBs error.\n");
	if (id == 0)
		printf("ERROR: Map error.\n");
	return (0);
}

int	ft_cub(char *argv)
{
	int idx;

	idx = 0;
	if (!argv)
		return (0);
	while (argv[idx])
	{
		if (argv[idx] == '.')
		{
			if (argv[idx + 1] && argv[idx + 1] == 'c' && argv[idx + 2] \
				&& argv[idx + 2] == 'u' && argv[idx + 3] && argv[idx + 3] == 'b')
				return (1);
		}
		idx++;
	}
	return (0);
}
