/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_iterations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		increase_iterations(t_all *a)
{
	if (a->iterations + 2 <= 700)
		a->iterations += 2;
}

static void		decrease_iterations(t_all *a)
{
	if (a->iterations - 2 >= 50)
		a->iterations -= 2;
}

void			change_iterations(t_all *a, int keycode)
{
	if (keycode == 34)
		increase_iterations(a);
	else if (keycode == 31)
		decrease_iterations(a);
	redraw_one_fractal(a);
}
