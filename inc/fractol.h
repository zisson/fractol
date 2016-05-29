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
# include <mlx.h>

# define HIGTH 1240
# define WIDTH 740

typedef struct		s_env
{
	void			*mlx;
	void			*win;
}					t_env;
#endif
