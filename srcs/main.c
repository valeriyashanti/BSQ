/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 09:58:59 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/07 16:00:23 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include "ft.h"

int		main(int argc, char **argv)
{
	int		i;
	char	*lines;

	i = 1;
	if (argc == 1)
	{
		lines = read_file("");
		if (lines)
			bsq(lines);
	}
	while (i < argc)
	{
		lines = read_file(argv[i]);
		if (lines)
		{
			bsq(lines);
		}
		if (i != argc - 1)
			ft_putchar('\n');
		++i;
	}
	return (0);
}
