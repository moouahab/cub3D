/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:36:50 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/02 11:18:29 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

static void mapping(t_mlx *mlx, int i,int x, int y)
{
    int color;
    int j;
    
    if (mlx->map.map[y][x] == '1')
        color = 0xFFFFFF;
    else
        color = 0x000000;
    while (++i < 10)
    {
        j = -1;
        while (++j < 15)
        {
            mlx->pixel.pixel_x = x * 10 + i;
            mlx->pixel.pixel_y = y * 10 + j;
            if (mlx->pixel.pixel_x < WIDTH && mlx->pixel.pixel_y < HEIGHT)
                ((int *)(mlx->img.addr))[mlx->pixel.pixel_y * WIDTH
                    + mlx->pixel.pixel_x] = color;
        }
    }
}

void	draw_map(t_mlx *mlx)
{
	int x;
    int y;
    
    y = 0;
	while (y < mlx->map.map_height)
	{
        x = 0;
        while (x < mlx->map.map_width)
		{
            mapping(mlx, -1, x, y);
            x++;
		}
        y++;
	}
}
