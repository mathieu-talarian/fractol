/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_mlx.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:14:07 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/18 21:58:07 by mmoullec         ###   ########.fr       */
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
	mlx->iter_max = 50;
	return (mlx);
}

t_datas		*init_datas(t_mlx *mlx)
{
	t_datas *datas;
	datas = (t_datas *)malloc(sizeof(t_datas));
	datas->xold = X1;
	datas->yold = Y1;
	datas-> x1 = X1 / ((X2 - X1) * mlx->zoom / RESO_X);
	datas-> x2 = X2;
	datas-> y1 = Y1 / ((Y2 - Y1) * mlx->zoom / RESO_Y);
	datas-> y2 = Y2;
	printf("===>datas\n[x1 = %f| y1 = %f]\n", datas->x1, datas->y1);
	return (datas);
}

void		new_datas(t_mlx *mlx, t_datas **ll, double xm, double ym)
{
	t_datas *datas;
	datas = *ll;
	datas->xold = datas->x1;
	datas->yold = datas->y1;
	datas->x1 = (datas->xold + xm); // ((X2 - datas->xold) * mlx->zoom / RESO_X);
	datas->y1 = (datas->yold + ym); // ((Y2 - datas->yold) * mlx->zoom / RESO_Y);
	printf("===>datas\n[x1 = %f| y1 = %f]\n", datas->x1, datas->y1);
}
