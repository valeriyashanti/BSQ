/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_lines.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 16:08:32 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/07 20:16:41 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

void	ft_remalloc(char **dst, int dst_size, char *src, int src_size)
{
	int		i;
	int		j;
	char	*temp;

	temp = *dst;
	if (!(*dst = (char*)malloc(sizeof(char) * (dst_size))))
		return ;
	i = 0;
	while (i < dst_size - src_size - 1)
	{
		(*dst)[i] = temp[i];
		i++;
	}
	j = 0;
	while (j < src_size)
	{
		(*dst)[i] = src[j];
		i++;
		j++;
	}
	(*dst)[i] = '\0';
	if (temp)
		free(temp);
}

int		read_lines(int fd, char **dst)
{
	int		size;
	char	*buf;
	int		ret_size;

	ret_size = 0;
	size = 0;
	if (!(buf = (char*)malloc(sizeof(char) * (B_SIZE + 1))))
		return (1);
	ret_size = read(fd, buf, B_SIZE);
	if (ret_size <= 0)
	{
		print_error();
		return (1);
	}
	while (ret_size)
	{
		size += ret_size;
		ft_remalloc(dst, size + 1, buf, ret_size);
		ret_size = read(fd, buf, B_SIZE);
		if (ret_size < 0)
			return (1);
	}
	if (buf)
		free(buf);
	return (0);
}
