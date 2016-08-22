/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:48:42 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*initialize_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, \
			"fractol");
	mlx->zoom = 100;
	mlx->iter_max = 24;
	return (mlx);
}

t_datas		*init_datas(t_mlx *mlx)
{
	t_datas *datas;

	datas = (t_datas *)malloc(sizeof(t_datas));
	datas->xold = X1;
	datas->yold = Y1;
	datas->zoomold = mlx->zoom;
	datas->c_r = 0.285;
	datas->c_i = 0.01;
	datas-> x1 = X1 / ((X2 - X1) * mlx->zoom / RESO_X);
	datas-> x2 = X2 / ((X2 - X1) * mlx->zoom / RESO_X);
	datas-> y1 = Y1 / ((Y2 - Y1) * mlx->zoom / RESO_Y);
	datas-> y2 = Y2  / ((Y2 - Y1) * mlx->zoom / RESO_Y);
	return (datas);
}

void		new_datas(t_mlx *mlx, t_datas **ll, t_pts pts)
{
	t_datas *datas;
	double	new_width;
	double	new_height;

	datas = *ll;
	new_width = (datas->zoomold / mlx->zoom) * \
				(datas->x2 - datas->x1);
	new_height = (datas->zoomold / mlx->zoom) * \
				 (datas->y2 - datas->y1);
	datas->xold = datas->x1;
	datas->yold = datas->y1;
	datas->zoomold = mlx->zoom;
	datas->x1 = pts.map_x - pts.window_x * \
				(new_width / RESO_X);
	datas->x2 = datas->x1 + new_width;
	datas->y1 = pts.map_y - pts.window_y * \
				(new_height / RESO_Y);
	datas->y2 = datas->y1 + new_height;
}
