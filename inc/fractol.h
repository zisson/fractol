/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 03:16:06 by zsina             #+#    #+#             */
/*   Updated: 2016/05/29 03:23:00 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "printf.h"
# include "../minilibx_macos/mlx.h"

# define HIGTH 		740
# define WIDTH		1240

# define JULIA		1
# define MANDEL		2
# define BURNI		3

# define F_BLUE		0
# define F_WHITE	1
# define F_RED		2
# define F_GREEN	3
# define F_OTHER	4

typedef struct		s_frac
{
	double	xmin;
	double	xmax;
	double	ymin;
	double	ymax;
	double	zoom;
	double	zoomx;
	double	zoomy;
	double	zr;
	double	zi;
	double	cr;
	double	ci;
	double	cr_ref;
	double	ci_ref;
	double	max_iter;
	double	x;
	double	y;
}					t_frac;

typedef struct		s_win
{
	void 			*win;
	int 			*img;
	int				type;
	char			*buf;
	int				line;
	t_frac			frac;
	int				b;
	int				col;
}					t_win;

typedef struct		s_env
{
	void			*mlx;
	t_win			**wins;
	int				id;
}					t_env;

/*
** parser function
*/
int     fract_parser(int ac, char **av, t_env *e);
int 	fract_help(void);

/*
** helper function
*/
void    fract_printab(char **tab);
void 		fract_printlst(t_list *lst);
int		fract_lstsrch(const t_list *lst, const void *ptr, size_t size);
void	fract_lstdel(void *content, size_t content_size);
int     fract_draw(t_env *e, t_win *w);
int		free_fractol(t_env *e);

/*
** init function
*/
void	init_mandel(t_frac *frac);
int		get_color(t_frac *f, int col, int nb, double max);
/*
** event function
*/
int	mandel_expose(t_env *e);

/*
** algo function
*/
void	my_mandelbrot(t_win *win, t_frac *f);
#endif
