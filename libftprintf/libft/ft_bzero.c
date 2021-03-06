/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/06 15:48:10 by zsina             #+#    #+#             */
/*   Updated: 2014/11/15 17:37:43 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	char *tmp;

	tmp = (char *)s;
	if (n == 0)
		return ;
	while (n != 0)
	{
		*tmp++ = 0;
		n--;
	}
}
