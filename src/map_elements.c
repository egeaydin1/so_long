/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_elements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egeaydin <egeaydin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 09:57:51 by egeaydin          #+#    #+#             */
/*   Updated: 2025/11/27 09:57:52 by egeaydin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

int	is_valid_char(char c)
{
	if (c == '1' || c == '0' || c == 'P' || c == 'E' || c == 'C' || c == '\n')
		return (1);
	return (0);
}

int	is_valid_chars(char **map_arr)
{
	int	i;
	int	j;

	i = 0;
	while (map_arr[i])
	{
		j = 0;
		while (map_arr[i][j])
		{
			if (!is_valid_char(map_arr[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	count_elements(char **map, int *p, int *e, int *c)
{
	int	i;
	int	j;

	*p = 0;
	*e = 0;
	*c = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
				(*p)++;
			else if (map[i][j] == 'E')
				(*e)++;
			else if (map[i][j] == 'C')
				(*c)++;
			j++;
		}
		i++;
	}
}

int	check_required_elements(char **map_arr)
{
	int	p_count;
	int	e_count;
	int	c_count;

	count_elements(map_arr, &p_count, &e_count, &c_count);
	if (p_count != 1)
		return (error_return("Map must have exactly 1 player (P)\n", 0));
	if (e_count != 1)
		return (error_return("Map must have exactly 1 exit (E)\n", 0));
	if (c_count < 1)
		return (error_return("Map must have at least 1 collectible (C)\n", 0));
	return (1);
}
