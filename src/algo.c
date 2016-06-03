#include "fractol.h"

void	my_mandelbrot(t_win *win, t_frac *f)
{
	int		i;
	int		x;
	int		y;
	double	tmp;

	y = -1;
	while (++y < HIGTH && (x = -1))
	{
		f->ci = y / f->zoomy + f->y;
		while (++x < WIDTH)
		{
			f->cr = x / f->zoomx + f->x;
			f->zr = f->cr_ref;
			f->zi = f->ci_ref;
			i = -1;
			while (++i < (int)f->max_iter && f->zr * f->zr + f->zi * f->zi < 4)
			{
				tmp = f->zr;
				f->zr = f->zr * f->zr - f->zi * f->zi + f->cr;
				f->zi = 2 * f->zi * tmp + f->ci;
			}
			*(int *)(win->buf + y * win->line + x * 4) =
				get_color(f, win->col, i, f->max_iter);
		}
	}
}
