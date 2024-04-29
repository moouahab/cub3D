/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_color.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:56:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 21:18:41 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_color(t_rgb **color, int i, char *tmp)
{
	char	*rgb;

	(*color)->red = 0;
	(*color)->blue = 0;
	(*color)->green = 0;
	rgb = ft_strtok(tmp, ",");
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
}

void	extract_color(t_rgb *color, char *line, int i, char c)
{
	char		*tmp;
	const int	len = ft_strlen(line) - find_path(line);
	const int	start = find_path(line);

	while (line[i])
	{
		if (line[i] == c)
			tmp = ft_substr(line, start, len - 1);
		i++;
	}
	init_color(&color, 0, tmp);
	return (free(tmp));
}

void	extract_colors(char *line, t_map *map)
{
	if (ft_strnstr(line, "F", ft_strlen(line)))
		extract_color(&map->color_sol, line, 0, 'F');
	if (ft_strnstr(line, "C", ft_strlen(line)))
		extract_color(&map->color_ceiling, line, 0, 'C');
}