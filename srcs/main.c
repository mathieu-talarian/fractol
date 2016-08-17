/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:54:17 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/17 16:36:23 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fractol.h"

void	zoom_more(t_mlx *mlx)
{
	mlx->zoom++;
	mlx->iter_max++;
	mlx_destroy_image(mlx->mlx, mlx->img);
	do_mandelbrot2(mlx);
}

int		key_hook(int keycode, void *params)
{
	if (keycode == 53)
		exit (0);
	printf("%d\n", keycode);
	if (keycode == 69)
		zoom_more((t_mlx *)params);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 1)
	{
		printf("argument????");
		return (0);
	}
	t_mlx	*mlx;
	mlx = initialize_mlx();
	do_mandelbrot2(mlx);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_loop(mlx->mlx);
}
