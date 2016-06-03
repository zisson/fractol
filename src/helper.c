#include "fractol.h"

void        fract_printab(char **tab)
{
    int     i;

    i = 1;
    while (tab[i])
    {
        ft_putendl(tab[i]);
        i++;
    }
}

void 		fract_printlst(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	if (!lst)
    {
        ft_putendl("vide");
		return ;
    }
	while (lst)
	{
		ft_printf("%d", (int)lst->content);
		lst = lst->next;
	}
}

/************************************************/
int		fract_lstsrch(const t_list *lst, const void *ptr, size_t size)
{
	(void)ptr;
	return (*(int *)(lst->content) == (int)size);
}

void	fract_lstdel(void *content, size_t content_size)
{
	(void)content;
	(void)content_size;
}

int     fract_draw(t_env *e, t_win *w)
{
    if (w->type == MANDEL)
        my_mandelbrot(w, &w->frac);
    mlx_put_image_to_window(e->mlx, w->win, w->img, 0, 0);
    return (1);
}

int		free_fractol(t_env *e)
{
	int	i;

	if (e->wins)
	{
		i = -1;
		while (e->wins[++i])
		{
			if (e->wins[i]->img)
				mlx_destroy_image(e->mlx, e->wins[i]->img);
			if (e->wins[i]->win)
				mlx_destroy_window(e->mlx, e->wins[i]->win);
			free(e->wins[i]);
		}
		free(e->wins);
	}
	if (e->mlx)
		free(e->mlx);
	exit(0);
	return (0);
}
