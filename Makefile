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
			julia.o \
			mandelbrot.o \
			burning_ship.o \
			move.o \
			change_color.o \
			construct_destruct.o \
			mlx_hook.o \
			draw.o \
			change_iterations.o \

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

julia.o : julia.c $(HEADER)
	$(CC) $(CFLAGS) -c julia.c fractol.h

mandelbrot.o : mandelbrot.c $(HEADER)
	$(CC) $(CFLAGS) -c mandelbrot.c fractol.h

burning_ship.o : burning_ship.c $(HEADER)
	$(CC) $(CFLAGS) -c burning_ship.c fractol.h

move.o : move.c $(HEADER)
	$(CC) $(CFLAGS) -c move.c fractol.h

change_color.o : change_color.c $(HEADER)
	$(CC) $(CFLAGS) -c change_color.c fractol.h

construct_destruct.o : construct_destruct.c $(HEADER)
	$(CC) $(CFLAGS) -c construct_destruct.c fractol.h

mlx_hook.o : mlx_hook.c $(HEADER)
	$(CC) $(CFLAGS) -c mlx_hook.c fractol.h

draw.o : draw.c $(HEADER)
	$(CC) $(CFLAGS) -c draw.c fractol.h

change_iterations.o : change_iterations.c $(HEADER)
	$(CC) $(CFLAGS) -c change_iterations.c fractol.h