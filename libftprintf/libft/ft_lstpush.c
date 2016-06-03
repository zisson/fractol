#include "includes/list.h"

void	ft_lstpush(t_list **alst, t_list *add)
{
	t_list	*i;

	if (!alst || !add)
		return ;
	if (!*alst)
		return ((void)(*alst = add));
	i = *alst;
	while (i->next)
		i = i->next;
	i->next = add;
}
