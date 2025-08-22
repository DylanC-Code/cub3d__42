/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dcastor <dcastor@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/09 15:08:01 by saal-kur          #+#    #+#             */
/*   Updated: 2025/08/22 10:36:07 by dcastor          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PARSING_H__
# define __PARSING_H__

# include <fcntl.h>

# define HEIGHT 0
# define WIDTH 1
# define HEIGHT_PADDING 4
# define WIDTH_PADDING 4

# define E_OPEN "Error\nCannot open file\n"

typedef struct s_map_data
{
	char				*line;
	int					length;
	struct s_map_data	*next;
}						t_map_data;

int						check_map(char *filename, t_scene *scene);
int						set_color(char id, char *color, t_textures *st);
int						parse_map_line(char *line, t_map_data **data);
int						is_empty_line(char *line);
char					**get_map(t_map_data *map, t_scene *sc);
int						validate_map_reqs(t_map_data *data);
void					free_dup(char **map, int total_height);
int						create_trgb(int t, int r, int g, int b);
int						skip_spaces(char *str, int i);

int						is_valid_char(char c);
int						is_valid_line(char *line);
int						count_players_in_line(char *line);
int						is_empty_line(char *line);
t_map_data				*new_elem(char *line);
void					ft_map_add_back(t_map_data **lst, t_map_data *new);
void					free_map_data_list(t_map_data *data);
int						check_line(char *line, int *player_count);
int						check_map_content(t_map_data *data);
int						validate_map_reqs(t_map_data *data);

int						read_elements(int fd, t_scene *scene, int *counter);
int						read_map(int fd, t_map_data **data);
int						load_file(int fd, t_scene *scene);
int						process_element(char *line, t_scene *scene,
							int *counter);
int						check_complete(t_textures *st);
void					empty_gnl_fd(int fd);
void					free_list(t_map_data *data);
int						store_color_info(t_textures *st, int id,
							char *color_str);
int						set_element_data(t_textures *st, char *line,
							char *data);
int						skip_elem_spaces(char *line);
int						extract_element_data(char *line, t_textures *st);
int						valid_id(char *line);
int						already_set(t_textures *st, char *line);
int						xpm_file(char *path);
int						store_texture_path(t_textures *st, int id, char *path);
int						only_spaces(char *line);
int						is_forbidden_next(char letter, char next_char);
int						check_single_id(char *line, int i, char letter);
int						check_double_id(char *line, int i, char *id_str);
int						get_texture_id(char *line, int i);
char					*s_strndup(char *s, size_t n);
char					*trim_spaces(char *str);
int						is_space(char c);
int						has_extension(char *filename, char *ext);
int						file_exists(char *path);
int						get_map_dimensions(int *height, int *width,
							t_map_data *map);
int						alloc_rows(char **arr, int total_height,
							int total_width);
int						copy_line_to_map(char *dest, char *src, int start_pos,
							int max_width);
int						fill_map_data(char **arr, t_map_data *map,
							int *dimensions);
int						fill_array(char **arr, t_map_data *map,
							int *dimensions);
char					**dup_map(char **map, int total_height);
void					free_dup(char **map, int total_height);
int						count_players(char **map, int *dimensions);
int						flood_check_outside(char **map, int *dims, int x,
							int y);
int						flood_check_inside(char **map, int *dims, int x, int y);
int						find_player_start(char **map, int *dims, int *px,
							int *py);
int						check_unreachable_spaces(char **map, int *dimensions);
int						is_enclosed(char **map, int *dimensions);
int						is_reachable(char **map, int *dimensions);
int						is_space_valid(char **map, int *dims, int x, int y);
int						validate_spaces(char **map, int *dimensions);
int						validate_map(char **map, int *dimensions);
char					**get_map(t_map_data *map, t_scene *sc);

#endif
