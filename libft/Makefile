# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 16:35:34 by dcastor           #+#    #+#              #
#    Updated: 2025/07/25 11:01:51 by dcastor          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -Wall -Wextra -Werror -g -MMD

NAME = libft.a
OPTIONS = -c -I ./includes -I ../includes/

SRCS_DIR = srcs/
BUILD_DIR = build/

SRCS = $(addprefix $(SRCS_DIR), \
	bit/bit_is_set.c \
	bit/set_bit.c \
	\
	char/ft_toupper.c \
	char/ft_tolower.c \
	\
	dlist/ft_dlst_new.c \
	dlist/ft_dlstadd_back.c \
	\
	int/ft_dup_int_arr.c \
	int/ft_int_in_arr.c \
	\
	memory/ft_memset.c \
	memory/ft_bzero.c \
	memory/ft_memcpy.c \
	memory/ft_memmove.c \
	memory/ft_memchr.c \
	memory/ft_memcmp.c \
	memory/ft_calloc.c \
	memory/garbage.c \
	\
	number/ft_abs.c \
	number/ft_max.c \
	\
	string/ft_contains_substr.c \
	string/ft_count_occ.c \
	string/ft_ends_with.c \
	string/ft_starts_with.c \
	string/ft_free_strs.c \
	string/ft_str_contains_any.c \
	string/ft_strlen.c \
	string/ft_strlcpy.c \
	string/ft_strlcat.c \
	string/ft_strchr.c \
	string/ft_ischarset.c \
	string/ft_strrchr.c \
	string/ft_strncmp.c \
	string/ft_strcmp.c \
	string/ft_strnstr.c \
	string/ft_strdup.c \
	string/ft_strndup.c \
	string/ft_substr.c \
	string/ft_strjoin.c \
	string/ft_strtrim.c \
	string/ft_strmapi.c \
	string/ft_striteri.c \
	\
	utils/ft_split.c \
	utils/ft_atoi.c \
	utils/ft_atol.c \
	utils/ft_itoa_base.c \
	utils/ft_itoa.c \
	utils/ft_lis_len.c \
	utils/ft_lower_bound.c \
	utils/ft_strset.c \
	utils/ft_uitoa_base.c \
	utils/ft_uitoa.c \
	utils/quick_sort.c \
	utils/gnl/get_next_line.c \
	utils/gnl/get_next_line_part2.c \
	\
	output/ft_putchar_fd.c \
	output/ft_putstr_fd.c \
	output/ft_putendl_fd.c \
	output/ft_putnbr_fd.c \
	output/print_err.c \
	\
	list/ft_lstsome.c \
	list/ft_lstnew.c \
	list/ft_lstadd_front.c \
	list/ft_lstsize.c \
	list/ft_lstlast.c \
	list/ft_lstadd_back.c \
	list/ft_lstdelone.c \
	list/ft_lstclear.c \
	list/ft_lstiter.c \
	list/ft_lstmap.c \
	\
	validate/ft_isalpha.c \
	validate/ft_isdigit.c \
	validate/ft_isalnum.c \
	validate/ft_isascii.c \
	validate/ft_isprint.c \
	validate/ft_isspace.c \
	validate/is_valid_number.c \
)

OBJS = $(patsubst  %.c, $(BUILD_DIR)%.o, $(SRCS))
DEPS = $(OBJS:.o=.d)

all: $(NAME)

$(NAME): $(BUILD_DIR) $(OBJS)
	@ar rsc $(NAME) $(OBJS)
	@echo "[$(NAME)] Archive generated ✅"

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)
	@echo "[$(NAME)] build directory created ✅"

$(BUILD_DIR)%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTIONS) -o $@ $<
	@echo "[$(NAME)] Compiling $<"

clean:
	@rm -rf $(BUILD_DIR)
	@echo "File objects cleaned 🧼"

fclean: clean
	@rm -f $(NAME)
	@echo "[$(NAME)] Everything has been cleaned 🧼"
	@echo

re: fclean all

.PHONY: all clean fclean re

-include  $(DEPS)
