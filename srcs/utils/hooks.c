/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:47:32 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/28 11:43:59 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"

int	key_press(int keysym, t_mlx *data)
{
	free_window(keysym, data);
    
    // move_camera(keysym, data); cette function va gere les movement de la carmera via les flecche du clavier
    
    // move_person(keysym, data); cette function va gere les movement du perso : 
    // - W = Avencer 
    // - S = Reculer 
    // - A = aller a gauche
    // - D = aller a droite
    return (0);
}

void	event_hook(t_mlx	*data)
{
    mlx_hook(data->mlx_win, KeyPress, KeyPressMask, key_press, data);
	mlx_hook(data->mlx_win, DestroyNotify, StructureNotifyMask, window_close, data);
}