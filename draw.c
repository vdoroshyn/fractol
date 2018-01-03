/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw_one_pixel(int x, int y, t_all *a)
{
	int		i;

	if (x < 0 || y < 0 || x > a->win_x - 1 || y > a->win_y - 1)
	{
		return ;
	}
	i = x * 4 + y * a->size_line;
	a->str[i] = (unsigned char)(sin(0.016 * a->continuous_index + 4)
		* a->red + 25);
	a->str[i + 1] = (unsigned char)(sin(0.013 * a->continuous_index + 2)
		* a->green + 25);
	a->str[i + 2] = (unsigned char)(sin(0.01 * a->continuous_index + 1)
		* a->blue + 25);
	a->str[i + 3] = 0;
}

void		redraw_one_fractal(t_all *a)
{
	if (a->which_fractal == 1)
	{
		julia(a);
	}
	else if (a->which_fractal == 2)
	{
		mandelbrot(a);
	}
	else if (a->which_fractal == 3)
	{
		burning_ship(a);
	}
}
