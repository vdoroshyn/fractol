/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 14:05:44 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/16 14:28:47 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft/libft.h"
# include "mlx.h"

typedef struct		s_all
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				bpp;
	int				size_line;
	int				endian;
	int				win_x;
	int				win_y;
	int				continuous_index;
	int				red;
	int				green;
	int				blue;
}					t_all;

void				julia(t_all *container);
void				mandelbrot();
void				burning_ship();
int					my_key_func1(int keycode, t_all *a);
void				draw_fractal(int x, int y, t_all *a);
#endif
