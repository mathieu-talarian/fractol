/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 17:46:39 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/12 18:12:45 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		draw(t_mlx *mlx, void (*funct)(void *))
{
	funct(mlx);
}

int			to_re(t_mlx *mlx)
{
	draw(mlx, mlx->funct);
	mlx_string_put(mlx->mlx, mlx->win, 0, 0, 16777215, \
	"changement de couleurs : pave numerique");
	mlx_string_put(mlx->mlx, mlx->win, 0, 20, 16777215, \
	"page_up <=> page_down");
	return (0);
}

void		try_to_redraw(t_mlx *mlx)
{
	int		x;
	int		y;
	t_rgb	rgb;

	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;
	y = -1;
	x = -1;
	while (++y < RESO_Y)
	{
		x = -1;
		while (++x < RESO_X)
			put_color_to_pixel1(mlx, x, y, rgb);
	}
}

void		rd(t_mlx *mlx, int a)
{
	if (a == 1)
		mlx->tt = 1;
	else if (a == 0)
		mlx->tt = 0;
	try_to_redraw(mlx);
}
