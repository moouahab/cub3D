/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:47:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 20:46:21 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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

int	key_press(int keysym, t_mlx *data)
{
	free_window(keysym, data);
    
    // move_camera(keysym, data); cette function va gere les movement de la carmera via les flecche du clavier
    
    // move_person(keysym, data); cette function va gere les movement du perso : 
    // - W = Avencer 
    // - S = Reculer 
    // - A = aller a gauche
    // - D = aller a droite
    return (0);
}

void	event_hook(t_mlx	*data)
{
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, window_close, data);
}