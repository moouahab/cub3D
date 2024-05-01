/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 10:35:51 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/01 13:20:17 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_texture(t_map	**map)
{
	(*map)->texture_east = NULL;
	(*map)->texture_west = NULL;
    (*map)->texture_south = NULL;
	(*map)->texture_north = NULL;
}

void	init_rgb(t_rgb *color)
{
	color->red = 0;
	color->blue = 0;
	color->green = 0;
}

void	data_map_init(t_map *map)
{
    map->beggin_map = false;
	init_texture(&map);
	init_rgb(&map->color_sol);
	init_rgb(&map->color_ceiling);
}
