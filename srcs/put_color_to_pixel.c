/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:00:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 17:41:59 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_color_to_pixel1(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;

	j = (x * 4) + (y * mlx->sizeline);
	AD[j] = mlx_get_color_value(mlx->mlx, rgb.b);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.g);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.r);
}

void		put_color_to_pixel2(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;

	j = (x * 4) + (y * mlx->sizeline);
	AD[j] = mlx_get_color_value(mlx->mlx, rgb.g);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.b);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.r);
}

void		put_color_to_pixel3(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;

	j = (x * 4) + (y * mlx->sizeline);
	AD[j] = mlx_get_color_value(mlx->mlx, rgb.r);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.g);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.b);
}

void		put_color_to_pixel4(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;

	j = (x * 4) + (y * mlx->sizeline);
	AD[j] = mlx_get_color_value(mlx->mlx, rgb.b);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.r);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.g);
}
