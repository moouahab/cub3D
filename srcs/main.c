/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:28:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/01 21:46:55 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

void	print_map(char	**map)
{
	int    i;

    i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }
}

void	print_info(t_map *map)
{
	printf("\n\033[33m    INFORMATION DE LA MAP      \n");
	printf("\n################################\033[0m\033[32m\n\n");
	printf("Hauteur %d\n", map->map_height);
	printf("Largeur %d\n\n", map->map_width);
	print_map(map->map);
	printf("\n\033[33m  INFORMATION DES TEXTURES  \n");
	printf("\n################################\033[0m\033[36m\n\n");
	printf("Nord %s\n", map->texture_north);
	printf("Sud %s\n", map->texture_south);
	printf("Ouest %s\n", map->texture_west);
	printf("Est %s\n", map->texture_east);
	printf("color ceiling %d\n", map->color_ceiling.blue + map->color_ceiling.green + map->color_ceiling.red);
	printf("color sol %d\n", map->color_sol.blue + map->color_sol.green + map->color_sol.red);
	printf("\n\033[33m  INFORMATION DE LA PLAYER  \n");
	printf("\n################################\033[0m\033[35m\n\n");
	printf("Orientation %c\n", map->player.orientation);
	printf("Position X %.2f\n", map->player.corrdone.axe_abs);
	printf("Position Y %.2f\n", map->player.corrdone.axe_ord);
	printf("\033[0m");
	
}


int	main(int ac, char **av, char **env)
{
	t_mlx	mlx;

	if (parsing(ac, av, env, &mlx))
	{
		print_info(&mlx.map);
		data_init(&mlx);
		mlx_loop(mlx.mlx_ptr);
		return (0);
	}
	return (0);
}
