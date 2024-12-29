# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adlopez- <adlopez-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/22 20:46:33 by adlopez-          #+#    #+#              #
#    Updated: 2024/12/22 22:03:20 by adlopez-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d
CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address -g3
MLXFLAGS = -L$(MLX_DIR) -lm -lmlx -lX11 -lXext

MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a

SRCS = main.c \
		srcs/00_freedom.c \
		srcs/01_setup_checker.c \
		srcs/02_parse.c \
		srcs/03_setup_data.c \
		srcs/04_setup_map.c \
		srcs/05_start_game.c \
		srcs/06_render_map.c \
		srcs/07_hooks.c \
		srcs/08_raycasting.c \
		srcs/09_textures.c \
		utils/00_errors.c \
		utils/01_checker_utils.c \
		utils/02_map_utils.c \
		utils/03_split.c \
		utils/04_parse_utils.c \
		utils/05_init_utils.c

OBJS = $(SRCS:.c=.o)

.SILENT:
all: $(MLX_LIB) $(NAME)

# Compilación de la MLX
$(MLX_LIB):
	@echo "🛠️  Compilando librería MLX..."
	@make -C $(MLX_DIR)
	@echo "✅ Librería MLX compilada correctamente!"

# Compilación del programa
$(NAME): $(OBJS)
	@echo "🛠️  Compilando $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)
	@echo "✅ Compilación correcta!"

# Regla para generar archivos .o
%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

# Limpieza
clean:
	@rm -f $(OBJS)
	@make -C $(MLX_DIR) clean
	@echo "🧹 Archivos .o eliminados!"

fclean: clean
	@rm -f $(NAME)
	@make -C $(MLX_DIR) clean
	@echo "🗑️ Ejecutable eliminado!"

re: fclean all
