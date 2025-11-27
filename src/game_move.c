/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	can_move(t_game *game, int new_x, int new_y)
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

void	move_player(t_game *game, int new_x, int new_y)
{
	char	target;

	target = game->map[new_y][new_x];
	if (target == COLLECTIBLE)
		game->collectibles--;
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