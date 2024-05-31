/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:45:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 10:55:53 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	data_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (error_msg("Error mlx_int", mlx->mlx_ptr));
    mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT,
			"CUB3D");
	if (!mlx->mlx_win)
		return (error_msg("Error window", mlx->mlx_ptr));
	mlx->img.img_ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	if (!mlx->img.img_ptr)
		return (error_msg("Error image", mlx->mlx_ptr));
	mlx->img.addr = mlx_get_data_addr(mlx->img.img_ptr, &mlx->img.bpp,
			&mlx->img.line_length, &mlx->img.endian);
    event_hook(mlx);
    return (true);
}