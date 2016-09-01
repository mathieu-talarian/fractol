/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redraw_key_position.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:45:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 12:39:00 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	redraw_key_position(t_mlx *mlx, int keycode)
{
	if (keycode == 124)
		mlx->datas->x1 -= 0.01;
	else if (keycode == 123)
		mlx->datas->x1 += 0.01;
	else if (keycode == 126)
		mlx->datas->y1 += 0.01;
	else if (keycode == 125)
		mlx->datas->y1 -= 0.01;
	try_to_redraw(mlx);
}
