/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:08:03 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/17 16:36:22 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_mandelbrot2(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	t_rgb	rgb;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	double x1 = ;
	double x2 = X2;
	double y1 = Y1;
	double y2 = Y2;

	unsigned int image_x = ((x2 - x1) * mlx->zoom);
	unsigned int image_y = ((y2 - y1) * mlx->zoom);
	for (unsigned int x = 0; x < image_x && x < RESO_X; x++)
	{
		for (unsigned int y = 0; y < image_y && y < RESO_Y; y++)
		{
			double c_r = (x / mlx->zoom) + x1;
			double c_i = (y / mlx->zoom) + y1;
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
			{
				rgb.r = i * 55 / mlx->iter_max;
				rgb.g = i * 55 / mlx->iter_max;
				rgb.b = i * 255 / mlx->iter_max;
				put_color_to_pixel(mlx, x, y, rgb);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
