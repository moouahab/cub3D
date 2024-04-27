/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:27:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 15:47:04 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <stdbool.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>
# include <X11/keysym.h>
# include <X11/X.h>

# define WIDTH 1024
# define HEIGHT 400

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}t_img;

typedef struct s_corrdone
{
	int			x;
	int			y;
}				t_corrdone;

typedef struct s_mlx
{
	void		*mlx_ptr;
	void		*mlx_win;
	void		*mlx_img;
	int			mlx_addr;
	t_img		img;
	t_corrdone	corrdone;
}				t_mlx;



// function de msg
void    exit_msg();
bool	error_msg(char *msg, void *display);

// hooks functions
void	event_hook(t_mlx	*data);


// function initializ
bool	data_init(t_mlx	*mlx);


#endif