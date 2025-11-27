/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:15 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 11:30:42 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	load_texture(t_game *game)
{
	game->img_width = TILE_SIZE;
	game->img_heigh = TILE_SIZE;
	game->bg_img = mlx_xpm_file_to_image(game->mlx,
			"textures/bg.xpm", &game->img_width, &game->img_heigh);
	game->wall_img = mlx_xpm_file_to_image(game->mlx,
			"textures/wall.xpm", &game->img_width, &game->img_heigh);
	game->door_img = mlx_xpm_file_to_image(game->mlx,
			"textures/door.xpm", &game->img_width, &game->img_heigh);
	game->player_img = mlx_xpm_file_to_image(game->mlx,
			"textures/player.xpm", &game->img_width, &game->img_heigh);
	game->collec_img = mlx_xpm_file_to_image(game->mlx,
			"textures/collec.xpm", &game->img_width, &game->img_heigh);
	if (!game->bg_img || !game->wall_img || !game->door_img
		|| !game->player_img || !game->collec_img)
		return (error_return("Failed to load textures\n", 0));
	return (1);
}

static int	close_game(int keycode, t_game *game)
{
	(void)keycode;
	free_game(game);
	exit(0);
	return (0);
}

static int	can_move(t_game *game, int new_x, int new_y)
{
	if (new_x < 0 || new_y < 0 || new_y >= game->height
		|| new_x >= game->width)
		return (0);
	if (game->map[new_y][new_x] == WALL)
		return (0);
	if (game->map[new_y][new_x] == EXIT && game->collectibles > 0)
		return (0);
	return (1);
}

static void	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target == COLLECTIBLE)
	{
		game->collectibles--;
	}
	if (target == EXIT && game->collectibles == 0)
	{
		game->moves++;
		ft_printf("Moves: %d\n", game->moves);
		ft_printf("You won! Total moves: %d\n", game->moves);
		close_game(0, game);
	}
	game->map[game->player_y][game->player_x] = EMPTY;
	game->player_x = new_x;
	game->player_y = new_y;
	game->map[new_y][new_x] = PLAYER;
	game->moves++;
	ft_printf("Moves: %d\n", game->moves);
}

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
		close_game(keycode, game);
	else if (keycode == KEY_W || keycode == KEY_UP)
		new_y--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		new_y++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		new_x--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		new_x++;
	if ((new_x != game->player_x || new_y != game->player_y)
		&& can_move(game, new_x, new_y))
	{
		move_player(game, new_x, new_y);
		render_game(game);
	}
	return (0);
}

static int	count_collectibles(char **map)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == COLLECTIBLE)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	init_game(t_game *game)
{
	int	win_width;
	int	win_height;

	game->mlx = mlx_init();
	if (!game->mlx)
		return (error_return("mlx_init failed\n", 0));
	win_width = game->width * TILE_SIZE;
	win_height = game->height * TILE_SIZE;
	game->win = mlx_new_window(game->mlx, win_width, win_height, "so_long");
	if (!game->win)
		return (error_return("mlx_new_window failed\n", 0));
	if (!load_texture(game))
		return (0);
	game->collectibles = count_collectibles(game->map);
	game->moves = 0;
	mlx_hook(game->win, 2, 0, handle_input, game);
	mlx_hook(game->win, 17, 0, close_game, game);
	return (1);
}

static void	render_tile(t_game *game, int x, int y)
{
	void	*img;

	img = game->bg_img;
	if (game->map[y][x] == WALL)
		img = game->wall_img;
	else if (game->map[y][x] == COLLECTIBLE)
		img = game->collec_img;
	else if (game->map[y][x] == EXIT)
		img = game->door_img;
	else if (game->map[y][x] == PLAYER)
		img = game->player_img;
	mlx_put_image_to_window(game->mlx, game->win, img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_game(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			render_tile(game, x, y);
			x++;
		}
		y++;
	}
}
