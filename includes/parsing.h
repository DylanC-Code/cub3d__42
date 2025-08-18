/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-09 15:08:01 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-09 15:08:01 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef __PARSING_H__
# define __PARSING_H__

#include <fcntl.h>

#define HEIGHT 0
#define WIDTH 1
#define HEIGHT_PADDING 4
#define WIDTH_PADDING  4

typedef struct s_map_data
{
	char *line;
	int length;
	struct s_map_data *next;
} t_map_data;

int check_map(char *filename);
int is_space(char c);
t_map_data *parse_map_line(char *line);
int only_whitespace_after(char *line);
int set_color(char id, char *color, t_textures *st);
int is_empty_line(char *line);
char *clean_copy(char *str);
char **get_map(t_map_data *map, t_scene *sc);


#endif
