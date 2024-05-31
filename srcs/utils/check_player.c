/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 17:21:02 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 17:25:39 by moouahab         ###   ########.fr       */
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
				if ((map[i][j + 1] == '2') || (map[i + 1] && map[i + 1][j]
						&& map[i + 1][j] == ' '))
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

static bool	is_player(const char strs[4], char *str)
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
				return (true);
			j++;
		}
		i++;
	}
	return (false);
}

bool	check_double_player(char	**str)
{
	int			i;
	int			j;
	const char	oriantation[4] = {'N', 'S', 'W', 'E'};

	i = 0;
	j = 0;
	while (str[i])
	{
		if (is_player(oriantation, str[i]))
			j++;
		i++;
	}
	if (j > 1)
		return (false);
	return (true);
}
