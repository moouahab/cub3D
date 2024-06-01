/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:09:33 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/01 22:31:49 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	init_noth(t_player *player)
{
	player->direction.dir_x = -1;
	player->direction.dir_y = 0;
	player->camera.planeX = 0;
	player->camera.planeY = 0.66;
}

void	init_east(t_player *player)
{
	player->direction.dir_x = 0;
	player->direction.dir_y = 1;
	player->camera.planeX = 0.66;
	player->camera.planeY = 0;
}

void	init_player(t_player *player)
{
	int			i;
	const char	character[2] = {'N', 'E'};

	void (*f[2])(t_player *) = {init_noth, init_east};
	i = -1;
	while (++i < 2)
		if (character[i] == player->orientation)
		{
			f[i](player);
			break ;
		}
	if (player->orientation == 'S')
	{
		player->direction.dir_x = 1;
		player->direction.dir_y = 0;
		player->camera.planeX = 0;
		player->camera.planeY = -0.66;
	}
	else if (player->orientation == 'W')
	{
		player->direction.dir_x = 0;
		player->direction.dir_y = -1;
		player->camera.planeX = -0.66;
		player->camera.planeY = 0;
	}
}

static bool	is_player(const char strs[4], char *str, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (strs[j])
		{
			if (str[i] == strs[j])
			{
				player->corrdone.axe_ord = i;
				player->orientation = str[i];
				return (true);
			}
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_double_player(char **str, t_player *player)
{
	int i;
	int j;
	const char oriantation[4] = {'N', 'S', 'W', 'E'};

	i = 0;
	j = 0;
	player->orientation = '\0';
	player->corrdone.axe_ord = -1;
	player->corrdone.axe_abs = -1;
	while (str[i])
	{
		if (is_player(oriantation, str[i], player))
		{
			player->corrdone.axe_abs = i;
			j++;
		}
		i++;
	}
	init_player(player);
	if (j > 1)
		return (false);
	return (true);
}