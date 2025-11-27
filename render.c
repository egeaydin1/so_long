/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:15 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 10:36:44 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"
void	load_texture(t_data *data)
{
	game->bg_img  = mlx_xpm_file_to_image(game->mlx, "textures/bg.xpm", &game->img_w)

	
}
int	init_game(t_data *game)
{
    game->mlx = mlx_init();
    if (!game->mlx)
		return(error_return("mlx_init failed\n",0));
	game->win = mlx_new_window(data->mlx, WIDTH, HEIGHT,"so_long - PACMAN");
	if(!data->win)
		return(error_return("mlx_new_window failed\n",0));
	load_texture(data);
	
    
}