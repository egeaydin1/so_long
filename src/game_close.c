/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_close.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	close_game(int keycode, t_game *game)
{
	(void)keycode;
	free_game(game);
	exit(0);
	return (0);
}