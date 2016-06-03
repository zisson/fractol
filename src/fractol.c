/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 03:15:37 by zsina             #+#    #+#             */
/*   Updated: 2016/05/29 03:42:31 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*static void init_win(t_env *e, t_win *win, void (*fct_init)(), int (*fct_exp)())
{
	win->b = 0;
	win->col = F_BLUE;
	(*fct_init)(&win->frac);
	fract_draw(e, win);
	(void)fct_exp;
//	mlx_expose_hook(win->win, fct_exp, e);
}

int 		fract_help(void)
{
	ft_putendl("Usage: ./fractol [mandelbrot]");
	return (1);
}

int  		 main(int ac, char **av)
{
	int		ret;
  	t_env	e;
	int		i;

	 if (!(e.mlx = mlx_init()))
		 return (0);
	if ((ret = fract_parser(ac, av, &e)) == 0)
		return(fract_help());
	if (ret > 0 && (i = -1))
	{
		while (e.wins[++i])
			if (e.wins[i]->type == MANDEL)
			 	init_win(&e, e.wins[i], &init_mandel, &mandel_expose);
		mlx_loop(e.mlx);
	}
	return(free_fractol(&e));
}*/

void    my_pixel_put_to_image(unsigned long img_color, char *data, int sizeline, int bpp, int x, int y)
{
 // int i;
  unsigned char color1;
  unsigned char color2;
  unsigned char color3;
  color1 = (img_color & 0xFF00000) >> 24;
  color2 = (img_color & 0xFF00000) >> 16;
  color3 = (img_color & 0xFF00000) >> 8;
  data[y * sizeline + x * bpp / 8 ] = color1;
  data[y * sizeline + x * bpp / 8 + 1] = color2;
  data[y * sizeline + x * bpp / 8 + 2] = color3;
}
int     main()
{
  void  *mlx_ptr;
  void  *win_ptr;
  void  *img_ptr;
  char  *data;
  int   bpp;
  int   sizeline;
  int   endian;
  unsigned long img_color;
  int   z;
  int   y;
  z = 0;
  y = 0;
  mlx_ptr = mlx_init();
  img_ptr = mlx_new_image(mlx_ptr, 500, 500);
  data = mlx_get_data_addr(img_ptr, &bpp, &sizeline, &endian);
  img_color = mlx_get_color_value(mlx_ptr, 0xf8f8ff);
  while (z < 500)
    {
      my_pixel_put_to_image(img_color, data, sizeline, bpp, z, y);
      z++;
      if (z == 500 && y < 500)
        {
          z = 0;
          y++;
        }
    }
  win_ptr = mlx_new_window(mlx_ptr, 500, 500, "WOLF SUCK A LOT !" );
  mlx_put_image_to_window(mlx_ptr, win_ptr, img_ptr, 0, 0);
  mlx_loop(mlx_ptr);
  return(0);
}
