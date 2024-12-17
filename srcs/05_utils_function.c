/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   05_IZAROMAMICOSAS.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 19:30:37 by adrian            #+#    #+#             */
/*   Updated: 2024/11/29 13:16:01 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_close(int keycode, t_data *data)
{
	if (keycode == ESC)
	{
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
		exit (0);
	}
	return (keycode);
}
