/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calclen_o.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zsina <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/01 09:37:00 by zsina             #+#    #+#             */
/*   Updated: 2016/04/01 10:51:05 by zsina            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

static size_t	ft_zeroflag(t_pfdata *data, ssize_t outputlen)
{
	if (data->prec == NO_PREC)
		ft_swap(&data->prec, &data->width);
	else
		ft_swap(&data->prec, &data->width);
	return (outputlen);
}

size_t			ft_calclen_o(int sign, int strsize, t_pfdata *data,
		const char *base)
{
	ssize_t		ouputlen;

	ouputlen = MAX(data->prec, strsize);
	if (sign < 0 || ((data->flag & PLUSFLAG || data->flag & SPACEFLAG)
				&& sign > 0))
	{
		ouputlen++;
		strsize++;
	}
	if (data->flag & DIESEFLAG)
		ouputlen = ft_managediez_too(data, base, ouputlen, sign);
	if (data->flag & ZEROFLAG || data->flag & SPACEFLAG)
		ouputlen = ft_zeroflag(data, ouputlen);
	else
		ouputlen = ft_manago_precwid(ouputlen, strsize, data);
	return (ouputlen);
}
