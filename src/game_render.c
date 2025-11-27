/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_render.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

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