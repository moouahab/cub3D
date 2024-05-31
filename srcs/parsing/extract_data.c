/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 12:50:57 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 11:09:38 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	return (free(line), NULL);
}

static bool	extract_texture_if_needed(char **texture, char *line,
		const char *pattern)
{
	if (*texture == NULL && ft_strnstr(line, pattern, ft_strlen(line)))
	{
		*texture = extract_texture_path(line, pattern[0], pattern[1], 0);
		if (!*texture || (*texture)[0] == 0 || *texture == NULL)
			return (free(line), false);
	}
	return (true);
}

static void	check_double_texture(char	*line, char const *str[4], int *i)
{
	int	j;

	j = 0;
	if (!i)
		*i = 0;
	while (j < 4)
	{
		if (ft_strncmp(line, str[j], 2) == 0)
			(*i)++;
		j++;
	}
}

bool	extract_data(t_map *map, char *line, int count_line)
{
	const char	*str[4] = {"NO", "SO", "WE", "EA"};
	static int	i;

	check_double_texture(line, str, &i);
	if (i > 4)
		return (free(line), false);
	if (i == 4 && map->line_texture == -1)
		map->line_texture = count_line;
	if (!extract_texture_if_needed(&map->texture_north, line, "NO")
		|| !extract_texture_if_needed(&map->texture_south, line, "SO")
		|| !extract_texture_if_needed(&map->texture_west, line, "WE")
		|| !extract_texture_if_needed(&map->texture_east, line, "EA"))
		return (false);
	else if (ft_strchr(line, 'F') || ft_strchr(line, 'C'))
		return (recovery_colors(line, &map, count_line));
	else if (!check_line(line) || (inside_map(line, map) && !check_line(line)))
		return (false);
	else if (inside_map(line, map))
		return (add_map_line(&map->line, line, map, count_line));
	return (free(line), true);
}
