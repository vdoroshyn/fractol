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

static int		is_valid_arg(char *ar)
{
	if (ar[0] == '1' || ar[0] == '2' || ar[0] == '3')
	{
		return (1);
	}
	return (0);
}

static void		ft_usage(int num, char **ar)
{
	if (num != 2 || !is_valid_arg(ar[1]))
	{
		write(1, "usage: ./fractol fractal_of_your_choice\n", 40);
		write(1, "enter 1 to see Julia\n", 21);
		write(1, "enter 2 to see Mandelbrot\n", 26);
		write(1, "enter 3 to see blah\n", 20);
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	// t_all		abyss;

	ft_usage(argc, argv);
	return (0);
}
