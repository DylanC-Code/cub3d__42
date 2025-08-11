/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saal-kur <saal-kur@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-08-08 19:13:53 by saal-kur          #+#    #+#             */
/*   Updated: 2025-08-08 19:13:53 by saal-kur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*s_strndup(char *s, size_t n)
{
	size_t	i;
	size_t	len;
	char	*dup;

	if (!s)
		return (NULL);
	len = 0;
	while (s[len] && len < n)
		len++;
	dup = (char *)malloc(len + 1);
	if (!dup)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

int is_space(char c)
{
	return (c == ' ' || c == '\t');
}
int is_valid_direction(char *dir)
{
	if (!dir || !*dir)
		return (0);
	if (*dir == 'N' || *dir == 'S' || *dir == 'W' || *dir == 'E' || *dir == 'F' || *dir == 'C')
		return (1);
	if (ft_strncmp(dir, "NO", 2) == 0 || ft_strncmp(dir, "SO", 2) == 0 ||
		 ft_strncmp(dir, "WE", 2) == 0 || ft_strncmp(dir, "EA", 2) == 0)
		return (1);

	return (0);
}
int only_whitespace_after(char *line)
{
	while(*line && is_space(*line))
		line++;
	if(*line == 0 || *line == '\n')
		return 1;
	return 0;
}

int set_texture(char *line, t_textures *st, int path_i, int len)
{
	int i;
	char *path;

	i = 0;
	while(is_space(line[i]))
		i++;
	path = s_strndup(line + path_i, len);
	if(!path)
		return 0;
	if(line[i] == 'N')
		st->north = path;
	else if(line[i] == 'S')
		st->south = path;
	else if(line[i] == 'W')
		st->west = path;
	else if(line[i] == 'E')
		st->east = path;
	else
	{
		free(path);
		return 0;
	}
	return 1;
}

int get_texture_path(char *line, t_textures *st)
{
	int i;
	int k;

	i = 0;
	while(is_space(line[i]))
			i++;
	while(!is_space(line[i]) && line[i])
		i++;
	if(!line[i] || line[i] == '\n')
		return 0;
	while(is_space(line[i]))
			i++;
	k = i;
	while(!is_space(line[i]) && line[i])
		i++;
	if(only_whitespace_after(&line[i]))
		set_texture(line, st, k, i - k);
	else
		return 0;
	return 1;
}
int check_textures(char *line, t_scene *scene, int *counter)
{
	int i;

	i = 0;
	while(line[i])
	{
		while(is_space(line[i]))
			i++;
		if(is_valid_direction(line))
		{
			while(is_space(line[i]))
				i++;
			return (*counter)++, get_texture_path(line, &scene->textures);
		}
		else
			return 0;
	}
	return 0;
}

int check_format(int fd, t_scene *scene)
{
	char *line;
	int counter;
	int ret;

	ret = 1;
	counter = 0;
	line = get_next_line(fd);
	while(line)
	{
		if(counter != 6)
			ret = check_textures(line, scene, &counter);
		else
			//check_map
		free(line);
		if(!ret)
			break;
		line = get_next_line(fd);
	}
	if(line)
		free(line);
	return ret;
}
void	print_textures(t_textures *tex)
{
	printf("north: %s\n", tex->north ? tex->north : "(null)");
	printf("south: %s\n", tex->south ? tex->south : "(null)");
	printf("west:  %s\n", tex->west  ? tex->west  : "(null)");
	printf("east:  %s\n", tex->east  ? tex->east  : "(null)");
	printf("floor_color: %d\n", tex->floor_color);
	printf("ceil_color:  %d\n", tex->ceil_color);
}

int check_map(char *filename)
{
	int fd;
	t_textures tex = {0};
	t_scene scene;

	scene.textures = tex;
	fd = open(filename, O_RDONLY);
	if(fd == -1)
		return 0;
	int ret = check_format(fd, &scene);
	print_textures(&tex);
	return ret;
}