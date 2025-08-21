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

# define E_OPEN "Error\nCannot open file\n"

typedef struct s_map_data
{
	char *line;
	int length;
	struct s_map_data *next;
} t_map_data;

int	check_map(char *filename, t_scene *scene);
int			set_color(char id, char *color, t_textures *st);
int			parse_map_line(char *line, t_map_data **data);
int			is_empty_line(char *line);
char		**get_map(t_map_data *map, t_scene *sc);
int			validate_map_reqs(t_map_data *data);
void	free_dup(char **map, int total_height);

#endif
