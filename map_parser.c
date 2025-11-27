/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:30 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 09:57:31 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

char	**map_parser(char *map_file)
{
	char	**map_arr;
	int		fd;
	int		i;

	map_arr = malloc(sizeof(char *) * 1000);
	if (!map_arr)
		return (NULL);
	fd = open(map_file, O_RDONLY);
	if (fd < 0)
	{
		free(map_arr);
		return (NULL);
	}
	i = 0;
	map_arr[i] = get_next_line(fd);
	while (map_arr[i])
	{
		i++;
		map_arr[i] = get_next_line(fd);
	}
	close(fd);
	return (map_arr);
}

int	get_map_height(char **map)
{
	int	height;

	height = 0;
	while (map[height])
		height++;
	return (height);
}
