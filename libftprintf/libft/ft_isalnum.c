/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <zsina@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/04 13:35:42 by zsina             #+#    #+#             */
/*   Updated: 2014/11/04 13:42:03 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int		ft_isalnum(int c)
{
	if (ft_isalpha(c) != 0)
		return (1);
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}
