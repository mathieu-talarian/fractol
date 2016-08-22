/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 17:08:03 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:58:05 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

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
				z_r = carre(z_r) - carre(z_i) + c_r;
				z_i = 2 * z_i * tmp + c_i;
				++i;
			}while (carre(z_r) + carre(z_i) < 4 && i < mlx->iter_max);
			if (i != mlx->iter_max)
				color(mlx, i, rgb, x, y);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	do_mandelbrot3(t_mlx *mlx, t_datas *datas)
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
				z_r = cube(z_r) - (3 * z_r * carre(z_i)) + c_r;
				z_i = (3 * carre(tmp) * z_i) - cube(z_i) + c_i;
				++i;
			}while (cube(z_r) + cube(z_i) < 8 && i < mlx->iter_max);
			if (i != mlx->iter_max)
				color(mlx, i, rgb, x, y);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}

void	do_mandelbrot4(t_mlx *mlx, t_datas *datas)
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
				z_r = p_4(z_r) - (6 * carre(z_r) * carre(z_i)) + p_4(z_i) + c_r;
				z_i = (4 * cube(tmp) * z_i) - (4 * tmp * cube(z_i)) + c_i;
				++i;
			}while (p_4(z_r) + p_4(z_i) < p_4(2) && i < mlx->iter_max);
			if (i != mlx->iter_max)
				color(mlx, i, rgb, x, y);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
