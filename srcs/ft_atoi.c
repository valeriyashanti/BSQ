/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkessler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/23 12:32:23 by gkessler          #+#    #+#             */
/*   Updated: 2018/11/05 18:23:03 by gkessler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		++i;
	}
	return (i);
}

int		ft_atoi(char *str, int len)
{
	int	i;
	int	number;

	i = 0;
	number = 0;
	while (i < len && str[i] >= '0' && str[i] <= '9')
	{
		number *= 10;
		number += ((int)str[i] - '0');
		i++;
	}
	if (i == len)
		return (number);
	else
		return (-1);
}
