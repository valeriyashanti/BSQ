/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/01 16:57:13 by hgreenfe          #+#    #+#             */
/*   Updated: 2018/11/07 20:23:07 by hgreenfe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H
# define FT_H
# include <unistd.h>
# include <stdlib.h>

int		ft_count_colms(char **str);
void	ft_putstr(char *str);
int		ft_putchar(char ch);
int		ft_atoi(char *str, int len);
int		ft_strlen(char *str);
void	print_error(void);
#endif
