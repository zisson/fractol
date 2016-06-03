#include "fractol.h"

int	mandel_expose(t_env *e)
{
	int	i;

	i = -1;
	while (e->wins[++i])
		if (e->wins[i]->type == MANDEL)
		{
			e->id = i;
			break ;
		}
	mlx_put_image_to_window(e->mlx, e->wins[i]->win, e->wins[i]->img, 0, 0);
	return (1);
}
