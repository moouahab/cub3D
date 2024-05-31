/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:28:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/05/31 15:31:19 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (parsing(ac, av, &mlx))
	{
		printf("\033[1;34mMise en place du projet cub3D\033[0m\n");
		free_tab2(mlx.map.map);
		free_extraction(&mlx.map);
		return (0);
	}
	return (0);
}
