/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 22:09:33 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/06 18:59:58 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

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
	int			i;
	int			j;
	const char	oriantation[4] = {'N', 'S', 'W', 'E'};

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
	player->corrdone.axe_ord = player->corrdone.axe_ord + 0.5;
	player->corrdone.axe_abs = player->corrdone.axe_abs + 0.5;
	if (j > 1)
		return (false);
	return (true);
}
