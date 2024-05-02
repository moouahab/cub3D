/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:47:23 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/02 12:51:39 by moouahab         ###   ########.fr       */
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
		return (ft_putstr_fd("\033[1;31mError: extract_data not success !\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_south))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_west, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_south, map->texture_east))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
				STDERR_FILENO));
	if (!ft_strcmp(map->texture_north, map->texture_west))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
				STDERR_FILENO));
	if (!is_init_color(map))
		return (ft_putstr_fd("\033[1;31mError: not argument valid\033[0m\n",
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
	return (check_argument(map));
}
