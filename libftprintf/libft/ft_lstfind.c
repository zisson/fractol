#include "includes/list.h"

t_list	*ft_lstfind(t_list *lst, const void *content_ref, size_t size_ref,
		int (*cmp)(const t_list *, const void *, size_t))
{
	if (!content_ref || !cmp || !size_ref)
		return (NULL);
	while (lst)
	{
		if ((*cmp)(lst, content_ref, size_ref))
			break ;
		lst = lst->next;
	}
	return (lst);
}
