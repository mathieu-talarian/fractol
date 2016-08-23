/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_hook.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:43:05 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:30:14 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	zoom_on(t_pts pts, t_mlx *mlx)
{
	mlx->zoom *= 1.1;
	mlx->iter_max += 6;
	new_datas(mlx, &mlx->datas, pts);
	try_to_redraw(mlx);
}

void	zoom_off(t_pts pts, t_mlx *mlx)
{
	if (mlx->iter_max - 6 > 0)
	{
		mlx->iter_max -= 6;
		mlx->zoom /= 1.1;
	}
	new_datas(mlx, &mlx->datas, pts);
	try_to_redraw(mlx);
}
