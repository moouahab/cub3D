/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:49:21 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/30 15:32:13 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Le parsing doit check is le fichier que l'on tente
//d'ouvir est un fichier .cub
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

/**
 * la function parsing va vreifer que chaque donne
 * de configuracion sont correctement recupere
 * toute en virifent la validation des donne
 *
 * elle utilise check_file afin de pouvoire
 * connaitre si l'extension est correcte si
 * oui nous bouvont passer check_map elle recupere
 * et verifier l'interieur de du fichier c'est le
 * coeur de parsing
 */


bool	parsing(int ac, char **av, t_mlx *mlx)
{
	data_map_init(&mlx->map);
	if (ac == 2)
	{
		if (!check_file(av[1]))
			return (ft_putstr_fd("\033[1;31mError\nnot file\033[0m\n",
					STDERR_FILENO));
		if (!check_map(&mlx->map, av[1]))
		{
			free_extraction(&mlx->map);
			return (false);
		}
		free_extraction(&mlx->map);
		return (true);
	}
	else
		return (ft_putstr_fd("\033[1;31mError\nparsing\033[0m\n",
				STDERR_FILENO));
}
