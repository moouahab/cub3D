/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:56:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 10:26:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	init_color(t_rgb **color, int i, char *tmp)
{
	char	*rgb;

	rgb = ft_strtok(tmp, ",");
	if (rgb == NULL)
	{
		free(tmp);
		return (false);
	}
	while (rgb != NULL && i <= 3)
	{
		if (i == 0)
			(*color)->green = ft_atoi(rgb);
		else if (i == 1)
			(*color)->red = ft_atoi(rgb);
		else if (i == 2)
			(*color)->blue = ft_atoi(rgb);
		rgb = ft_strtok(NULL, ", ");
		i++;
	}
	free(tmp);
	return (true);
}

bool	extract_color(t_rgb *color, char *line, int i, char c)
{
	char		*tmp;
	const int	len = ft_strlen(line) - find_path(line);
	const int	start = find_path(line);

	while (line[i])
	{
		if (line[i] == c)
		{
			tmp = ft_substr(line, start, len - 1);
			break ;
		}
		i++;
	}
	free(line);
	return (init_color(&color, 0, tmp));
}

bool	recovery_colors(char *line, t_map **map, int i)
{
	if (ft_strchr(line, 'F'))
	{
		if (!((*map)->color_sol.blue < 0) || !((*map)->color_sol.green < 0)
			|| !((*map)->color_sol.red < 0))
		{
			free(line);
			return (false);
		}
		(*map)->line_color = i;
		return (extract_color(&(*map)->color_sol, line, 0, 'F'));
	}
	if (ft_strchr(line, 'C'))
	{
		if (!((*map)->color_ceiling.blue < 0)
			|| !((*map)->color_ceiling.green < 0)
			|| !((*map)->color_ceiling.red < 0))
		{
			free(line);
			return (false);
		}
		(*map)->line_color = i;
		return (extract_color(&(*map)->color_ceiling, line, 0, 'C'));
	}
	return (false);
}

bool	is_init_color(t_map *map)
{
	if (map->color_sol.blue < 0 || map->color_sol.red < 0
		|| map->color_sol.green < 0)
		return (false);
	if (map->color_ceiling.blue < 0 || map->color_ceiling.red < 0
		|| map->color_ceiling.green < 0)
		return (false);
	if (map->color_ceiling.blue == map->color_sol.blue
		&& map->color_sol.red == map->color_ceiling.red
		&& map->color_sol.green == map->color_ceiling.green)
		return (ft_putstr_fd("\033[1;31mError\n not argument valid \033[0m\n",
				STDERR_FILENO));
	return (true);
}
