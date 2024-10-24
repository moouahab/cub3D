/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pos.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:00:33 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/10 14:26:21 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_north(t_player *player)
{
	player->direction.dir_x = -1;
	player->direction.dir_y = 0;
	player->camera.planex = 0;
	player->camera.planey = 0.66;
}

void	init_east(t_player *player)
{
	player->direction.dir_x = 0;
	player->direction.dir_y = 1;
	player->camera.planex = 0.66;
	player->camera.planey = 0;
}

void	init_south(t_player *player)
{
	player->direction.dir_x = 1;
	player->direction.dir_y = 0;
	player->camera.planex = 0;
	player->camera.planey = -0.66;
}

void	init_west(t_player *player)
{
	player->direction.dir_x = 0;
	player->direction.dir_y = -1;
	player->camera.planex = -0.66;
	player->camera.planey = 0;
}

void	init_player(t_player *player)
{
	int			i;
	void		(*f[4])(t_player *);
	const char	character[4] = {'N', 'E', 'S', 'W'};

	f[0] = init_north;
	f[1] = init_east;
	f[2] = init_south;
	f[3] = init_west;
	i = 0;
	while (i < 4)
	{
		if (character[i] == player->orientation)
		{
			f[i](player);
			break ;
		}
		i++;
	}
}
