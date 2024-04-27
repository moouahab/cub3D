/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:27:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/04/27 21:52:25 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include <stdbool.h>
# include <stdio.h>

# define WIDTH 1024
# define HEIGHT 400

typedef struct s_img
{
	void		*img_ptr;
	char		*addr;
	int			bpp;
	int			line_length;
	int			endian;
}				t_img;

typedef	struct s_rgb
{
	unsigned int	red; 
	unsigned int	green;
	unsigned int	blue;
}t_rgb;

typedef struct s_map
{
	char		**map;
	int			fd_file;
	char		*texture_north;
	char		*texture_south;
	char		*texture_west;
	char		*texture_east;
	t_rgb		color_sol;
	t_rgb		color_ceiling;
}				t_map;

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
	t_map		map;
	t_img		img;
	t_corrdone	corrdone;
}				t_mlx;

// function de msg
void			exit_msg(void);
bool			error_msg(char *msg, void *display);

// hooks functions
void			event_hook(t_mlx *data);

// parsing functions
bool			parsing(int ac, char **av, t_mlx *mlx);

// function initializ
bool			data_init(t_mlx *mlx);

#endif