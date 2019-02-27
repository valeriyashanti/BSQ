/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_square.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 11:59:34 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/06 20:17:36 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

void	ft_ints_to_char(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->array[i][j] == 0)
				map->array[i][j] = map->obstacle;
			else if (map->array[i][j] == 1)
				map->array[i][j] = map->empty;
			j++;
		}
		i++;
	}
}

int		ft_fill_square(t_map *map, int x, int y, int size)
{
	int		sum;
	int		i;
	int		j;

	i = 0;
	sum = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			map->array[i + y][j + x] = map->full;
			j++;
		}
		i++;
	}
	return (sum);
}

int		ft_find_max_size(t_map *map, int x, int y)
{
	int size;
	int sum;

	size = 0;
	sum = 0;
	while (size + x < map->cols &&
		size + y < map->rows &&
		sum == size * size)
	{
		size++;
		sum = ft_find_sum(map, x, y, size);
	}
	if (sum == size * size)
	{
		return (size);
	}
	else
	{
		return (size - 1);
	}
}

int		ft_find_sum(t_map *map, int x, int y, int size)
{
	int		sum;
	int		i;
	int		j;

	i = 0;
	sum = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			sum += map->array[i + y][j + x];
			j++;
		}
		i++;
	}
	return (sum);
}

int		ft_find_obstacle(t_map *map, int x, int y, int size)
{
	int		i;
	int		j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map->array[i + y][j + x] == 0)
			{
				return ((i + y) * map->cols + (j + x));
			}
			j++;
		}
		i++;
	}
	return (-1);
}
