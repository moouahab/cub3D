/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:45:37 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/23 00:14:24 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_texture_paths(t_mlx *mlx, t_map *textures)
{
	int		width;
	int		height;
	void	*img;

	img = mlx_xpm_file_to_image(mlx->mlx_ptr, textures->texture_north, &width,
			&height);
	if (img == NULL || !img)
		return (false);
	mlx_destroy_image(mlx->mlx_ptr, img);
	img = mlx_xpm_file_to_image(mlx->mlx_ptr, textures->texture_south, &width,
			&height);
	if (img == NULL)
		return (false);
	mlx_destroy_image(mlx->mlx_ptr, img);
	img = mlx_xpm_file_to_image(mlx->mlx_ptr, textures->texture_east, &width,
			&height);
	if (img == NULL)
		return (false);
	mlx_destroy_image(mlx->mlx_ptr, img);
	img = mlx_xpm_file_to_image(mlx->mlx_ptr, textures->texture_west, &width,
			&height);
	if (img == NULL)
		return (false);
	mlx_destroy_image(mlx->mlx_ptr, img);
	return (true);
}

bool	data_init(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (error_msg("Error mlx_int", mlx->mlx_ptr));
	if (!check_texture_paths(mlx, &mlx->map))
		return (error_msg("texture is not correcte", mlx->mlx_ptr));
	init_textures(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "CUB3D");
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
