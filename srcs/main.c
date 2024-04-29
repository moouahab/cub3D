/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:28:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/29 23:18:18 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (parsing(ac, av, &mlx))
	{
		printf("\033[1;34mMise en place du projet cub3D\033[0m\n");
		return (0);
	}
	return (0);
}
