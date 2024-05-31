/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 13:49:21 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 16:06:25 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

// Le parsing doit check is le fichier que l'on tente
// d'ouvir est un fichier .cub
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
		if (!verify_map(&mlx->map))
		{
			free_tab2(mlx->map.map);
			free_extraction(&mlx->map);
			return (ft_putstr_fd("\033[1;31mError\nmap not valide\033[0m\n",
					STDERR_FILENO));
		}
		return (true);
	}
	else
		return (ft_putstr_fd("\033[1;31mError\nparsing\033[0m\n",
				STDERR_FILENO));
}
