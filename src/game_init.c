/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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