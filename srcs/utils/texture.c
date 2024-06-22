/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 16:59:26 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/23 01:27:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	load_texture(t_mlx *mlx, t_texture *texture, char *path)
{
	texture->img = mlx_xpm_file_to_image(mlx->mlx_ptr, path, &texture->width,
			&texture->height);
	if (!texture->img)
	{
		fprintf(stderr, "Error loading texture: %s\n", path);
		exit(EXIT_FAILURE);
	}
	texture->data = (int *)mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->size_line, &texture->endian);
	if (!texture->data)
	{
		fprintf(stderr, "Error getting texture data: %s\n", path);
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

int	calculate_texture_x(t_ray *ray, t_texture *texture)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = ray->map_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ray->map_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	// Calculer la coordonnée x de la texture
	tex_x = (int)(wall_x * (double)texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = texture->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = texture->width - tex_x - 1;
	return (tex_x);
}

static void texture_position(t_ray *ray, t_mlx *mlx, t_texture **texture)
{
	if (ray->side == 0)
	{
		if (ray->ray_dir_x > 0)
			*texture = &mlx->texture_north;
		else
			*texture = &mlx->texture_south;
	}
	else
	{
		if (ray->ray_dir_y > 0)
			*texture = &mlx->texture_east;
		else
			*texture = &mlx->texture_west;
	}
}

static void	fixed_texture(t_ray *ray, t_mlx *mlx, t_texture **texture, int *tex_x)
{
	double		wall_x;

	if (ray->side == 0)
		wall_x = mlx->map.player.corrdone.axe_ord + ray->perp_wall_dist
			* ray->ray_dir_y;
	else
		wall_x = mlx->map.player.corrdone.axe_abs + ray->perp_wall_dist
			* ray->ray_dir_x;
	wall_x -= floor(wall_x);
	*tex_x = (int)(wall_x * (double)(*texture)->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		*tex_x = (*texture)->width - *tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		*tex_x = (*texture)->width - *tex_x - 1;
}


void	display_of_wall(t_ray *ray, int x, t_mlx *mlx, int count)
{
	int			tex_x;
	int			tex_y;
	int			d;
	t_texture	*texture;

    texture_position(ray, mlx, &texture);
	fixed_texture(ray, mlx, &texture, &tex_x);
	while (count < ray->draw_end)
	{
		d = count * 256 - HEIGHT * 128 + ray->line_height * 128;
		tex_y = ((d * texture->height) / ray->line_height) / 256;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= texture->height)
			tex_y = texture->height - 1;
		mlx->pixel.color = texture->data[tex_y * texture->width + tex_x];
		put_pixel_to_img(&mlx->img, x, count, mlx->pixel.color);
		count++;
	}
}
