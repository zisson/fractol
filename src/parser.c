#include "fractol.h"

static int	lst_add_elem(t_list **lst, int type, int *nb)
{
	t_list	*tmp;

	if (!(tmp = ft_lstnew(&type, sizeof(int))))
	{
		ft_lstdel(lst, &fract_lstdel);
		return (0);
	}
	ft_lstpush(lst, tmp);
	(*nb)++;
	return (1);
}

static int init_list(int ac, char **av, t_list **lst)
{
    int     i;
    int     j;
    int     nb;

    i = 0;
    nb = 0;
    *lst = NULL;
    while (++i < ac && (j = -1))
    {
        while (av[i][++j])
            av[i][j] = (char)ft_tolower(av[i][j]);
        if (ft_strcmp(av[i], "mandelbrot") == 0
            && !ft_lstfind(*lst, &i, MANDEL, &fract_lstsrch)
            && !lst_add_elem(lst, MANDEL, &nb))
            return (-1);
        else if (ft_strcmp(av[i], "julia") == 0
            && !ft_lstfind(*lst, &i, JULIA, &fract_lstsrch)
            && !lst_add_elem(lst, JULIA, &nb))
            return (-1);
        else if (ft_strcmp(av[i], "burning_ship") == 0
            && !ft_lstfind(*lst, &i, BURNI, &fract_lstsrch)
            && !lst_add_elem(lst, BURNI, &nb))
            return (-1);
    }
    return (nb);
}

static int	list_fractol(t_list *lst, t_env *e, int nb)
{
    int     i;
    int     bpp;
	int		endian;

    i = nb + 1;
    while (--i >= 0)
		e->wins[i] = NULL;
    while (++i < nb)
    {
         if (!(e->wins[i] = (t_win*)malloc(sizeof(t_win))))
             return (0);
        if ((e->wins[i]->type  = *(int*)(lst->content)) == MANDEL)
            e->wins[i]->win = mlx_new_window(e->mlx, WIDTH, HIGTH, "mandel");
        lst = lst->next;
        e->wins[i]->img = NULL;
        if (!e->wins[i]->win
            || !(e->wins[i]->img = mlx_new_image(e->mlx, WIDTH, HIGTH)))
            return (0);
        e->wins[i]->buf = mlx_get_data_addr(e->wins[i]->img, &bpp,
        &e->wins[i]->line, &endian);
		ft_printf("%d, %d, %d", bpp, e->wins[i]->line, endian);
    }
	return (1);
}


int     fract_parser(int ac, char **av, t_env *e)
{
    int     nb;
    t_list  *lst;

    if (ac < 2)
        return (0);
    e->wins = NULL;
    if ((nb = init_list(ac, av, &lst)) < 1)
        return (nb);
    if (!(e->wins = (t_win**)malloc((unsigned long)(nb + 1) * sizeof(t_win*))))
        return (0);
    if (!list_fractol(lst, e, nb))
    {
        ft_lstdel(&lst, &fract_lstdel);
        return (-1);
    }
    ft_lstdel(&lst, &fract_lstdel);
    return (1);
}
