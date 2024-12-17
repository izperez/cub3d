/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: izperez <izperez@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:20:59 by adrian            #+#    #+#             */
/*   Updated: 2024/12/17 13:58:40 by izperez          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <stdbool.h>
# include "mlx/mlx.h"
# include <math.h>

# define A 97
# define D 100
# define W 119
# define S 115
# define LEFT 65361
# define RIGHT 65363
# define UP 65364
# define DOWN 65364
# define ESC 65307

# define WALL_TOP 0
# define WALL_BOTTOM 1
# define WALL_RIGHT 2
# define WALL_LEFT 3

# define TILE_SIZE 100
# define PI 3.14159265359

# define GRIS 0x808080
# define BLANCO 0xFFFFFF
# define NEGRO 0x000000
# define ROJO 0xff0000
# define ROSA 0xB0149B
# define MORADO 0x7306BC
# define VERDE 0x099F1D
# define AZUL 0X146BD0

# define WINDOW_RATIO 81

typedef struct s_image_info
{
	void			*image_charge;
	char			*address;
	int				bpp;
	int				line_s;
	int				endian;
	bool			created;
}					t_image_info;

typedef struct s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	void			*img_addr;
	int				bit_per_pixel;
	int				size_line;
	int				endian;
	int				width_window;
	int				height_window;
}						t_mlx;

typedef struct s_asset
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				cieling_rgb;
	int				floor_rgb;
}					t_asset;

typedef struct s_playerpos
{
	float			x;
	float			y;
	float			dir;
}					t_pos;

typedef struct s_map
{
	int				width;
	int				height;
	char			**grid;
}					t_map;

typedef struct s_data
{
	t_map			*map;
	t_asset			*asset;
	t_pos			*playerpos;
	t_mlx			*mlx;
	t_image_info	*n_texture;
	t_image_info	*s_texture;
	t_image_info	*w_texture;
	t_image_info	*e_texture;
}					t_data;


typedef struct s_checks
{
	char			*north_texture;
	char			*south_texture;
	char			*west_texture;
	char			*east_texture;
	int				c_red;
	int				c_blue;
	int				c_green;
	int				f_red;
	int				f_blue;
	int				f_green;
	char			**map;
	int				x_ppos;
	int				y_ppos;
}					t_checks;

// functions
int				load_image(void *patata);
//utils
//static int			count_words(const char *str, char c);
//static char			*word_dup(const char *str, int start, int finish);
char				**ft_split(char const *s, char c);
int					ft_strlen(const char *s);
char				*ft_strdup(char *str);
int					ft_maptop(char **input);
int					ft_mapbot(char **input, int start);
int					ft_mapline(char *line);
int					ft_rgb_pos(char **input, int flag);
int					ft_rgbreturn(char *input, int flag);
int					ft_rgbreturn_2(char *input);
int					ft_strncmp(const char *str, const char *str2, size_t c);
int					ft_texture_format(char *texture);
int					ft_repeated_textures(t_checks *checker);
float				ft_posdir(char **map);


//00_error.c
void				ft_error(int id);
int					ft_interror(int id);
int					ft_cub(char *argv);

//0x_freedom.c
void				ft_free_split(char **data);
void				ft_free_checker(t_checks *checker);
void				ft_free_data(t_data *data);
void				ft_free_semichecker(t_checks *checker);

//01_setup_checker.c
t_checks	*		ft_setup_checker(int fd);
void				ft_setup_rgbs(t_checks **checker, char **input);
int					ft_rgbdata(char **input, int flag, int flag_d);
char				**ft_setup_map(char **input);
char				*ft_texture_data(char **input, int flag);

//02_parse
int					ft_parse(t_checks *checker);
int					ft_voids_checks(t_checks *checker);
int					ft_textures_checks(t_checks *checker);
int					ft_rgb_checks(t_checks *checker);
int					ft_map_checks(t_checks *checker);

//03_setup_data.c
t_data				*ft_setup_data(t_checks *checker);
t_pos				*ft_playerpos(char **map);
t_mlx				*ft_mlx_init(t_map *map);
t_asset				*ft_setup_assets(t_checks *checker);
t_image_info		*ft_setup_texture(char *path, t_mlx *mlx);
int					ft_transform_rgb(int red, int green, int blue);

//04_setup_map.c
t_map				*ft_clean_map(char **checkermap);

//05_izaromamicosas.c
int					ft_close(int keycode, t_data *data);

//06_render_map.c
void				my_mlx_pixel_put(t_data *data, int x, int y, int color);
void				draw_square(t_data *data, char c, int d_x, int d_y);
void				calculate_fov(t_data *data);
void				draw_player(t_data *data);
void				prepare_rays(t_data *data, float desf, int lenght);
void				draw_line(t_data *data, float x_start, float y_start, float angle, float steps);
int					ft_distancia(int x, int y, t_pos *player);

//07_hooks.c
int					ft_hooks( int keycode, t_data *data);
int					ft_rotation(int keycode, t_data *data);

//08_3d.c
int					wall_side(int x, int y);
void				ft_drawcf(t_data *data);
void				draw_colum(t_data *data, int color, int dist_wall, int x_current, int y_current);

int					ft_textures_colors(int x_text, int y_text, t_image_info *data);
int					ft_texture_color(int x, int y, t_data *data, int x_text, int y_text);
int					ft_north_south(int x, int y);

#endif