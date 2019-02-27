/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 18:18:28 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/07 20:17:24 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"
#include "bsq.h"

int		ft_count_cols(char *str)
{
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(str);
	i += len + 1;
	len = ft_strlen(str + i);
	while (str[i])
	{
		if (ft_strlen(str + i) != len)
		{
			return (-1);
		}
		i += len + 1;
	}
	return (len);
}

int		ft_parse_mapsize(char *str, t_map *map)
{
	if (ft_read_symbols(str, map) < 0)
	{
		free(map);
		return (-1);
	}
	if (!str)
		return (-1);
	map->rows = ft_atoi(str, ft_strlen(str) - 3);
	map->cols = ft_count_cols(str);
	if (map->rows < 1 || map->cols < 1)
	{
		print_error();
		return (-1);
	}
	return (map->rows);
}

int		ft_read_symbols(char *str, t_map *map)
{
	int		i;

	i = ft_strlen(str);
	if (i < 4)
	{
		print_error();
		return (-1);
	}
	map->full = str[i - 1];
	map->obstacle = str[i - 2];
	map->empty = str[i - 3];
	if ((map->obstacle == map->full || map->empty == map->full ||
			map->empty == map->obstacle) ||
			(!(map->obstacle) || !(map->empty) || !(map->full)))
	{
		print_error();
		return (-1);
	}
	return (0);
}

t_map	*ft_create_map(char *str)
{
	int		i;
	int		j;
	t_map	*map;

	map = (t_map*)malloc(sizeof(t_map));
	if (ft_parse_mapsize(str, map) < 0)
		return (0);
	str = str + ft_strlen(str) + 1;
	if (!(map->array = (char**)malloc(sizeof(char*) * map->rows)))
		return (0);
	j = -1;
	while (++j < map->rows)
	{
		if (!(map->array[j] = (char*)malloc(sizeof(char) * map->cols)))
			return (0);
		i = -1;
		while (++i < map->cols)
		{
			map->array[j][i] = str[i + j * (map->cols + 1)];
		}
	}
	return (map);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		free(map->array[i]);
		++i;
	}
	free(map->array);
	free(map);
}
