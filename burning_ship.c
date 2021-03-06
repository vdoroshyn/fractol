/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			burning_ship_init(t_all *a)
{
	a->zoom = 1;
	a->move_x_axis = -0.5;
	a->move_y_axis = -0.5;
	a->iterations = 300;
	a->red = 153;
	a->green = 195;
	a->blue = 159;
}

static void		iterations_while(t_all *a)
{
	int			i;

	i = 0;
	while (i < a->iterations)
	{
		a->old_real = a->new_real;
		a->old_imaginary = a->new_imaginary;
		a->new_real = a->old_real * a->old_real -
		a->old_imaginary * a->old_imaginary + a->real;
		a->new_imaginary = 2 * fabs(a->old_real * a->old_imaginary)
		+ a->imaginary;
		if ((a->new_real * a->new_real +
			a->new_imaginary * a->new_imaginary) > 4)
		{
			break ;
		}
		++i;
	}
	a->continuous_index = i + 1 - (log(2) / 1) / log(2);
}

void			burning_ship(t_all *a)
{
	int			y;
	int			x;

	create_new_image(a);
	y = 0;
	while (y < a->win_y)
	{
		x = 0;
		while (x < a->win_x)
		{
			a->real = 1.5 * (x - a->win_x / 2) /
			(0.5 * a->zoom * a->win_x) + a->move_x_axis;
			a->imaginary = (y - a->win_y / 2) /
			(0.5 * a->zoom * a->win_y) + a->move_y_axis;
			a->new_real = 0;
			a->old_real = 0;
			a->new_imaginary = 0;
			a->old_imaginary = 0;
			iterations_while(a);
			draw_one_pixel(x, y, a);
			++x;
		}
		++y;
	}
	image_to_window_and_destroy(a);
}
