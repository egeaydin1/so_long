/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_texture.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 12:30:00 by hientranpc        #+#    #+#             */
/*   Updated: 2025/11/27 12:30:00 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	load_texture(t_game *game)
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