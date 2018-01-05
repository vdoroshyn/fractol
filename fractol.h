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

	float			auxilary_x;
	float			auxilary_y;
}					t_all;

void				construct(t_all *a);
void				destruct(t_all *a);
void				create_new_image(t_all *a);
void				image_to_window_and_destroy(t_all *a);
int					proper_exit(t_all *a);

void				julia_init(t_all *a);
void				julia(t_all *a);
void				mandelbrot_init(t_all *a);
void				mandelbrot(t_all *a);
void				burning_ship_init(t_all *a);
void				burning_ship(t_all *a);

void				draw_one_pixel(int x, int y, t_all *a);
void				redraw_one_fractal(t_all *a);

int					my_key_func1(int keycode, t_all *a);
void				move(t_all *a, int keycode);
void				change_color(t_all *a, int keycode);
void				reset(t_all *a);
void				zoom(t_all *a, int keycode);
int					move_with_mouse(int x, int y, t_all *a);
int					zoom_with_mouse(int key, int x, int y, t_all *a);

#endif
