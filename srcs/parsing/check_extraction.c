/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_extraction.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:37:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/01 13:21:00 by moouahab         ###   ########.fr       */
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

bool	check_argument(t_map *map)
{
	if (!map->texture_north || !map->texture_south || !map->texture_west
		|| !map->texture_east)
		return (ft_putstr_fd("\033[1;31mError\nextract_data not success!\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_south))
		return (ft_putstr_fd("\033[1;31mError\nnot argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_west, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError\nnot argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_south, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError\nnot argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_west))
		return (ft_putstr_fd("\033[1;31mError\nnot argument valid\033[0m\n",
				STDERR_FILENO));
	if (!is_init_color(map))
		return (ft_putstr_fd("\033[1;31mError\nnot argument valid\033[0m\n",
				STDERR_FILENO));
	if (map->beggin_map == false)
		return (ft_putstr_fd("\033[1;31mError\nmap not find\033[0m\n",
				STDERR_FILENO));
	return (true);
}

bool	verify_map(t_map *map)
{
	t_line	*current;

	current = map->line;
	map->map = list_to_array(current, map->map_height, map->map_width);
	if (!map->map)
		return (false);
	if (!check_around_2(map->map, 0))
		return (false);
	if (!check_double_player(map->map, &map->player))
		return (false);
	if (!check_player(map->map, &map->player))
		return (false);
	return (true);
}

bool	check_extraction(t_map *map, char *filename)
{
	char	*line;
	int		i;

	i = 0;
	map->fd_file = open(filename, O_RDONLY);
	if (map->fd_file == -1)
		return (ft_putstr_fd("Error\n", STDERR_FILENO));
	line = get_next_line(map->fd_file);
	while (line != NULL)
	{
		if (!extract_data(map, line, i))
		{
			free_get_net_line(line, map->fd_file);
			return (ft_putstr_fd("\033[1;31mError\nextract_data not success\
 !\033[0m\n", STDERR_FILENO));
		}
		line = get_next_line(map->fd_file);
		i++;
	}
	close(map->fd_file);
	if (map->line_map < map->line_color + map->line_texture
		|| !witdh_and_heigth_map(map))
		return (ft_putstr_fd("\033[1;31mError\nmap is not correct!\033[0m\n",
				STDERR_FILENO));
	return (check_argument(map));
}
