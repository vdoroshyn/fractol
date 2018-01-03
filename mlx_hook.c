/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		zoom_with_mouse(int key, int x, int y, t_all *a)
{
	x = y;
	if (key == 4)
	{
		a->zoom /= 1.1;
		a->move_x_axis += -((a->win_x / 2 - a->auxilary_x)) / 1000 / a->zoom;
		a->move_y_axis += -((a->win_y / 2 - a->auxilary_y)) / 1000 / a->zoom;
	}
	if (key == 5)
	{
		a->zoom *= 1.1;
		a->move_x_axis += -((a->win_y / 2 - a->auxilary_x) / 1000) / a->zoom;
		a->move_y_axis += -((a->win_x / 2 - a->auxilary_y) / 1000) / a->zoom;
	}
	redraw_one_fractal(a);
	return (0);
}

int		move_with_mouse(int x, int y, t_all *a)
{
	if (a->toggle == 1)
	{
		if (x >= a->win_x / 2 && x < a->win_x)
		{
			a->imaginary += ((x - a->win_x / 2) * 0.00002);
			a->real += ((x - a->win_x / 2) * 0.00002);
		}
		if (x < a->win_x / 2 && x > 0)
		{
			a->imaginary -= ((a->win_x / 2 - x) * 0.00002);
			a->real -= ((a->win_x / 2 - x) * 0.00002);
		}
		redraw_one_fractal(a);
	}
	a->auxilary_x = x;
	a->auxilary_y = y;
	mlx_mouse_hook(a->win, zoom_with_mouse, a);
	return (0);
}

void	zoom(t_all *a, int keycode)
{
	if (keycode == 69)
	{
		a->zoom *= 1.1;
	}
	else if (keycode == 78)
	{
		a->zoom /= 1.1;
	}
	redraw_one_fractal(a);
}

void	reset(t_all *a)
{
	if (a->which_fractal == 1)
		julia_init(a);
	else if (a->which_fractal == 2)
		mandelbrot_init(a);
	else if (a->which_fractal == 3)
		burning_ship_init(a);
	redraw_one_fractal(a);
}

int		my_key_func1(int keycode, t_all *a)
{
	if (keycode == 53)
		proper_exit(a);
	else if (keycode == 123 || keycode == 124
		|| keycode == 125 || keycode == 126)
		move(a, keycode);
	else if (keycode == 12 || keycode == 13 || keycode == 14)
		change_color(a, keycode);
	else if (keycode == 69 || keycode == 78)
		zoom(a, keycode);
	else if (keycode == 15)
		reset(a);
	else if (keycode == 49 && a->which_fractal == 1)
		a->toggle = !a->toggle;
	return (0);
}
