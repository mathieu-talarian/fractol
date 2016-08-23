/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_it.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 13:08:00 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 19:14:07 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	do_it(void (*funct)(void *))
{
	t_mlx	*mlx;
	t_datas *datas;

	mlx = initialize_mlx();
	mlx->datas = init_datas(mlx);
	mlx->funct = funct;
	prepa_draw((t_mlx *)mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_hook(mlx->win, 4, 1L << 2, key_press, mlx);
	mlx_hook(mlx->win, 5, 1L << 3, key_release, mlx);
	mlx_hook(mlx->win, 6, (1L << 6), motion_mouse, mlx);
	mlx_loop(mlx->mlx);
}
