/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/22 17:31:08 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 19:14:59 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	calculs_julia(t_mlx *mlx, t_iter iter)
{
	iter.z_r = iter.x / mlx->zoom + mlx->datas->x1;
	iter.z_i = iter.y / mlx->zoom + mlx->datas->y1;
	iter.i = 0;
	while (carre(iter.z_r) + carre(iter.z_i) < 4 && iter.i < mlx->iter_max)
	{
		iter.tmp = iter.z_r;
		iter.z_r = carre(iter.z_r) - carre(iter.z_i) + mlx->datas->c_r;
		iter.z_i = 2 * iter.z_i * iter.tmp + mlx->datas->c_i;
		++iter.i;
	}
	if (iter.i != mlx->iter_max)
		init_color(mlx, iter);
}

void	do_julia(void *params)
{
	t_mlx	*mlx;
	t_iter	iter;

	mlx = params;
	iter.image_x = ((mlx->datas->x2 - mlx->datas->x1) * mlx->zoom);
	iter.image_y = ((mlx->datas->y2 - mlx->datas->y1) * mlx->zoom);
	iter.x = 0;
	iter.y = 0;
	while (iter.x < iter.image_x && iter.x < RESO_X)
	{
		iter.y = 0;
		while (iter.y < iter.image_y && iter.y < RESO_Y)
		{
			calculs_julia(mlx, iter);
			iter.y++;
		}
		iter.x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
