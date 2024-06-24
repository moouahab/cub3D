/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 11:36:36 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 16:50:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	free_texture_img(t_mlx *mlx, t_texture *texture)
{
	if (texture->img)
		mlx_destroy_image(mlx->mlx_ptr, texture->img);
}

void	free_textures_img(t_mlx *mlx)
{
	free_texture_img(mlx, &mlx->texture_north);
	free_texture_img(mlx, &mlx->texture_south);
	free_texture_img(mlx, &mlx->texture_west);
	free_texture_img(mlx, &mlx->texture_east);
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
	free_textures_img(data);
	mlx_destroy_window(data->mlx_ptr, data->mlx_win);
	mlx_destroy_image(data->mlx_ptr, data->img.img_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_tab2(data->map.map);
	free_extraction(&data->map, false);
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
