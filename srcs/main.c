/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:28:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 22:56:48 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;

	if (parsing(ac, av, &mlx))
	{
		return (0);
	}
	else
		return (ft_putstr_fd("Error\n", STDERR_FILENO) + 1);
	return (0);
}
