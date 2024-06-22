/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:21:02 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/06 19:06:28 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <stdbool.h>
#include <stdio.h>

bool	is_open_map(char **map, int i, int j)
{
	while (map[i] && map[i + 1])
	{
		j = -1;
		while (map[i][++j])
		{
			if (map[i][j] == ' ')
			{
				if ((map[i][j + 1] && map[i][j + 1] == '0') || (map[i + 1][j]
						&& map[i + 1][j] == '0') || (j > 0 && map[i][j - 1]
						&& map[i][j - 1] == '0') || (i > 0 && map[i - 1][j]
						&& map[i - 1][j] == '0'))
					return (false);
			}
			else if (map[i][j] == '0')
			{
				if ((map[i][j + 1] && map[i][j + 1] == ' ') || (map[i + 1][j]
						&& map[i + 1][j] == ' ') || (j > 0 && map[i][j - 1]
						&& map[i][j - 1] == ' ') || (i > 0 && map[i - 1][j]
						&& map[i - 1][j] == ' '))
					return (false);
			}
		}
		i++;
	}
	return (true);
}

bool	check_around_1(char **map, int i, int j)
{
	if (i < 1 || j < 1 || map[i + 1] == NULL || map[i][j + 1] == '\0')
		return (false);
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' '
		|| map[i][j + 1] == ' ')
	{
		return (false);
	}
	return (true);
}

bool	is_valid_position(char **map, int i, int j, t_col_row col)
{
	if (i < 0 || j < 0 || i >= col.row || j >= col.col)
		return (false);
	return (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S'
		|| map[i][j] == 'W' || map[i][j] == 'E');
}

bool	can_player_move(char **map, int i, int j)
{
	int			rows;
	int			cols;
	t_col_row	col;

	rows = 0;
	while (map[rows])
		rows++;
	cols = ft_strlen(map[0]);
	col.row = rows;
	col.col = cols;
	if (is_valid_position(map, i - 1, j, col) || is_valid_position(map, i + 1,
			j, col) || is_valid_position(map, i, j - 1, col)
		|| is_valid_position(map, i, j + 1, col))
		return (true);
	return (false);
}

bool	check_player(char **str, t_player *player)
{
	if (!check_double_player(str, player))
		return (false);
	if (!check_around_1(str, player->corrdone.axe_abs,
			player->corrdone.axe_ord))
		return (false);
	if (!can_player_move(str, player->corrdone.axe_abs,
			player->corrdone.axe_ord))
		return (false);
	return (true);
}
