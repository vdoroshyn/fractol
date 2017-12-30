/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		move_right(t_all *a)
{
	a->move_x_axis -= 0.02;
}

static void		move_left(t_all *a)
{
	a->move_x_axis += 0.02;
}

static void		move_up(t_all *a)
{
	a->move_y_axis += 0.02;
}

static void		move_down(t_all *a)
{
	a->move_y_axis -= 0.02;
}

void			move(t_all *a, int keycode)
{
	if (keycode == 123)
	{
		move_left(a);
	}
	else if (keycode == 124)
	{
		move_right(a);
	}
	else if (keycode == 125)
	{
		move_down(a);
	}
	else if (keycode == 126)
	{
		move_up(a);
	}
	redraw_one_fractal(a);
}
