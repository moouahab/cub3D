/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:47:23 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/02 10:55:50 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	find_path(char *line)
{
	int	i;

	i = 0;
	while ((line[i] < 14 && line[i] > 8) || line[i] == 32)
		i++;
	while (line[i] && line[i] > 32 && line[i] < 126)
		i++;
	while ((line[i] < 14 && line[i] > 8) || line[i] == 32)
		i++;
	return (i);
}

char	*extract_texture_path(char *line, char c, char y, int i)
{
	const int	len = ft_strlen(line) - find_path(line);
	const int	start = find_path(line);

	while (line[i])
	{
		if (line[i] == c && line[i + 1] == y)
			return (ft_substr(line, start, len - 1));
		i++;
	}
	free(line);
	return (NULL);
}

static bool	extract_texture_if_needed(char **texture, char *line,
		const char *pattern)
{
	if (*texture == NULL && ft_strnstr(line, pattern, ft_strlen(line)))
	{
		*texture = extract_texture_path(line, pattern[0], pattern[1], 0);
		if (!*texture || (*texture)[0] == 0 || *texture == NULL)
		{
			free(line);
			return (false);
		}
	}
	return (true);
}

bool	extract_data(t_map *map, char *line)
{
	if (!extract_texture_if_needed(&map->texture_north, line, "NO")
		|| !extract_texture_if_needed(&map->texture_south, line, "SO")
		|| !extract_texture_if_needed(&map->texture_west, line, "WE")
		|| !extract_texture_if_needed(&map->texture_east, line, "EA"))
		return (false);
	else if (ft_strchr(line, 'F') || ft_strchr(line, 'C'))
		return (extract_colors(line, &map));
	else if (!check_line(line) || (inside_map(line, map) && !check_line(line)))
		return false;
	else if (inside_map(line, map))
		return add_map_line(&map->line, line);
	free(line);
	return (true);
}

bool	check_argument(t_map *map)
{
	if (!map->texture_north || !map->texture_south || !map->texture_west
		|| !map->texture_east)
		return (ft_putstr_fd("\033[1;31mError: extract_data not success !\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_south))
		return (ft_putstr_fd("\033[1;31mError: not argument valid 1\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_west, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError: not argument valid 2\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_south, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError: not argument valid 3\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_west))
		return (ft_putstr_fd("\033[1;31mError: not argument valid 4\033[0m\n",
				STDERR_FILENO));
	if (map->color_ceiling.blue == map->color_sol.blue
		&& map->color_sol.red == map->color_ceiling.red
		&& map->color_sol.green == map->color_ceiling.green)
		return (ft_putstr_fd("\033[1;31mError: not argument valid 5\033[0m\n",
				STDERR_FILENO));
	if (map->beggin_map == false)
		return (ft_putstr_fd("\033[1;31mError: map not find\033[0m\n",
				STDERR_FILENO));
	return (true);
}

/**
 * check_map va ouvir un fichier esser de le lire avec
 * avec gnl chaque line sera stkoer et liber achaque fois
 * grace a extract_data qui recuper chaque donne qui ce trouve 
 * dans le fichier est verifier que l'extraction c'est bien passer
 * 
 * 
 * une verification est pour savoir si le donner son bonne  
 * 
 * 
*/

bool	check_map(t_map *map, char *filename)
{
	char	*line;

	map->fd_file = open(filename, O_RDONLY);
	if (map->fd_file == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	line = get_next_line(map->fd_file);
	while (line != NULL)
	{
		if (!extract_data(map, line))
		{
			free_get_net_line(line, map->fd_file);
			return (ft_putstr_fd("\033[1;31mError: extract_data not success !\033[0m\n",
					STDERR_FILENO));
		}
		line = get_next_line(map->fd_file);
	}
	close(map->fd_file);
	t_line *head  = map->line;
	while (head)
	{
		printf("line : %s\n", head->line);;
		head = head->next;
	}
	if (!is_init_color(map))
		return (ft_putstr_fd("\033[1;31mError: color not init!\033[0m\n",
					STDERR_FILENO));
	return (check_argument(map));
}
