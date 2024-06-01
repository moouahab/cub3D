/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <mohamed.ouahab1999@gmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 22:27:34 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/01 13:50:48 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "get_next_line.h"
# include "libft.h"
# include "mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <stdio.h>

# define WIDTH 1024
# define HEIGHT 400
# define TAB_SIZE 4

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
	int				axe_ord;
	int				axe_abs;
}					t_corrdone;

typedef struct s_player
{
	char			orientation;
	t_corrdone		corrdone;
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

typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*mlx_win;
	void			*mlx_img;
	int				mlx_addr;
	t_map			map;
	t_img			img;
}					t_mlx;

// function de msg
void				exit_msg(void);
bool				error_msg(char *msg, void *display);

// hooks functions
void				event_hook(t_mlx *data);

// free functions
void				free_tab2(char **tab);
void				free_map_lines(t_line *head);
void				free_extraction(t_map *map);
int					window_close(t_mlx *data);
int					free_window(int keysym, t_mlx *data);

// function extraction
bool				verify_map(t_map *map);
bool				extract_data(t_map *map, char *line, int y);
bool				recovery_colors(char *line, t_map **map, int i);
bool				extract_color(t_rgb *color, char *line, int i, char c);

// parsing functions
bool				is_init_color(t_map *map);
int					find_path(char *line);
void				init_rgb(t_rgb *color);
void				init_texture(t_map **map);
void				data_map_init(t_map *map);
bool				check_line(char *line);
bool				inside_map(char *line, t_map *map);
bool				find_line_first_end_last_map(char *line);
bool				check_extraction(t_map *map, char *filename);
bool				parsing(int ac, char **av, char **env, t_mlx *mlx);

// function utils
size_t				size_map(t_line *line);
size_t				size_max_line(t_line *line);
char				**list_to_array(t_line *head, int height, int width);

// function initializ
bool				data_init(t_mlx *mlx);
bool				add_map_line(t_line **head, char *line, t_map *m, int j);
bool				witdh_and_heigth_map(t_map	*map);
bool				check_around_2(char **map, int i);
bool				check_double_player(char 	**str, t_player *player);
bool				check_player(char **str, t_player *player);

#endif