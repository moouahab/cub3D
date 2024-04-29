/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:49:21 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 19:57:53 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Le parsing doit check is le fichier que l'on tente d'ouvir est un fichier .cub
// le parsing doit check la map qui ce trouver dans les fichiers .cub
// cas erreur possible :
// si il a un cote ouver ERROR DE MAP
// si il a deux jouer ERROR DE PERSONNAGE

bool	check_extension(char *filename)
{
	int			i;
	const int	len = ft_strlen(filename);

	i = 0;
	if (len >= 4)
	{
		while (i < len)
		{
			if (filename[i] == '.')
			{
				if (filename[i + 1] != 'c' && filename[i + 2] != 'u'
					&& filename[i + 3] != 'b')
					return (false);
			}
			i++;
		}
		return (true);
	}
	return (false);
}

bool	check_file(char *filename)
{
	int			i;
	const int	len = ft_strlen(filename);

	i = 0;
	if (len >= 4 && ft_strcmp(filename + len - 4, ".cub") == 0)
	{
		if (filename[len - 5] == '.')
			return (false);
		while (i < len - 4)
		{
			if (ft_strncmp(filename + i, ".cub", 4) == 0)
				return (false);
			i++;
		}
		return (check_extension(filename));
	}
	return (false);
}

bool	parsing(int ac, char **av, t_mlx *mlx)
{
	if (ac == 2)
	{
		if (!check_file(av[1]))
			return (false);
		check_map(&mlx->map, av[1]);
		free_cardinal(&mlx->map);
	}
	return (true);
}
