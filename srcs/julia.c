/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:31:08 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:58:04 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_julia(t_mlx *mlx, t_datas *datas)
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
			double z_r = x / mlx->zoom + datas->x1;
			double z_i = y / mlx->zoom + datas->y1;
			unsigned int i = 0;
			do {
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + datas->c_r;
				z_i = 2 * z_i * tmp + datas->c_i;
				++i;
			}while (z_r * z_r + z_i * z_i < 4 && i < mlx->iter_max);
			if (i != mlx->iter_max)
			{
//				rgb.r = i * 255 / mlx->iter_max;
//				put_color_to_pixel(mlx, x, y, rgb);
				color(mlx, i, rgb, x, y);
			}
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
