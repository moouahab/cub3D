/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:47:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/02 11:23:48 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int keysym, t_mlx *data)
{
	free_window(keysym, data);
	if (keysym == XK_W || keysym == XK_w)
		move_forward(&data->map.player, data->map.map);
	else if (keysym == XK_S || keysym == XK_s)
		move_backward(&data->map.player, data->map.map);
	else if (keysym == XK_A || keysym == XK_a)
		turn_left(&data->map.player);
	else if (keysym == XK_D || keysym == XK_d)
		turn_right(&data->map.player);
    draw_map(data);
    draw_player(data, &data->map.player);
    mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0, 0);
	return (0);
}

void	event_hook(t_mlx *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, window_close,
		data);
    draw_map(data);
	draw_player(data, &data->map.player);
}