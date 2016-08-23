/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:39:27 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:39:02 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_hook(int keycode, void *params)
{
	t_mlx *mlx;

	mlx = params;
	printf("%d\n", keycode);
	if ((keycode >= 83 && keycode <= 88) || keycode == 6)
	{
		mlx->color_style = keycode;
		try_to_redraw(mlx, mlx->funct);
	}
	if (keycode == 53)
		exit (0);
	return (0);
}

