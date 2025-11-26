/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientran <hientran@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:51:00 by hientran          #+#    #+#             */
/*   Updated: 2025/11/26 14:51:00 by hientran         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdlib.h>
#include <stdio.h>

/* Window dimensions */
#define WIN_WIDTH 800
#define WIN_HEIGHT 600
#define TILE_SIZE 64

/* Mac key codes */
#define KEY_ESC 53
#define KEY_W 13
#define KEY_A 0
#define KEY_S 1
#define KEY_D 2
#define KEY_UP 126
#define KEY_DOWN 125
#define KEY_LEFT 123
#define KEY_RIGHT 124

/* Game data structure */
typedef struct s_data
{
	void	*mlx;
	void	*win;
	void	*red_square;
	int		x;
	int		y;
}	t_data;

/* ************************************************************************** */
/*                          HELPER FUNCTIONS                                  */
/* ************************************************************************** */

int	close_program(t_data *data)
{
	if (data->red_square)
		mlx_destroy_image(data->mlx, data->red_square);
	if (data->win)
		mlx_destroy_window(data->mlx, data->win);
	exit(0);
	return (0);
}

void	render(t_data *data)
{
	char	pos_text[50];

	mlx_clear_window(data->mlx, data->win);
	mlx_put_image_to_window(data->mlx, data->win,
		data->red_square, data->x, data->y);
	sprintf(pos_text, "X: %d  Y: %d", data->x, data->y);
	mlx_string_put(data->mlx, data->win, 10, 20, 0xFFFFFF, pos_text);
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFFFFFF,
		"Use WASD or Arrow Keys");
	mlx_string_put(data->mlx, data->win, 10, 60, 0xFFFFFF,
		"Press ESC to exit");
}

/* ************************************************************************** */
/*                          EVENT FUNCTIONS                                   */
/* ************************************************************************** */

int	key_press(int keycode, t_data *data)
{
	int	move_speed;

	move_speed = 10;
	printf("Key pressed: %d\n", keycode);
	if (keycode == KEY_ESC)
		close_program(data);
	else if (keycode == KEY_W || keycode == KEY_UP)
	{
		if (data->y - move_speed >= 0)
			data->y -= move_speed;
	}
	else if (keycode == KEY_S || keycode == KEY_DOWN)
	{
		if (data->y + move_speed + TILE_SIZE <= WIN_HEIGHT)
			data->y += move_speed;
	}
	else if (keycode == KEY_A || keycode == KEY_LEFT)
	{
		if (data->x - move_speed >= 0)
			data->x -= move_speed;
	}
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
	{
		if (data->x + move_speed + TILE_SIZE <= WIN_WIDTH)
			data->x += move_speed;
	}
	render(data);
	return (0);
}

/* ************************************************************************** */
/*                          INITIALIZATION FUNCTIONS                          */
/* ************************************************************************** */

void	load_texture(t_data *data)
{
	int	width;
	int	height;

	data->red_square = mlx_xpm_file_to_image(data->mlx,
			"textures/red_square.xpm", &width, &height);
	if (!data->red_square)
	{
		printf("Error: Cannot load red_square.xpm\n");
		printf("Make sure textures/red_square.xpm exists!\n");
		exit(1);
	}
	printf("Texture loaded successfully!\n");
	printf("   Size: %dx%d\n", width, height);
}

void	init_game(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
	{
		printf("Error: mlx_init() failed\n");
		exit(1);
	}
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT,
			"MiniLibX Test - Red Square");
	if (!data->win)
	{
		printf("Error: mlx_new_window() failed\n");
		exit(1);
	}
	load_texture(data);
	data->x = (WIN_WIDTH - TILE_SIZE) / 2;
	data->y = (WIN_HEIGHT - TILE_SIZE) / 2;
	printf("Game initialized!\n");
	printf("   Window: %dx%d\n", WIN_WIDTH, WIN_HEIGHT);
	printf("   Starting position: (%d, %d)\n", data->x, data->y);
}

void	setup_hooks(t_data *data)
{
	mlx_hook(data->win, 2, 0, key_press, data);
	mlx_hook(data->win, 17, 0, close_program, data);
	printf("Hooks setup complete!\n");
}

/* ************************************************************************** */
/*                              MAIN FUNCTION                                 */
/* ************************************************************************** */

int	main(void)
{
	t_data	data;

	printf("=================================\n");
	printf("  MiniLibX Test - Red Square\n");
	printf("=================================\n\n");
	init_game(&data);
	setup_hooks(&data);
	render(&data);
	printf("\nGame is running!\n");
	printf("   Use WASD or Arrow Keys to move\n");
	printf("   Press ESC to exit\n\n");
	mlx_loop(data.mlx);
	return (0);
}
