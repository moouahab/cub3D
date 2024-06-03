/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 14:18:54 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/03 14:24:11 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub.h"
#include <mlx.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

bool	error_msg(char *msg, void *display)
{
	if (msg != NULL)
		printf("Error\n%s\n", msg);
	if (display != NULL)
	{
		mlx_destroy_display(display);
		free(display);
	}
	return (false);
}

void	exit_msg(void)
{
	printf("fin de program\n");
}
