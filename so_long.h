/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:58:11 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 10:33:41 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_LONG_H
# define SO_LONG_H

/* ************************************************************************** */
/*                           STANDARD LIBRARIES                               */
/* ************************************************************************** */

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdarg.h>

/* ************************************************************************** */
/*                           CUSTOM LIBRARIES                                 */
/* ************************************************************************** */

# include "lib/mlx/mlx.h"
# include "lib/libft/libft.h"
# include "lib/ft_printf/ft_printf.h"
# include "lib/get_next_line/get_next_line.h"

/* ************************************************************************** */
/*                              DEFINES                                       */
/* ************************************************************************** */

# define WIDTH 64
# define HEIGHT 64

/* ************************************************************************** */
/*                         GAME STRUCTURES                                    */
/* ************************************************************************** */

typedef struct s_game
{
	void	*mlx;
	void	*win;
	void	*bg_img;
	char	**map;
	int		width;
	int		height;
	int		player_x;
	int		player_y;
	int		collectibles;
	int		moves;
}	t_game;

/* ************************************************************************** */
/*                         GAME FUNCTIONS                                     */
/* ************************************************************************** */

// Validation
int		arg_check(int ac, char **av);

// Map parser functions (map_parser.c)
char	**map_parser(char *map_file);
int		get_map_height(char **map);

// Map element functions (map_elements.c)
int		is_valid_char(char c);
int		is_valid_chars(char **map_arr);
void	count_elements(char **map, int *p, int *e, int *c);
int		check_required_elements(char **map_arr);

// Map validation functions (map.c)
int		is_rectangle_and_walled(char **map_arr);
int		map_main(char *map_file, t_data *game);

// Path validation functions (map_validation.c)
int		is_valid_path(char **map);

// Game functions
int		init_game(t_game *game);
int		handle_input(int keycode, t_game *game);
void	render_game(t_game *game);

// Utils
int		error_return(char *str, int return_v);
void	free_game(t_game *game);
void	ft_free_split(char **arr);
char	**copy_map(char **map);


#endif
