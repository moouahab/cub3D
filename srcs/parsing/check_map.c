/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:47:23 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 23:05:16 by moouahab         ###   ########.fr       */
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

bool	extract_data(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO", ft_strlen(line)))
		map->texture_north = extract_texture_path(line, 'N', 'O', 0);
	else if (ft_strnstr(line, "SO", ft_strlen(line)))
		map->texture_south = extract_texture_path(line, 'S', 'O', 0);
	else if (ft_strnstr(line, "WE", ft_strlen(line)))
		map->texture_west = extract_texture_path(line, 'W', 'E', 0);
	else if (ft_strnstr(line, "EA", ft_strlen(line)))
		map->texture_east = extract_texture_path(line, 'E', 'A', 0);
	extract_colors(line, map);
	free(line);
	if (map->texture_north != NULL || map->texture_south != NULL
		|| map->texture_east != NULL || map->texture_west != NULL)
		return (true);
	else if (map->texture_north == NULL || map->texture_south == NULL
		|| map->texture_east == NULL || map->texture_west == NULL)
		return (false);
	return (true);
}

bool	check_argument(t_map *map)
{
	if (!ft_strcmp(map->texture_north, map->texture_south))
		return (false);
	if (!ft_strcmp(map->texture_west, map->texture_east))
		return (false);
	if (!ft_strcmp(map->texture_south, map->texture_east))
		return (false);
	if (!ft_strcmp(map->texture_north, map->texture_west))
		return (false);
	if (map->color_ceiling.blue == map->color_sol.blue
		&& map->color_sol.red == map->color_ceiling.red
		&& map->color_sol.green == map->color_ceiling.green)
		return (false);
	return (true);
}

bool	check_map(t_map *map, char *filename)
{
	char	*line;

	init_texture(&map);
	map->fd_file = open(filename, O_RDONLY);
	if (map->fd_file == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	line = get_next_line(map->fd_file);
	while (line != NULL)
	{
		if (!extract_data(map, line))
		{
			free_get_net_line(line, map->fd_file);
			return (ft_putstr_fd("\033[1;31mError: extract_data not success!\033[0m\n",
					STDERR_FILENO));
		}
		line = get_next_line(map->fd_file);
	}
	if (!check_argument(map))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
				STDERR_FILENO));
	close(map->fd_file);
	return (true);
}
