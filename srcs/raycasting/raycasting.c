/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/05 16:14:47 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/24 13:45:37 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_ray(t_ray *ray, t_mlx *mlx, int x)
{
	ray->camera_x = 2 * x / (double)WIDTH - 1;
	ray->ray_dir_x = mlx->map.player.direction.dir_x
		+ mlx->map.player.camera.planex * ray->camera_x;
	ray->ray_dir_y = mlx->map.player.direction.dir_y
		+ mlx->map.player.camera.planey * ray->camera_x;
	ray->map_x = (int)mlx->map.player.corrdone.axe_abs;
	ray->map_y = (int)mlx->map.player.corrdone.axe_ord;
	ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	perform_dda(t_ray *ray, t_mlx *mlx)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (mlx->map.map[ray->map_x][ray->map_y] == '1')
			ray->hit = 1;
	}
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - mlx->map.player.corrdone.axe_abs
				+ (1 - ray->step_x) / 2) / ray->ray_dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - mlx->map.player.corrdone.axe_ord
				+ (1 - ray->step_y) / 2) / ray->ray_dir_y;
}

void	calculate_step_and_side_dist(t_ray *ray, t_mlx *mlx)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (mlx->map.player.corrdone.axe_abs - ray->map_x)
			* ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - mlx->map.player.corrdone.axe_abs)
			* ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (mlx->map.player.corrdone.axe_ord - ray->map_y)
			* ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1.0 - mlx->map.player.corrdone.axe_ord)
			* ray->delta_dist_y;
	}
}

void	calculate_draw_limits(t_ray *ray)
{
	ray->line_height = (int)(HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + HEIGHT / 2;
	if (ray->draw_end >= HEIGHT)
		ray->draw_end = HEIGHT - 1;
}

void	raycasting(t_mlx *mlx)
{
	int		x;
	t_ray	ray;

	draw_ceiling(&mlx->map, &mlx->img);
	draw_sol(&mlx->map, &mlx->img);
	x = 0;
	while (x < WIDTH)
	{
		init_ray(&ray, mlx, x);
		calculate_step_and_side_dist(&ray, mlx);
		perform_dda(&ray, mlx);
		calculate_draw_limits(&ray);
		display_of_wall(&ray, x, mlx, ray.draw_start);
		x++;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->img.img_ptr, 0, 0);
}
