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
	int				which_fractal;
	int				toggle;
	
	int				continuous_index;
	int				red;
	int				green;
	int				blue;
	double			real;
	double			imaginary;
	double			new_real;
	double			old_real;
	double			new_imaginary;
	double			old_imaginary;
	double			zoom;
	double			move_x_axis;
	double			move_y_axis;
	int				iterations;
}					t_all;

void				construct(t_all *container);
void				destruct(t_all *container);

void				julia_init(t_all *container);
void				julia(t_all *container);
void				mandelbrot_init(t_all *container);
void				mandelbrot(t_all *container);
void				burning_ship_init(t_all *container);
void				burning_ship(t_all *container);

void				draw_fractal(int x, int y, t_all *container);
void				redraw_one_fractal(t_all *container);

int					my_key_func1(int keycode, t_all *container);
void				move(t_all *container, int keycode);
void				change_color(t_all *a, int keycode);
#endif
