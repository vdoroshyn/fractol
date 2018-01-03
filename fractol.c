/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		which_fractal(char *ar, t_all *container)
{
	if (!ft_strcmp(ar, "1"))
	{
		container->which_fractal = 1;
		return (1);
	}
	else if (!ft_strcmp(ar, "2"))
	{
		container->which_fractal = 2;
		return (1);
	}
	else if (!ft_strcmp(ar, "3"))
	{
		container->which_fractal = 3;
		return (1);
	}
	return (0);
}

static void		is_valid_arg(int num, char **ar, t_all *container)
{
	if (num != 2 || !which_fractal(ar[1], container))
	{
		write(1, "usage: ./fractol fractal_of_your_choice\n", 40);
		write(1, "enter 1 to see Julia\n", 21);
		write(1, "enter 2 to see Mandelbrot\n", 26);
		write(1, "enter 3 to see Burning ship\n", 28);
		exit(0);
	}
}

static void		launch_fractal(t_all *container)
{
	if (container->which_fractal == 1)
	{
		julia_init(container);
		julia(container);
	}
	else if (container->which_fractal == 2)
	{
		mandelbrot_init(container);
		mandelbrot(container);
	}
	else if (container->which_fractal == 3)
	{
		burning_ship_init(container);
		burning_ship(container);
	}
}

int				main(int argc, char **argv)
{
	t_all		container;

	is_valid_arg(argc, argv, &container);
	construct(&container);
	launch_fractal(&container);
	mlx_hook(container.win, 2, 5, my_key_func1, &container);
	mlx_hook(container.win, 6, 5, move_with_mouse, &container);
	mlx_hook(container.win, 17, 1L << 17, mouse_exit, &container);
	mlx_loop(container.mlx);
	mlx_destroy_image(container.mlx, container.win);
	mlx_destroy_window(container.mlx, container.win);
	return (0);
}
