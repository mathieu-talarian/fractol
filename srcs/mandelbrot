/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:33:12 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/17 15:05:15 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "mandelbrot.h"

void	draw(t_mandel datas, t_rgb rgb, t_mlx *mlx)
{
	int i;

	i = 0;
	while ((D.z_r * D.z_r + D.z_i * D.z_i) < 4 && i < I_MAX)
	{
		D.tmp = D.z_r;
		D.z_r = D.z_r * D.z_r - D.z_i * D.z_i + D.c_r;
		D.z_i = 2 * D.z_i * D.tmp + D.c_i;
		i++;
	}
	if (i == I_MAX)
		put_color_to_pixel(mlx, D.x, D.y, rgb);
	else
	{
//		R.b = i * 255 / I_MAX;
		R.g = i * 230 / I_MAX;
//		R.r = i * 255 / I_MAX;
		put_color_to_pixel(mlx, D.x, D.y, R);
	}
}

void	put_mandelbrot(t_mlx *mlx, t_mandel datas)
{
	t_rgb		rgb;

	D.zoom_x = IMAGE_X / (X2 - X1);
	D.zoom_y = IMAGE_Y / (Y2 - Y1);
	D.c_r = D.x / D.zoom_x + X1;
	D.c_i = D.y / D.zoom_y + Y1;
	D.z_r = 0;
	D.z_i = 0;
	R.r = 0;
	R.g = 0;
	R.b = 0;
	draw(D, R, mlx);
}

void	draw_mandelbrot(t_mlx *mlx)
{
	t_mandel	datas;

	D.x = 0;
	D.y = 0;
	while (D.y < RESO_Y)
	{
		D.x = 0;
		while (D.x < RESO_X)
		{
			put_mandelbrot(mlx, D);
			D.x++;
		}
		D.y++;
	}
}

void	do_mandelbrot(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, \
			&mlx->endian);
	draw_mandelbrot(mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
