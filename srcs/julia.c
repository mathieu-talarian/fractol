/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:31:08 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:37:02 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_julia(void *params)
{
	t_mlx *mlx;
	mlx = params;
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	t_rgb	rgb;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	unsigned int image_x = ((mlx->datas->x2 - mlx->datas->x1) * mlx->zoom);
	unsigned int image_y = ((mlx->datas->y2 - mlx->datas->y1) * mlx->zoom);
	for (unsigned int x = 0; x < image_x && x < RESO_X; x++)
	{
		for (unsigned int y = 0; y < image_y && y < RESO_Y; y++)
		{
			double z_r = x / mlx->zoom + mlx->datas->x1;
			double z_i = y / mlx->zoom + mlx->datas->y1;
			unsigned int i = 0;
			do {
				double tmp = z_r;
				z_r = z_r * z_r - z_i * z_i + mlx->datas->c_r;
				z_i = 2 * z_i * tmp + mlx->datas->c_i;
				++i;
			}while (z_r * z_r + z_i * z_i < 4 && i < mlx->iter_max);
			if (i != mlx->iter_max)
				init_color(mlx, i, x, y);
		}
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
