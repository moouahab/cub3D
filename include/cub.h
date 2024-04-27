/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:27:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 11:19:19 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <errno.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct s_corrdone
{
	int			x;
	int			y;
}				t_corrdone;

typedef struct s_mlx
{
	void		*mlx_data;
	void		*mlx_win;
	void		*mlx_img;
	int			mlx_addr;
	t_corrdone	corrdone;
}				t_mlx;

#endif