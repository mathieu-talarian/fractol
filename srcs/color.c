/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:27:58 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:32:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mod_color(int i, int iter_max)
{
	return (255 - (i % (iter_max / 6)) * (255 / (iter_max/6)));
}

void	color(t_mlx *mlx, int i, t_rgb rgb, int x, int y)
{
	int col;

	col = i / (mlx->iter_max / 6);
	if (col == 0)
	{
		rgb.r = 255;
		rgb.g = mod_color(i, mlx->iter_max);
		rgb.b = 0;
	}
	if (col == 1)
	{
		rgb.r = mod_color(i, mlx->iter_max);
		rgb.g = 255;
		rgb.b = 0;
	}
	if (col == 2)
	{
		rgb.r = 0;
		rgb.g = 255;
		rgb.r = mod_color(i, mlx->iter_max);
	}
	if (col == 3)
	{
		rgb.r = 0;
		rgb.g = mod_color(i, mlx->iter_max);
		rgb.b = 255;
	}
	if (col == 4)
	{
		rgb.r = mod_color(i, mlx->iter_max);
		rgb.g = 0;
		rgb.b = 255;
	}
	if (col == 5)
	{
		rgb.r = 255;
		rgb.g = 0;
		rgb.b = mod_color(i, mlx->iter_max);
	}
	put_color_to_pixel(mlx, x, y, rgb);
}
