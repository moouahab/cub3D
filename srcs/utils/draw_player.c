/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 11:19:09 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/02 13:39:03 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	initialize_player(t_mlx *mlx, t_player *player, int *base_height,
		float *angle)
{
	mlx->pixel.color = 0xFF0000 >> 8;
	*base_height = 15 / 4;
	*angle = atan2(player->direction.dir_y, player->direction.dir_x);
}

void	draw_pixel(t_mlx *mlx, t_player *player,
		t_coordinates *coords)
{
	mlx->pixel.pixel_x = player->corrdone.axe_ord * 10 + coords->rotated_x;
	mlx->pixel.pixel_y = player->corrdone.axe_abs * 10 + coords->rotated_y;
	if (mlx->pixel.pixel_x < WIDTH && mlx->pixel.pixel_y < HEIGHT
		&& mlx->pixel.pixel_x >= 0 && mlx->pixel.pixel_y >= 0)
	{
		((int *)(mlx->img.addr))[mlx->pixel.pixel_y * WIDTH
			+ mlx->pixel.pixel_x] = mlx->pixel.color;
	}
}

void	rotate_coordinates(t_coordinates *coords, float angle)
{
	coords->rotated_x = cos(angle) * coords->local_x - sin(angle)
		* coords->local_y;
	coords->rotated_y = sin(angle) * coords->local_x + cos(angle)
		* coords->local_y;
}

void	draw_height_level(t_mlx *mlx, t_player *player, float angle,
		int height)
{
	int				j;
	t_coordinates	coords;

	j = -height;
	while (j <= height)
	{
		coords.local_x = j;
		coords.local_y = -height;
		rotate_coordinates(&coords, angle);
		draw_pixel(mlx, player, &coords);
		j++;
	}
}

void	draw_player(t_mlx *mlx, t_player *player)
{
	int		base_height;
	float	angle;
	int		i;

	initialize_player(mlx, player, &base_height, &angle);
	i = 0;
	while (i < base_height)
	{
		draw_height_level(mlx, player, angle, i);
		i++;
	}
}
