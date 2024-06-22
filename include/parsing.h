/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moouahab <moouahab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/01 21:37:59 by moouahab          #+#    #+#             */
/*   Updated: 2024/06/06 19:06:28 by moouahab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_col_row
{
	int					col;
	int					row;
}						t_col_row;

typedef struct s_mlx	t_mlx;
typedef struct s_map	t_map;
typedef struct s_rgb	t_rgb;
typedef struct s_line	t_line;
typedef struct s_player	t_player;

// function extraction
void					init_player(t_player *player);
bool					verify_map(t_mlx *mlx, t_map *map);
bool					extract_data(t_map *map, char *line, int y);
bool					recovery_colors(char *line, t_map **map, int i);
bool					extract_color(t_rgb *color, char *line, int i, char c);

// parsing functions
bool					is_init_color(t_map *map);
int						find_path(char *line);
void					init_rgb(t_rgb *color);
void					init_texture(t_map **map);
void					data_map_init(t_map *map);
bool					check_line(char *line);
bool					inside_map(char *line, t_map *map);
bool					find_line_first_end_last_map(char *line);
bool					check_extraction(t_map *map, char *filename);
bool					parsing(int ac, char **av, char **env, t_mlx *mlx);

// function utils
size_t					size_map(t_line *line);
size_t					size_max_line(t_line *line);
bool					check_texture_paths(t_mlx *mlx, t_map *textures);
char					**list_to_array(t_line *head, int height, int width);

// function initializ
bool					data_init(t_mlx *mlx);
bool					add_map_line(t_line **head, char *line, t_map *m,
							int j);
bool					witdh_and_heigth_map(t_map *map);
bool					is_open_map(char **map, int i, int j);
bool					check_double_player(char **str, t_player *player);
bool					check_player(char **str, t_player *player);
bool					check_line_map(char *line);

#endif