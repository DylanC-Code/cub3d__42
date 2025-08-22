# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:36:04 by dcastor           #+#    #+#              #
#    Updated: 2025/08/22 10:47:29 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ============================================================================== #
#                                 CONFIGURATION                                  #
# ============================================================================== #

# 📛 Nom du programme
NAME := cub3d
LIB_NAME := libft
MLX_NAME := minilibx-linux

# 📂 Répertoires
SRCS_DIR := srcs/
BUILD_DIR := build/
LIB_DIR := $(LIB_NAME)/
MLX_DIR := $(MLX_NAME)/
INCLUDE_DIRS := -I$(LIB_DIR)includes -Iincludes -I$(MLX_DIR)

# 📦 Compiler & Flags
CC := cc
CFLAGS := -Wall -Wextra -Werror -g3 $(INCLUDE_DIRS)
MLX_FLAGS := -lX11 -lXext

# 🛠 Utilitaires
MAKE := make
RM := rm -rf

# 📁 Sources & Objets
SRCS := $(addprefix $(SRCS_DIR), \
		cleanup/cleanup.c \
		\
		events/events.c \
		events/exit.c \
		events/inputs.c \
		events/movement.c \
		\
		init/init_args.c \
		init/init_game.c \
		init/init_player.c \
		init/init_textures.c \
		\
		raycast/cast_ray.c \
		raycast/horizontal.c \
		raycast/ray_utils.c \
		raycast/raycast.c \
		raycast/vector_utils.c \
		raycast/vertical.c \
		\
		render/background.c \
		render/draw_helpers.c \
		render/game.c \
		render/hud.c \
		render/map.c \
		render/player.c \
		render/render_tex.c \
		render/render_utils.c \
		render/wall_column_utils.c \
		render/wall_column.c \
		\
		parsing/colors.c \
		parsing/colors2.c \
		parsing/map_parsing_check.c \
		parsing/map_parsing_list.c \
		parsing/map_parsing_utils.c \
		parsing/map_parsing.c \
		parsing/parsing_element.c \
		parsing/parsing_gnl.c \
		parsing/parsing_id.c \
		parsing/parsing_main.c \
		parsing/parsing_texture.c \
		parsing/parsing_utils.c \
		parsing/validation_check.c \
		parsing/validation_dimensions.c \
		parsing/validation_dup.c \
		parsing/validation_flood.c \
		\
		utils/error.c \
		utils/map.c \
		utils/utils_map.c \
		utils/utils_player.c \
		\
		main.c \
)
OBJS := $(patsubst %.c, $(BUILD_DIR)%.o, $(SRCS))

DEPS := $(OBJS:.o=.d)

# 📚 Libft
LIB_FILE := $(LIB_DIR)libft.a
MLX_FILE := $(MLX_DIR)libmlx.a


# ============================================================================== #
#                               RULES - BUILD FLOW                               #
# ============================================================================== #

# 🎯 Règle principale
all: $(NAME)

# 🧱 Construction de l'exécutable
$(NAME): $(BUILD_DIR) $(LIB_FILE) $(MLX_FILE) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB_FILE) $(MLX_FILE) $(MLX_FLAGS) -lm

# 🔨 Compilation des .c vers .o
$(BUILD_DIR)%.o: %.c
	mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -g -MMD $(INCLUDE_DIRS) -c $< -o $@


# ============================================================================== #
#                            DIRECTORY & LIBRARY SETUP                           #
# ============================================================================== #

# 📁 Création du dossier de build
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# 📚 Build libft.a
$(LIB_FILE): $(LIB_DIR)
	$(MAKE) -sC $(LIB_DIR)

$(MLX_FILE):
	$(MAKE) -sC $(MLX_DIR)

# ============================================================================== #
#                                   CLEAN RULES                                  #
# ============================================================================== #

clean:
	$(RM) $(BUILD_DIR) && make clean -C $(LIB_DIR) && make clean -C $(MLX_DIR)

fclean: clean
	$(RM) $(NAME)

re: fclean all

# ============================================================================== #
#                                    TEST RULES                                  #
# ============================================================================== #

test_leak: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-fd=1 --trace-children=yes ./$(NAME) test.cub

# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS) $(DEPS_BONUS)
