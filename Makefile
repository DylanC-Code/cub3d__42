# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 14:36:04 by dcastor           #+#    #+#              #
#    Updated: 2025/07/25 22:41:36 by dcastor          ###   ########.fr        #
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
		init/init_args.c \
		init/init_game.c \
		\
		render/background.c \
		render/map.c \
		render/render_utils.c \
		\
		utils/error.c \
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
	valgrind --leak-check=full --show-leak-kinds=all --track-fds=yes --track-origins=yes --log-fd=1 --trace-children=yes ./$(NAME)

# ============================================================================== #
#                                  PHONY & DEPS                                  #
# ============================================================================== #

# 📌 Cibles qui ne sont pas des fichiers
.PHONY: all clean fclean re

# 📎 Inclusion des dépendances générées automatiquement
-include $(DEPS) $(DEPS_BONUS)
