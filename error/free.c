/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:36 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 09:39:08 by moouahab         ###   ########.fr       */
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

void	free_extraction(t_map *map)
{
    if (map->texture_north != NULL)
	    free(map->texture_north);
	if (map->texture_south != NULL)
        free(map->texture_south);
	if (map->texture_east != NULL)
        free(map->texture_east);
	if (map->texture_west != NULL)
        free(map->texture_west);
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

int	window_close(t_mlx	*data)
{
	exit_msg();
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
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