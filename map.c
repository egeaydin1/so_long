/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:36 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 09:57:37 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static int	check_walls(char **map, int width, int height)
{
	int	i;
	int	j;

	i = 0;
	while (i < height)
	{
		j = 0;
		while (j < width && map[i][j] && map[i][j] != '\n')
		{
			if (i == 0 || i == height - 1 || j == 0 || j == width - 1)
			{
				if (map[i][j] != '1')
					return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	is_rectangle_and_walled(char **map_arr)
{
	int	i;
	int	width;
	int	height;
	int	len;

	if (!map_arr || !map_arr[0])
		return (0);
	width = ft_strlen(map_arr[0]);
	if (map_arr[0][width - 1] == '\n')
		width--;
	height = get_map_height(map_arr);
	i = 0;
	while (map_arr[i])
	{
		len = ft_strlen(map_arr[i]);
		if (map_arr[i][len - 1] == '\n')
			len--;
		if (len != width)
			return (0);
		i++;
	}
	return (check_walls(map_arr, width, height));
}

static int	map_validation(char **map_arr)
{
	if (!is_rectangle_and_walled(map_arr))
		return (error_return("Map is not rectangle or not walled\n", 0));
	if (!is_valid_chars(map_arr))
		return (error_return("Map contains invalid characters\n", 0));
	if (!check_required_elements(map_arr))
		return (0);
	if (!is_valid_path(map_arr))
		return (error_return("Invalid path: Cannot reach all items\n", 0));
	return (1);
}

int	map_main(char *map_file, t_data *game)
{
	char	**map_arr;

	map_arr = map_parser(map_file);
	if (!map_arr)
		return (error_return("Failed to read map file\n", 0));
	if (!map_validation(map_arr))
	{
		ft_free_split(map_arr);
		return (0);
	}
	game->map = map_arr;
	return (1);
}