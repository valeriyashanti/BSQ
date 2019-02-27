/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reader.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 15:47:19 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/07 20:23:49 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int		ft_write_map(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			ft_putchar(map->array[i][j]);
			++j;
		}
		ft_putchar('\n');
		++i;
	}
	return (0);
}

int		ft_validate_map(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	while (i < map->rows)
	{
		j = 0;
		while (j < map->cols)
		{
			if (map->array[i][j] == map->empty)
				map->array[i][j] = 1;
			else if (map->array[i][j] == map->obstacle)
				map->array[i][j] = 0;
			else
				return (map->array[i][j]);
			++j;
		}
		++i;
	}
	return (0);
}

int		calculate(t_map *map)
{
	int	**arr;
	int	k;
	int	sz;

	sz = 0;
	k = -1;
	if (ft_validate_map(map))
	{
		print_error();
		return (-1);
	}
	arr = pre_calculate(map);
	if (arr)
		k = find_square(map, arr, &sz);
	if (k >= 0)
		ft_fill_square(map, k % map->cols, k / map->cols, sz);
	else
		return (-1);
	ft_ints_to_char(map);
	free_array(arr, map->rows);
	return (0);
}

char	*read_file(char *filename)
{
	int		fd;
	char	*lines;

	lines = 0;
	if (!filename || filename[0] == 0)
		fd = 0;
	else
		fd = open(filename, O_RDONLY, 0);
	if (fd == -1)
	{
		print_error();
		return (0);
	}
	if (read_lines(fd, &lines))
		return (0);
	if (close(fd) == -1)
		return (0);
	return (lines);
}

int		bsq(char *lines)
{
	t_map	*map;

	map = ft_create_map(lines);
	if (!map)
		return (0);
	if (!calculate(map))
		ft_write_map(map);
	free_map(map);
	return (1);
}
