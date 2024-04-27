/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 01:28:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 15:07:45 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int main(int    ac, char **av)
{
    (void)ac; (void)av;
    t_mlx   data;

    
    if (data_init(&data))
        mlx_loop(data.mlx_ptr);
    return (0);
}
