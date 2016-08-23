/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:58 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 19:51:35 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mod_color(int i, int iter_max)
{
	return (255 - (i % (iter_max / 6)) * (255 / (iter_max / 6)));
}

void			color(t_mlx *mlx, t_iter iter, t_rgb *rgb)
{
	t_col	datas_col;
	int		col;

	col = iter.i / (mlx->iter_max / 6);
	datas_col.a = iter.i;
	datas_col.b = mlx->iter_max;
	if (col == 0)
		make_colors(datas_col, &rgb->r, &rgb->g, &rgb->b);
	if (col == 1)
		make_colors(datas_col, &rgb->g, &rgb->r, &rgb->b);
	if (col == 2)
		make_colors(datas_col, &rgb->g, &rgb->b, &rgb->r);
	if (col == 3)
		make_colors(datas_col, &rgb->r, &rgb->g, &rgb->b);
	if (col == 4)
		make_colors(datas_col, &rgb->b, &rgb->g, &rgb->r);
	if (col == 5)
		make_colors(datas_col, &rgb->r, &rgb->b, &rgb->g);
}

void			col(unsigned int *color, t_iter iter, int iter_max)
{
	*color = iter.i * 255 / iter_max;
}

void			log_color(t_mlx *mlx, t_iter iter)
{
	t_rgb rgb;

	color(mlx, iter, &rgb);
	if (mlx->color_style == 1)
		put_color_to_pixel1(mlx, iter.x, iter.y, rgb);
	else if (mlx->color_style == 2)
		put_color_to_pixel2(mlx, iter.x, iter.y, rgb);
	else if (mlx->color_style == 3)
		put_color_to_pixel3(mlx, iter.x, iter.y, rgb);
	else if (mlx->color_style == 4)
		put_color_to_pixel4(mlx, iter.x, iter.y, rgb);
}

void			init_color(t_mlx *mlx, t_iter iter)
{
	t_rgb rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	if (1 <= mlx->color_style && mlx->color_style <= 4)
		log_color(mlx, iter);
	else
	{
		make_colors2(mlx->color_style, &rgb, iter, mlx->iter_max);
		put_color_to_pixel1(mlx, iter.x, iter.y, rgb);
	}
}
