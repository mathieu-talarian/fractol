/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:08:03 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/19 16:26:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

unsigned int	mod_color(int i, int iter_max)
{
	return (255 - (i % (iter_max / 6)) * (255 / (iter_max/6)));
}

void	color(t_mlx *mlx, int i, t_rgb rgb, int x, int y)
{
	static int cpt = 0;
	int col;
	col = i / (mlx->iter_max / 6);
	if (col == 0)
	{
		rgb.r = 255;
		rgb.g = 255 - (i % (mlx->iter_max / 6)) * (255 / (mlx->iter_max/6));
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
/*	else
	{
	rgb.r = i * 255 / mlx->iter_max;
	rgb.g = i * 255 / mlx->iter_max;
	rgb.b = i * 255 / mlx->iter_max;
	}*/
	put_color_to_pixel(mlx, x, y, rgb);
}

void	do_mandelbrot2(t_mlx *mlx, t_datas *datas)
{
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	t_rgb	rgb;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;


	unsigned int image_x = ((datas->x2 - datas->x1) * mlx->zoom);
	unsigned int image_y = ((datas->y2 - datas->y1) * mlx->zoom);
	for (unsigned int x = 0; x < image_x && x < RESO_X; x++)
	{
		for (unsigned int y = 0; y < image_y && y < RESO_Y; y++)
		{
			double c_r = (x / mlx->zoom) + datas->x1;
			double c_i = (y / mlx->zoom) + datas->y1;
			double z_r = 0;
			double z_i = 0;
			unsigned int i = 0;
			do {
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}while (z_r * z_r + z_i * z_i < 4 && i < mlx->iter_max);
			if (i != mlx->iter_max)
				color(mlx, i, rgb, x, y);
		}
	}
	rgb.r = 255;
	rgb.g = 255;
	rgb.b = 0;
	put_color_to_pixel(mlx, RESO_X / 2, RESO_Y / 2, rgb);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
