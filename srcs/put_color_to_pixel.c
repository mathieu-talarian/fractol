/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_color_to_pixel.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 15:00:42 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/09 17:26:34 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		put_color_to_pixel(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;

	j = (x * 4) + (y * mlx->sizeline);
	AD[j] = mlx_get_color_value(mlx->mlx, rgb.r);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.g);
	AD[++j] = mlx_get_color_value(mlx->mlx, rgb.b);
}
