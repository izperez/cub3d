/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   03_setup_data.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/22 20:49:26 by adlopez-          #+#    #+#             */
/*   Updated: 2024/12/23 02:41:41 by adlopez-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

t_data	*ft_setup_data(t_checks *checker)
{
	t_data	*newdata;

	newdata = (t_data *)malloc(sizeof(t_data));
	newdata->mlx = ft_mlx_init();
	newdata->asset = ft_setup_asset(checker);
	newdata->map = ft_setup_map(checker);
	newdata->playerpos = ft_playerpos(newdata->map->grid);
	newdata->ray = ft_ray_init(newdata->ray);
	return (newdata);
}

t_asset	*ft_setup_asset(t_checks *checker)
{
	t_asset	*newasset;

	newasset = (t_asset *)malloc(sizeof(t_asset));
	newasset->north_texture = ft_strdup(checker->n_texture);
	newasset->south_texture = ft_strdup(checker->s_texture);
	newasset->east_texture = ft_strdup(checker->e_texture);
	newasset->west_texture = ft_strdup(checker->w_texture);
	newasset->cieling_rgb = ft_trans_rgb(checker->c_red, checker->c_green, \
		checker->c_blue);
	newasset->floor_rgb = ft_trans_rgb(checker->f_red, checker->f_green, \
		checker->f_blue);
	return (newasset);
}

t_image_info	*ft_setup_texture(char *path, t_mlx *mlx)
{
	t_image_info	*newimginfo;
	int				temp_width;

	temp_width = 0;
	newimginfo = (t_image_info *)malloc(sizeof(t_image_info));
	newimginfo->image_charge = mlx_xpm_file_to_image(mlx->mlx, path, \
		&temp_width, &(newimginfo->line_s));
	newimginfo->address = mlx_get_data_addr(newimginfo->image_charge, \
		&(newimginfo->bpp), &(newimginfo->line_s), &(newimginfo->endian));
	free(path);
	return (newimginfo);
}

t_mlx	*ft_mlx_init(void)
{
	t_mlx	*new;

	new = (t_mlx *)malloc(sizeof(t_mlx));
	new->mlx = mlx_init();
	new->win = mlx_new_window(new->mlx, 30 * WINDOW_RATIO,
			15 * WINDOW_RATIO, "cub3d");
	new->img = mlx_new_image(new->mlx, 30 * WINDOW_RATIO,
			15 * WINDOW_RATIO);
	if (new->img == NULL)
		printf("Error image\n");
	new->img_addr = mlx_get_data_addr(new->img, &new->bit_per_pixel,
			&new->size_line, &new->endian);
	new->width_window = 30 * WINDOW_RATIO;
	new->height_window = 15 * WINDOW_RATIO;
	return (new);
}
