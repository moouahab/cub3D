/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 23:42:49 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/06 10:20:44 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

/**
 * Ces fonctions permettent de gérer les déplacements et
 * les rotations du joueur dans le jeu. Voici un résumé
 * rapide de chaque fonction :
 *
 * move_forward : Avance le joueur dans la direction où il regarde.
 * move_backward : Recule le joueur dans la direction opposée à
 * celle où il regarde.
 *
 * turn_left : Fait tourner le joueur vers la gauche.
 * turn_right : Fait tourner le joueur vers la droite.
 *
 * Ces fonctions sont essentielles pour offrir une expérience de
 * jeu fluide et réactive.
 * Elles utilisent des formules simples mais efficaces pour
 * déplacer le joueur dans un environnement 3D basé sur une carte 2D.
 */

void	move_forward(t_player *player, char **map)
{
	if (map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'W'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'N'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'S'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'E')
		map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord)] \
	= '0';
	if (map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == '0')
		player->corrdone.axe_abs += player->direction.dir_x * MOVE_SPEED;
	if (map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord
			+ player->direction.dir_y * MOVE_SPEED)] == '0')
		player->corrdone.axe_ord += player->direction.dir_y * MOVE_SPEED;
}

void	strafe_left(t_player *player, char **map)
{
	double	move_x;
	double	move_y;

	move_x = player->direction.dir_y * MOVE_SPEED;
	move_y = -player->direction.dir_x * MOVE_SPEED;
	if (map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'W'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'N'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'S'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'E')
		map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord)] \
	= '0';
	if (map[(int)(player->corrdone.axe_abs
			+ move_x)][(int)(player->corrdone.axe_ord)] == '0')
		player->corrdone.axe_abs += move_x;
	if (map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord
			+ move_y)] == '0')
		player->corrdone.axe_ord += move_y;
}

void	strafe_right(t_player *player, char **map)
{
	double	move_x;
	double	move_y;

	move_x = -player->direction.dir_y * MOVE_SPEED;
	move_y = player->direction.dir_x * MOVE_SPEED;
	if (map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'W'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'N'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'S'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'E')
		map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord)] \
	= '0';
	if (map[(int)(player->corrdone.axe_abs
			+ move_x)][(int)(player->corrdone.axe_ord)] == '0')
		player->corrdone.axe_abs += move_x;
	if (map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord
			+ move_y)] == '0')
		player->corrdone.axe_ord += move_y;
}

void	move_backward(t_player *player, char **map)
{
	if (map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'W'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'N'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'S'
		|| map[(int)(player->corrdone.axe_abs + player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == 'E')
		map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord)] \
	= '0';
	if (map[(int)(player->corrdone.axe_abs - player->direction.dir_x
			* MOVE_SPEED)][(int)(player->corrdone.axe_ord)] == '0')
		player->corrdone.axe_abs -= player->direction.dir_x * MOVE_SPEED;
	if (map[(int)(player->corrdone.axe_abs)][(int)(player->corrdone.axe_ord
			- player->direction.dir_y * MOVE_SPEED)] == '0')
		player->corrdone.axe_ord -= player->direction.dir_y * MOVE_SPEED;
}
