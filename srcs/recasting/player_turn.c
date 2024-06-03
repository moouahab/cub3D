/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_turn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:23:07 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/03 14:20:28 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	turn_left(t_player *player)
{
	double	old_dirx;
	double	old_planex;
	double	cos_angle;
	double	sin_angle;

	old_dirx = player->direction.dir_x;
	old_planex = player->camera.planex;
	cos_angle = cos(-ROT_SPEED);
	sin_angle = sin(-ROT_SPEED);
	player->direction.dir_x = old_dirx * cos_angle - player->direction.dir_y
		* sin_angle;
	player->direction.dir_y = old_dirx * sin_angle + player->direction.dir_y
		* cos_angle;
	player->camera.planex = old_planex * cos_angle - player->camera.planey
		* sin_angle;
	player->camera.planey = old_planex * sin_angle + player->camera.planey
		* cos_angle;
}

void	turn_right(t_player *player)
{
	double	old_dirx;
	double	old_planex;
	double	cos_angle;
	double	sin_angle;

	old_dirx = player->direction.dir_x;
	old_planex = player->camera.planex;
	cos_angle = cos(ROT_SPEED);
	sin_angle = sin(ROT_SPEED);
	player->direction.dir_x = old_dirx * cos_angle - player->direction.dir_y
		* sin_angle;
	player->direction.dir_y = old_dirx * sin_angle + player->direction.dir_y
		* cos_angle;
	player->camera.planex = old_planex * cos_angle - player->camera.planey
		* sin_angle;
	player->camera.planey = old_planex * sin_angle + player->camera.planey
		* cos_angle;
}
