/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hientranpc <hientranpc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:20 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 11:22:38 by hientranpc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "so_long.h"

int	main(int ac, char **av)
{
	t_game	game;

	ft_memset(&game, 0, sizeof(t_game));
	if (!arg_check(ac, av))
		return (1);
	if (!map_main(av[1], &game))
		return (1);
	if (!init_game(&game))
	{
		free_game(&game);
		return (1);
	}
	render_game(&game);
	mlx_loop(game.mlx);
	return (0);
}
