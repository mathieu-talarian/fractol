/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 19:23:23 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 19:52:35 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	make_colors(t_col datas_col, unsigned int *r, unsigned int *g, \
		unsigned int *b)
{
	*r = 255;
	*g = mod_color(datas_col.a, datas_col.b);
	*b = 0;
}

void	make_colors2(int color_style, t_rgb *rgb, t_iter iter, int iter_max)
{
	if (color_style == 83)
		col(&rgb->r, iter, iter_max);
	else if (color_style == 84)
		col(&rgb->g, iter, iter_max);
	else if (color_style == 85)
		col(&rgb->b, iter, iter_max);
	else if (color_style == 86)
	{
		col(&rgb->r, iter, iter_max);
		col(&rgb->g, iter, iter_max);
	}
	else if (color_style == 87)
	{
		col(&rgb->r, iter, iter_max);
		col(&rgb->b, iter, iter_max);
	}
	else if (color_style == 88)
	{
		col(&rgb->b, iter, iter_max);
		col(&rgb->g, iter, iter_max);
	}
}
