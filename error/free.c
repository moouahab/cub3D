/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:36 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 22:57:46 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_cardinal(t_map *map)
{
    if (map->texture_north)
	    free(map->texture_north);
	if (map->texture_south)
        free(map->texture_south);
	if (map->texture_east)
        free(map->texture_east);
	if (map->texture_west)
        free(map->texture_west);
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