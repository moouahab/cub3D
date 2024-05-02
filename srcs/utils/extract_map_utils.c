/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:56:27 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/02 12:56:57 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	find_line_first_end_last_map(char *line)
{
	int			i;
	static bool	inside_map = false;

	i = 0;
	while (i < (int)ft_strlen(line) - 1)
	{
		if (line[i] == '1' || line[i] == ' ')
			inside_map = true;
		else
		{
			inside_map = false;
			break ;
		}
		i++;
	}
	return (inside_map);
}

bool	inside_map(char *line, t_map *map)
{
	static int	passage;

	if (!line)
		return (false);
	if (!passage && find_line_first_end_last_map(line))
	{
		passage = 1;
		map->beggin_map = true;
	}
	else if (passage == 1 && !find_line_first_end_last_map(line))
		passage = 2;
	return (map->beggin_map);
}

bool	check_line(char *line)
{
	int	i;

	i = 0;
	if (ft_strnstr(line, "NO", ft_strlen(line)) || ft_strnstr(line, "EA",
			ft_strlen(line)) || ft_strnstr(line, "SO", ft_strlen(line))
		|| ft_strnstr(line, "WE", ft_strlen(line)))
		return (true);
	while (line[i] && i < (int)ft_strlen(line))
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != ' ' && line[i] != 'N'
			&& line[i] != '\n')
		{
			printf("je suis %s\n", line);
			free(line);
			return (false);
		}
		i++;
	}
	return (true);
}