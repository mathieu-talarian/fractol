/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:46:06 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:30:18 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	modify_coords(t_pts pts, t_mlx *mlx, double *xm, double *ym)
{
	*xm = (DX1 / ((DX2 - DX1) * mlx->zoom / RESO_X)) + \
		  pts.window_x / mlx->zoom;
	*ym = (DY1 / ((DY2 - DY1) * mlx->zoom / RESO_Y)) + \
		  pts.window_y / mlx->zoom;
}
