/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   construct_destruct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		all_pointers_to_null(t_all *a)
{
	a->mlx = NULL;
	a->win = NULL;
	a->img = NULL;
	a->str = NULL;
}

void			construct(t_all *a)
{
	all_pointers_to_null(a);
	a->win_x = 800;
	a->win_y = 600;
	a->mlx = mlx_init();
	if (a->mlx == NULL)
		proper_exit(a);
	a->win = mlx_new_window(a->mlx, a->win_x, a->win_y, "window");
	if (a->win == NULL)
		proper_exit(a);
	a->img = mlx_new_image(a->mlx, a->win_x, a->win_y);
	if (a->img == NULL)
		proper_exit(a);
	a->str = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endian);
	if (a->str == NULL)
		proper_exit(a);
	a->toggle = 0;
}

void			destruct(t_all *a)
{
	if (a->mlx != NULL)
	{
		free(a->mlx);
		a->mlx = NULL;
	}
	if (a->win != NULL)
	{
		free(a->win);
		a->win = NULL;
	}
	if (a->img != NULL)
	{
		free(a->img);
		a->img = NULL;
	}
	if (a->str != NULL)
	{
		free(a->str);
		a->str = NULL;
	}
}

void			proper_exit(t_all *a)
{
	destruct(a);
	exit(0);
}

int				mouse_exit(void)
{
	exit(1);
}
