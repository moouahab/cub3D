/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:47:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 17:38:13 by moouahab         ###   ########.fr       */
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
		strafe_right(&data->map.player, data->map.map);
	else if (keysym == XK_D || keysym == XK_d)
		strafe_left(&data->map.player, data->map.map);
	else if (keysym == XK_Left || keysym == XK_Up)
		turn_right(&data->map.player);
	else if (keysym == XK_Right || keysym == XK_Down)
		turn_left(&data->map.player);
	raycasting(data);
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img.img_ptr, 0,
		0);
	return (0);
}

void	put_pixel_to_img(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		dst = img->addr + (y * img->line_length + x * (img->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

size_t	size_max_line(t_line *line)
{
	t_line	*head;
	size_t	size;

	if (line == NULL)
		return (-1);
	size = 0;
	head = line;
	while (head)
	{
		if (size < head->line_len)
			size = head->line_len;
		head = head->next;
	}
	return (size);
}

void	event_hook(t_mlx *data)
{
	mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, window_close,
		data);
	raycasting(data);
}
