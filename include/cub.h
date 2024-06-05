/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:27:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/05 16:47:36 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include "parsing.h"
# include <X11/X.h>
# include <X11/ap_keysym.h>
# include <X11/keysym.h>
# include <math.h>

# define WIDTH 1024
# define HEIGHT 400
# define TAB_SIZE 4
# define MOVE_SPEED 0.05
# define ROT_SPEED 0.3

typedef struct s_pixel
{
	int				color;
	int				pixel_x;
	int				pixel_y;
}					t_pixel;

typedef struct s_img
{
	void			*img_ptr;
	char			*addr;
	int				bpp;
	int				line_length;
	int				endian;
}					t_img;

typedef struct s_rgb
{
	int				red;
	int				green;
	int				blue;
}					t_rgb;

typedef struct s_line
{
	char			*line;
	size_t			line_len;
	struct s_line	*next;
}					t_line;

typedef struct s_corrdone
{
	double			axe_ord;
	double			axe_abs;
}					t_corrdone;

typedef struct s_camera
{
	double			planex;
	double			planey;
}					t_camera;

typedef struct s_coordinates
{
	int				local_x;
	int				local_y;
	int				rotated_x;
	int				rotated_y;
}					t_coordinates;
typedef struct s_direction
{
	double			dir_x;
	double			dir_y;
}					t_direction;

typedef struct s_player
{
	char			orientation;
	t_corrdone		corrdone;
	t_camera		camera;
	t_direction		direction;
}					t_player;

typedef struct s_map
{
	int				fd_file;
	int				map_width;
	int				map_height;
	int				line_color;
	int				line_texture;
	int				line_map;
	bool			beggin_map;
	char			**map;
	char			*texture_north;
	char			*texture_south;
	char			*texture_west;
	char			*texture_east;
	t_line			*line;
	t_player		player;
	t_rgb			color_sol;
	t_rgb			color_ceiling;
}					t_map;

typedef struct s_ray
{
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	int				map_x;
	int				map_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_dist_x;
	double			delta_dist_y;
	double			perp_wall_dist;
	int				step_x;
	int				step_y;
	int				hit;
	int				side;
	int				line_height;
	int				draw_start;
	int				draw_end;
}					t_ray;

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				mlx_addr;
	t_pixel			pixel;
	t_map			map;
	t_img			img;
}					t_mlx;

// function de msg
void				exit_msg(void);
bool				error_msg(char *msg, void *display);

// hooks functions
void				event_hook(t_mlx *data);
void				put_pixel_to_img(t_img *img, int x, int y, int color);
void				turn_right(t_player *player);
void				turn_left(t_player *player);
void				move_backward(t_player *player, char **map);
void				move_forward(t_player *player, char **map);
void				raycasting(t_mlx *mlx);

// free functions
void				free_tab2(char **tab);
void				free_map_lines(t_line *head);
void				free_extraction(t_map *map);
int					window_close(t_mlx *data);
int					free_window(int keysym, t_mlx *data);
void				draw_player(t_mlx *mlx, t_player *player);
void				draw_map(t_mlx *mlx);
void				strafe_left(t_player *player, char **map);
void				strafe_right(t_player *player, char **map);

#endif