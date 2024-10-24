/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 16:47:38 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 16:52:24 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_map_lines(t_line *head)
{
	t_line	*current;
	t_line	*next;

	current = head;
	while (current != NULL)
	{
		next = current->next;
		free(current->line);
		free(current);
		current = next;
	}
}

void	free_texture(t_map *map)
{
	if (map->texture_north != NULL && map->texture_north)
		free(map->texture_north);
	if (map->texture_south != NULL && map->texture_south)
		free(map->texture_south);
	if (map->texture_east != NULL && map->texture_east)
		free(map->texture_east);
	if (map->texture_west != NULL && map->texture_west)
		free(map->texture_west);
}

void	free_extraction(t_map *map, bool is_free)
{
	if (is_free)
		free_texture(map);
	if (map->line)
		free_map_lines(map->line);
}
