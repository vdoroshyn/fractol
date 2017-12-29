#include "fractol.h"

void mandelbrot()
{
    t_all a;

    a.win_x = 800;
    a.win_y = 600;
    a.mlx = mlx_init();
    if (a.mlx == NULL)
        exit(0);
    a.win = mlx_new_window(a.mlx, a.win_x, a.win_y, "window");
    if (a.win == NULL)
        exit(0);
    a.img = mlx_new_image(a.mlx, a.win_x, a.win_y);
    a.str = mlx_get_data_addr(a.img, &a.bpp, &a.size_line, &a.endian);
    //each iteration, it calculates: newz = oldz*oldz + p, where p is the current pixel, and oldz stars at the origin
    double pr, pi;           //real and imaginary part of the pixel p
    double newRe, newIm, oldRe, oldIm;   //real and imaginary parts of new and old z
    double zoom = 1, moveX = -0.5, moveY = 0; //you can change these to zoom and change position
    int maxIterations = 300;//after how much iterations the function should stop

    //loop through every pixel
    for(int y = 0; y < a.win_y; y++)
    for(int x = 0; x < a.win_x; x++)
    {
      //calculate the initial real and imaginary part of z, based on the pixel location and zoom and position values
      pr = 1.5 * (x - a.win_x / 2) / (0.5 * zoom * a.win_x) + moveX;
      pi = (y - a.win_y / 2) / (0.5 * zoom * a.win_y) + moveY;
      newRe = newIm = oldRe = oldIm = 0; //these should start at 0,0
      //"i" will represent the number of iterations
      int i;
      //start the iteration process
      for(i = 0; i < maxIterations; i++)
      {
        //remember value of previous iteration
        oldRe = newRe;
        oldIm = newIm;
        //the actual iteration, the real and imaginary part are calculated
        newRe = oldRe * oldRe - oldIm * oldIm + pr;
        newIm = 2 * oldRe * oldIm + pi;
        //if the point is outside the circle with radius 2: stop
        if((newRe * newRe + newIm * newIm) > 4) break;
      }
      a.continuous_index = i + 1 - (log(2) / 1) / log(2);
      draw_fractal(x, y, &a);
    }
    mlx_put_image_to_window(a.mlx, a.win, a.img, 0, 0);
    mlx_hook(a.win, 2, 5, my_key_func1, &a);
    mlx_loop(a.mlx);
}