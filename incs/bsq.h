/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 09:59:50 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/06 20:47:36 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define B_SIZE (16128)
# define ERRMSG "map error\n"

typedef	struct	s_map
{
	int			rows;
	int			cols;
	char		empty;
	char		obstacle;
	char		full;
	char		**array;
}				t_map;

char			*read_file(char *filename);
int				read_lines(int fd, char **dst);
void			ft_ints_to_char(t_map *map);
t_map			*ft_create_map(char *str);
int				**pre_calculate(t_map *map);
int				ft_read_symbols(char *str, t_map *map);
int				ft_find_sum(t_map *map, int x, int y, int size);
int				ft_find_max_size(t_map *map, int x, int y);
int				ft_find_obstacle(t_map *map, int x, int y, int size);
int				find_square(t_map *map, int **arr, int *size);
int				ft_fill_square(t_map *map, int x, int y, int size);
void			free_map(t_map *map);
void			free_array(int **arr, int size);
int				ft_validate_map(t_map *map);
int				ft_parse_mapsize(char *str, t_map *map);
int				bsq(char *lines);
#endif
