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

static int		which_fractal(char *ar, t_all *a)
{
	if (!ft_strcmp(ar, "1"))
	{
		a->which_fractal = 1;
		return (1);
	}
	else if (!ft_strcmp(ar, "2"))
	{
		a->which_fractal = 2;
		return (1);
	}
	else if (!ft_strcmp(ar, "3"))
	{
		a->which_fractal = 3;
		return (1);
	}
	return (0);
}

static void		is_valid_arg(int num, char **ar, t_all *a)
{
	if (num != 2 || !which_fractal(ar[1], a))
	{
		write(1, "usage: ./fractol fractal_of_your_choice\n", 40);
		write(1, "enter 1 to see Julia\n", 21);
		write(1, "enter 2 to see Mandelbrot\n", 26);
		write(1, "enter 3 to see Burning ship\n", 28);
		exit(0);
	}
}

static void		launch_fractal(t_all *a)
{
	if (a->which_fractal == 1)
	{
		julia_init(a);
		julia(a);
	}
	else if (a->which_fractal == 2)
	{
		mandelbrot_init(a);
		mandelbrot(a);
	}
	else if (a->which_fractal == 3)
	{
		burning_ship_init(a);
		burning_ship(a);
	}
}

int				main(int argc, char **argv)
{
	t_all		a;

	is_valid_arg(argc, argv, &a);
	construct(&a);
	launch_fractal(&a);
	mlx_hook(a.win, 2, 5, my_key_func1, &a);
	mlx_hook(a.win, 6, 5, move_with_mouse, &a);
	mlx_hook(a.win, 17, 1L << 17, proper_exit, &a);
	mlx_loop(a.mlx);
	return (0);
}
