/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	process_key(int keycode, int *new_x, int *new_y)
{
	if (keycode == KEY_W || keycode == KEY_UP)
		(*new_y)--;
	else if (keycode == KEY_S || keycode == KEY_DOWN)
		(*new_y)++;
	else if (keycode == KEY_A || keycode == KEY_LEFT)
		(*new_x)--;
	else if (keycode == KEY_D || keycode == KEY_RIGHT)
		(*new_x)++;
}

int	handle_input(int keycode, t_game *game)
{
	int	new_x;
	int	new_y;

	new_x = game->player_x;
	new_y = game->player_y;
	if (keycode == KEY_ESC)
		close_game(keycode, game);
	process_key(keycode, &new_x, &new_y);
	if ((new_x != game->player_x || new_y != game->player_y)
		&& can_move(game, new_x, new_y))
	{
		move_player(game, new_x, new_y);
		render_game(game);
	}
	return (0);
}