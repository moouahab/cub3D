/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 13:42:19 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 13:44:58 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_texture(t_mlx *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		printf("Error loading texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
	texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		printf("Error getting texture data: %s\n", path);
		exit(EXIT_FAILURE);
	}
}

void	init_textures(t_mlx *mlx)
{
	load_texture(mlx, &mlx->texture_north, mlx->map.texture_north);
	load_texture(mlx, &mlx->texture_south, mlx->map.texture_south);
	load_texture(mlx, &mlx->texture_west, mlx->map.texture_west);
	load_texture(mlx, &mlx->texture_east, mlx->map.texture_east);
	free_texture(&mlx->map);
}
