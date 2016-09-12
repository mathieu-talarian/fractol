/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_key_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:45:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/12 18:11:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_key_position(t_mlx *mlx, int keycode)
{
	if (keycode == 124)
	{
		mlx->datas->x1 -= 1 / mlx->zoom;
		mlx->datas->x2 -= 1 / mlx->zoom;
	}
	else if (keycode == 123)
	{
		mlx->datas->x1 += 1 / mlx->zoom;
		mlx->datas->x2 += 1 / mlx->zoom;
	}
	else if (keycode == 126)
	{
		mlx->datas->y1 += 1 / mlx->zoom;
		mlx->datas->y2 += 1 / mlx->zoom;
	}
	else if (keycode == 125)
	{
		mlx->datas->y1 -= 1 / mlx->zoom;
		mlx->datas->y2 -= 1 / mlx->zoom;
	}
	try_to_redraw(mlx);
}
