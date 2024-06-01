/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:21:02 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/01 14:16:21 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

bool	check_around_2(char **map, int i)
{
	int	j;

	while (map[i] && map[i + 1])
	{
		j = 0;
		while (map[i][j] && map[i][j + 1] != '\0')
		{
			if (map[i][j] == ' ')
			{
				if ((map[i][j + 1] == '0') || (map[i + 1][j] && map[i + 1][j]
						&& map[i + 1][j] == '0'))
					return (false);
				else
					break ;
			}
			if (map[i][j] == '0')
				if ((map[i][j + 1] == ' ') || (map[i + 1] && map[i + 1][j]
						&& map[i + 1][j] == ' '))
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool check_around_1(char **map, int i, int j)
{
	if (i < 1 || j < 1 || map[i + 1] == NULL || map[i][j + 1] == '\0')
		return false;
	if (map[i - 1][j] == ' ' || map[i + 1][j] == ' ' || map[i][j - 1] == ' ' || map[i][j + 1] == ' ')
		return false;
	return true;
}

bool is_valid_position(char **map, int i, int j, int rows, int cols)
{
	if (i < 0 || j < 0 || i >= rows || j >= cols)
		return false;
	return (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E');
}

bool can_player_move(char **map, int i, int j)
{
	int rows = 0;
	while (map[rows])
		rows++;
	int cols = strlen(map[0]);

	// Check if the player is surrounded by valid positions (i.e., spaces where he can move)
	if (is_valid_position(map, i - 1, j, rows, cols) ||
	    is_valid_position(map, i + 1, j, rows, cols) ||
	    is_valid_position(map, i, j - 1, rows, cols) ||
	    is_valid_position(map, i, j + 1, rows, cols))
	{
		return true;
	}
	return false;
}

static bool	is_player(const char strs[4], char *str, t_player	*player)
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

bool	check_double_player(char	**str, t_player *player)
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
	if (j > 1)
		return (false);
	return (true);
}

bool check_player(char **str, t_player *player)
{
	if (!check_double_player(str, player))
		return false;
	if (!check_around_1(str, player->corrdone.axe_abs, player->corrdone.axe_ord))
		return false;
	if (!can_player_move(str, player->corrdone.axe_abs, player->corrdone.axe_ord))
		return false;
	return true;
}
