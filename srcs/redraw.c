/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 17:46:39 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 13:13:38 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_mlx *mlx, void (*funct)(void *))
{
	funct(mlx);
}

void		try_to_redraw(t_mlx *mlx)
{
	mlx_destroy_image(mlx->mlx, mlx->img);
	prepa_draw(mlx);
}

void		rd(t_mlx *mlx, int a)
{
	if (a == 1)
		mlx->tt = 1;
	else if (a == 0)
		mlx->tt = 0;
	try_to_redraw(mlx);
}
