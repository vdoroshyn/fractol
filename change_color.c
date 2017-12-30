/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_color.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		change_red(t_all *a)
{
	a->red = (a->red + 10) % 256;
}

static void		change_green(t_all *a)
{
	a->green = (a->green + 10) % 256;
}

static void		change_blue(t_all *a)
{
	a->blue = (a->blue + 10) % 256;
}

void			change_color(t_all *a, int keycode)
{
	if (keycode == 12)
		change_red(a);
	else if (keycode == 13)
		change_green(a);
	else if (keycode == 14)
		change_blue(a);
	redraw_one_fractal(a);
}
