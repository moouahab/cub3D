/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:51 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/02 16:11:00 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

t_line	*init_line(void)
{
	return (NULL);
}

void	init_texture(t_map **map)
{
	(*map)->texture_east = NULL;
	(*map)->texture_west = NULL;
	(*map)->texture_south = NULL;
	(*map)->texture_north = NULL;
}

void	init_rgb(t_rgb *color)
{
	color->red = -1;
	color->blue = -1;
	color->green = -1;
}

void	data_map_init(t_map *map)
{
	map->beggin_map = false;
	init_texture(&map);
	init_rgb(&map->color_sol);
	init_rgb(&map->color_ceiling);
	map->line = init_line();
	map->map_width = 0;
	map->map_height = 0;
}
