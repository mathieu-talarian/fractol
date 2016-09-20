/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:43:05 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/20 15:22:20 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_on(t_pts pts, t_mlx *mlx)
{
	int test;

	mlx->zoom *= 1.1;
	test = (((mlx->zoom / 200) / 1.1));
	test = test % 6;
	if (test == 0)
		mlx->iter_max += 6;
	new_datas(mlx, &mlx->datas, pts);
	try_to_redraw(mlx);
}

void	zoom_off(t_pts pts, t_mlx *mlx)
{
	int test;

	if (mlx->iter_max - 6 > 0)
	{
		test = (((mlx->zoom / 200) / 1.1));
		test = test % 6;
		if (test == 0)
			mlx->iter_max -= 6;
		mlx->zoom /= 1.1;
	}
	new_datas(mlx, &mlx->datas, pts);
	try_to_redraw(mlx);
}
