# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hgreenfe <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/04 11:16:45 by hgreenfe          #+#    #+#              #
#    Updated: 2018/11/07 16:02:02 by hgreenfe         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = bsq 
SRCDIR = srcs
INCDIR = incs
CC = gcc
CCFLAGS = -Wall -Werror -Wextra --pedantic-errors -I $(INCDIR)
RM = rm
RMFLAGS = -f

FILES = $(SRCDIR)/main.c \
		$(SRCDIR)/ft_read_lines.c \
		$(SRCDIR)/ft_reader.c \
		$(SRCDIR)/ft_putchar.c \
		$(SRCDIR)/ft_putstr.c \
		$(SRCDIR)/ft_atoi.c \
		$(SRCDIR)/ft_read_map.c \
		$(SRCDIR)/ft_find_square.c \
		$(SRCDIR)/bsq.c

$(NAME):
	$(CC) $(CCFLAGS) -o $(NAME) $(FILES)

norm:
	@norminette $(SRCDIR)
	@norminette $(INCDIR)

all:	norm $(NAME)

clean:

fclean:	clean
	$(RM) $(RMFLAGS) $(NAME)
re: fclean all
