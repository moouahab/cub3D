/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:36 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/22 16:05:42 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * Libère toute la mémoire utilisée par la liste chaînée de lignes de la carte.
 * @param head La tête de la liste chaînée.
 */
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


void    free_texture(t_map *map)
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


void	free_extraction(t_map *map)
{
	free_texture(map);
	if (map->line)
		free_map_lines(map->line);
}

void	free_get_net_line(char *line, int fd_file)
{
	while (line != NULL)
	{
		line = get_next_line(fd_file);
		free(line);
	}
	close(fd_file);
}

int	window_close(t_mlx *data)
{
	exit_msg();
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab2(data->map.map);
	free_extraction(&data->map);
	close(data->map.fd_file);
	exit(EXIT_SUCCESS);
	return (1);
}

int	free_window(int keysym, t_mlx *data)
{
	if (keysym == XK_Escape || keysym == XK_c)
		window_close(data);
	return (EXIT_FAILURE);
}
