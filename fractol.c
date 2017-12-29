/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vdoroshy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 16:08:59 by vdoroshy          #+#    #+#             */
/*   Updated: 2017/03/02 13:39:17 by vdoroshy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		launch_fractal(char *ar, t_all *container)
{
	if (!ft_strcmp(ar, "1"))
	{
		julia(container);
		return (1);
	}
	else if (!ft_strcmp(ar, "2"))
	{
		mandelbrot();
		return (1);
	}
	else if (!ft_strcmp(ar, "3"))
	{
		burning_ship();
		return (1);
	}
	return (0);
}

static void		is_valid_arg(int num, char **ar, t_all *container)
{
	if (num != 2 || !launch_fractal(ar[1], container))
	{
		write(1, "usage: ./fractol fractal_of_your_choice\n", 40);
		write(1, "enter 1 to see Julia\n", 21);
		write(1, "enter 2 to see Mandelbrot\n", 26);
		write(1, "enter 3 to see Burning ship\n", 28);
		exit(0);
	}
}

void			draw_fractal(int x, int y, t_all *a)
{
	int			i;

	if (x < 0 || y < 0 || x > a->win_x - 1 || y > a->win_y - 1)
	{
		return ;
	}
	i = x * 4 + y * a->size_line;
	a->str[i] = (unsigned char)(sin(0.016 * a->continuous_index + 4) * 255 + 25);
	a->str[i + 1] = (unsigned char)(sin(0.013 * a->continuous_index + 2) * 211 + 25);
	a->str[i + 2] = (unsigned char)(sin(0.01 * a->continuous_index + 1) * 181 + 25);
	a->str[i + 3] = 0;
}

// void		move_up(t_all *a, int keycode)
// {
// 	//move_x move_y
// }

// int 	zoom_with_mouse(int key, int x, int y, t_all *a)
// {
// // 	if (key == 5)
// //  {
// //   fract->zoom /= 1.1;
// //   fract->move_x += -((fract->h / 2 - fract->x) / 1000) / fract->zoom;
// //   fract->move_y += -((fract->w / 2 - fract->y) / 1000) / fract->zoom;
// //  }
// // if (key == 4)
// //  {
// //   fract->zoom *= 1.1;
// //   fract->move_x += -((fract->h / 2 - fract->x) / 1000) / fract->zoom;
// //   fract->move_y += -((fract->w / 2 - fract->y) / 1000) / fract->zoom;
// //  }
// }

// int			move_with_mouse(int x, int y, t_all *a)
// {
// 	 // cRe = -0.7;
//   // cIm = 0.27015;
// 	// if (nazhat probel?)
// 	if (x >= a.win_x / 2 && x < a.win_x)
// 	{
// 		// a->c_im += ((x - a->w / 2) * 0.00002);
//   //  a->c_re += ((x - a->w / 2) * 0.00002);
// 	}
// 	if (x < a.win_x / 2 && x > 0)
// 	{
// 				// a->c_im -= ((x - a->w / 2) * 0.00002);
//   //  a->c_re -= ((x - a->w / 2) * 0.00002);
// 	}
// 	//prisvoit v struct x && y
// 	mlx_mouse_hook(a->win, zoom_with_mouse, a);
// 	// julia_otrisovka
// }

int				my_key_func1(int keycode, t_all *a)
{
	if (keycode == 53 && a)
		exit(0);
	// else if (keycode == 126)
	// 	move_up(a, keycode);
	// else if (keycode == 49)
	// 	mlx_hook(a->win, 6, 5, move_with_mouse, a);
	return (0);
}

static void		construct(t_all *a)
{
	a->win_x = 800;
	a->win_y = 600;
	a->mlx = mlx_init();
	if (a->mlx == NULL)
		exit(0);
	a->win = mlx_new_window(a->mlx, a->win_x, a->win_y, "window");
	if (a->win == NULL)
		exit(0);
	a->img = mlx_new_image(a->mlx, a->win_x, a->win_y);
	a->str = mlx_get_data_addr(a->img, &a->bpp, &a->size_line, &a->endian);
	if (a->str == NULL)
		exit(0);
}

int				main(int argc, char **argv)
{
	t_all container;

	construct(&container);
	is_valid_arg(argc, argv, &container);
	return (0);
}
