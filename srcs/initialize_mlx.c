/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/19 15:53:58 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*initialize_mlx(void)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, RESO_X, RESO_Y, "fractol");
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
	datas-> x1 = X1 / ((X2 - X1) * mlx->zoom / RESO_X);
	datas-> x2 = X2 /  ((X2 - X1) * mlx->zoom / RESO_X);
	datas-> y1 = Y1 / ((Y2 - Y1) * mlx->zoom / RESO_Y);
	datas-> y2 = Y2  / ((Y2 - Y1) * mlx->zoom / RESO_Y);
	printf("===>datas\n[x1 = %f| x2 = %f]\n", datas->x1, datas->x2);
	printf("===>datas\n[y1 = %f| y2 = %f]\n", datas->y1, datas->y2);
	return (datas);
}

void		new_datas(t_mlx *mlx, t_datas **ll, double xm, double ym)
{
	t_datas *datas;
	datas = *ll;
	datas->xold = datas->x1;
	datas->yold = datas->y1;
	datas->x1 = xm + (X1 / ((X2 - X1) * mlx->zoom / RESO_X));
	datas->x2 = xm + (X2 / ((X2 - X1) * mlx->zoom / RESO_X));
	datas->y1 = ym + (Y1 / ((Y2 - Y1) * mlx->zoom / RESO_Y));
	datas->y2 = ym + (Y2  / ((Y2 - Y1) * mlx->zoom / RESO_Y));
	printf("===>datas\n[x1 = %f| x2 = %f]\n", datas->x1, datas->x2);
	printf("===>datas\n[y1 = %f| y2 = %f]\n", datas->y1, datas->y2);
	
}
