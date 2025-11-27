/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:58 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 09:57:59 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void	flood_fill(char **map, int x, int y)
{
	if (map[y][x] == '1' || map[y][x] == 'V')
		return ;
	map[y][x] = 'V';
	flood_fill(map, x, y - 1);
	flood_fill(map, x, y + 1);
	flood_fill(map, x - 1, y);
	flood_fill(map, x + 1, y);
}

static void	find_player(char **map, int *x, int *y)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				*x = j;
				*y = i;
				return ;
			}
			j++;
		}
		i++;
	}
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
			if (map[i][j] == 'C')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	check_reachable(char **map, char **map_copy, int *r_c, int *r_e)
{
	int	i;
	int	j;

	*r_c = 0;
	*r_e = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'C' && map_copy[i][j] == 'V')
				(*r_c)++;
			if (map[i][j] == 'E' && map_copy[i][j] == 'V')
				(*r_e)++;
			j++;
		}
		i++;
	}
}

int	is_valid_path(char **map)
{
	char	**map_copy;
	int		player_x;
	int		player_y;
	int		total_c;
	int		reachable_c;
	int		reachable_e;

	find_player(map, &player_x, &player_y);
	total_c = count_collectibles(map);
	map_copy = copy_map(map);
	if (!map_copy)
		return (0);
	flood_fill(map_copy, player_x, player_y);
	check_reachable(map, map_copy, &reachable_c, &reachable_e);
	ft_free_split(map_copy);
	if (reachable_c == total_c && reachable_e == 1)
		return (1);
	return (0);
}
