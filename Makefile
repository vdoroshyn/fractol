#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/02 16:51:50 by vdoroshy          #+#    #+#              #
#    Updated: 2017/03/02 16:51:57 by vdoroshy         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = fractol
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT = libft.a
MLX = -lmlx -framework OpenGL -framework AppKit
HEADER = fractol.h

OBJECTS = fractol.o \

.PHONY : clean all fclean re

all : $(LIBFT) $(NAME)
	
$(NAME) : $(OBJECTS) $(HEADER)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJECTS) $(MLX) libft/$(LIBFT)

$(LIBFT) :
	make -C libft/

clean :
	rm -rf $(OBJECTS)
	make -C libft/ clean

fclean : clean
	rm -rf $(NAME)
	rm -rf libft/$(LIBFT)

re : fclean all

fractol.o : fractol.c $(HEADER)
	$(CC) $(CFLAGS) -c fractol.c fractol.h