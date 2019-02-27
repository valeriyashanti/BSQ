/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 09:59:39 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/06 20:55:17 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include <stdlib.h>

int		**pre_calculate(t_map *map)
{
	int		x;
	int		y;
	int		**arr;

	y = 0;
	arr = (int**)malloc(sizeof(int*) * map->rows);
	if (!arr)
		return (0);
	while (y < map->rows)
	{
		x = 0;
		arr[y] = (int*)malloc(sizeof(int) * map->cols);
		if (!arr[y])
			return (0);
		while (x < map->cols)
		{
			arr[y][x] = ft_find_max_size(map, x, y);
			x++;
		}
		y++;
	}
	return (arr);
}

void	free_array(int **array, int size)
{
	int		i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		++i;
	}
	free(array);
}

int		find_square(t_map *map, int **arr, int *size)
{
	int max_x;
	int max_y;
	int x;
	int y;

	y = 0;
	max_x = 0;
	max_y = 0;
	while (y < map->rows)
	{
		x = 0;
		while (x < map->cols)
		{
			if (arr[y][x] > arr[max_y][max_x])
			{
				max_x = x;
				max_y = y;
			}
			x++;
		}
		y++;
	}
	*size = arr[max_y][max_x];
	return (max_y * map->cols + max_x);
}
