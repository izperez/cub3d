/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   07_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 12:29:39 by izperez           #+#    #+#             */
/*   Updated: 2024/12/11 13:56:08 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static void	key_press_aux(t_data *data, double move_x, double move_y, int mode)
{
	t_pos *player;
	float tmp_x;
	float tmp_y;

	player = data->playerpos;

	// Dependiendo del modo (hacia adelante o hacia atrás), ajustamos las coordenadas
	if (mode == 1) // Movimiento hacia atrás
	{
		tmp_x = player->x - (move_x * 0.1);
		tmp_y = player->y - (move_y * 0.1);
	}
	else // Movimiento hacia adelante
	{
		tmp_x = player->x + (move_x * 0.1);
		tmp_y = player->y + (move_y * 0.1);
	}

	// Validación de colisión con muros (1) o fuera de los límites (espacio vacío ' ')
	if (data->map->grid[(int)(tmp_x)][(int)(tmp_y)] != '1' && data->map->grid[(int)tmp_x][(int)tmp_y] != ' ')
	{
		player->x = tmp_x;
		player->y = tmp_y;
	}

	data->playerpos = player;
}

int	ft_hooks(int keycode, t_data *data)
{
	double move_x, move_y;

	//system("clear");
	// Cálculo de la dirección para cada tecla
	if (keycode == S)
	{
		move_x = cos(data->playerpos->dir + PI / 2); // 90 grados a la izquierda
		move_y = sin(data->playerpos->dir + PI / 2);
		key_press_aux(data, move_x, move_y, 1); // Mover a la izquierda
	}
	else if (keycode == W) // Movimiento hacia la derecha (perpendicular a la dirección)
	{
		move_x = cos(data->playerpos->dir - PI / 2); // 90 grados a la derecha
		move_y = sin(data->playerpos->dir - PI / 2);
		key_press_aux(data, move_x, move_y, 1); // Mover a la derecha
	}
	else if (keycode == D) // Movimiento hacia adelante (en la dirección actual)
	{
		move_x = cos(data->playerpos->dir); // Dirección hacia adelante
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 2); // Mover hacia adelante
	}
	else if (keycode == A) // Movimiento hacia atrás (en la dirección opuesta)
	{
		move_x = cos(data->playerpos->dir); // Dirección hacia atrás
		move_y = sin(data->playerpos->dir);
		key_press_aux(data, move_x, move_y, 1); // Mover hacia atrás
	}
	else
		ft_rotation(keycode, data);
	return (keycode);
}


int	ft_rotation(int keycode, t_data *data)
{
	float	angle;

	angle = data->playerpos->dir;
	if (keycode == RIGHT)
		angle -= 0.015;
	else if (keycode == LEFT)
		angle += 0.015;
	// else
	// 	printf("error rotation %i\n", keycode);
		
	data->playerpos->dir = angle;
	return (keycode);
}