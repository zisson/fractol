#include "fractol.h"
#include <math.h>

void	init_mandel(t_frac *frac)
{
	frac->xmin = -2.1;
	frac->xmax = 0.6;
	frac->ymin = -1.2;
	frac->ymax = 1.2;
	frac->zoom = 1.;
	frac->zoomx = WIDTH / (frac->xmax - frac->xmin);
	frac->zoomy = HIGTH / (frac->ymax - frac->ymin);
	frac->max_iter = 30;
	frac->x = frac->xmin;
	frac->y = frac->ymin;
	frac->cr_ref = 0.;
	frac->ci_ref = 0.;
}

int		get_color(t_frac *f, int col, int nb, double max)
{
	double	tmp;

	if (col == F_BLUE)
		return ((nb == (int)max) ? 0 : (int)round(nb * 255. / max));
	else if (col == F_GREEN)
		return ((nb == (int)max) ? 0 : (int)round(nb * 255. / max) * 256);
	else if (col == F_RED)
		return ((nb == (int)max) ? 0 : (int)round(nb * 255. / max) * 65536);
	else if (col == F_WHITE)
		return ((nb == (int)max) ? 0 : (int)round(nb * 255. / max)
		+ round(nb * 255. / max) * 256 + round(nb * 255. / max) * 65536);
	else if (col == F_OTHER)
	{
		if (nb == (int)max)
			return (0);
		else if (((nb *= f->zoom) || 1) && nb < max / 3.)
			return ((int)round(nb * 3. * 255. / max));
		else if (nb < max / 1.5 && ((tmp = (nb - max / 3.) * 3.) || 1))
			return (255 - round(tmp * 255. / max)
					+ round(tmp * 255. / max) * 256);
		else if ((tmp = (nb - max / 1.5) * 3.) || 1)
			return (65535 - round(tmp * 255. / max) * 256.
					+ round(tmp * 255. / max) * 65536.);
	}
	return (0);
}
