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

void		fdf_mandelbrot(void)
{
	ft_putendl("ok");
}

void		choice_type(char *str)
{
	if (ft_strstr(str, "Mandelbrot"))
		fdf_mandelbrot();
	else
	{
		ft_putendl("error");
		exit(1);
	}
}

t_env		*ft_initenv(void)
{
	t_env	*env;

	if (!(env = (t_env*)malloc(sizeof(t_env) + 1)))
		return (NULL);
	env->mlx = NULL;
	env->win = NULL;
	return (env);
}

int  		 main(int ac, char **av)
{
  	t_env	*e;

	if (!(e = ft_initenv()))
			return (-1);
	e->mlx = mlx_init();
	e->win = mlx_new_window(e->mlx, HIGTH, WIDTH, "fractol");
	if (ac > 1)
		choice_type(av[1]);
	else
	{
		ft_putendl("Help");
		exit(1);
	}
	mlx_loop(e->mlx);
	return (0);
}
