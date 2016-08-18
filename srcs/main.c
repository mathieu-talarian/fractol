/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:54:17 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/18 21:58:06 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


# include "fractol.h"

void	zoom_more(t_mlx *mlx)
{
	mlx->zoom++;
//	mlx->iter_max++;
	mlx_destroy_image(mlx->mlx, mlx->img);
	do_mandelbrot2(mlx, mlx->datas);
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

void	zoom_on(double xm, double ym, t_mlx *mlx)
{
	mlx->zoom += 10;
//	mlx->iter_max++;
	new_datas(mlx, &mlx->datas, xm, ym);
	mlx_destroy_image(mlx->mlx, mlx->img);
	do_mandelbrot2(mlx, mlx->datas);
}

void	modify_coords(int x, int y, t_mlx *mlx, double*xm, double *ym)
{
	/*
	*xm = (XO / ((X2 - XO) * mlx->zoom / RESO_X)) + x / mlx->zoom;
	*ym = (YO / ((Y2 - YO) * mlx->zoom / RESO_Y)) + y / mlx->zoom;
	printf("before\vxm = %f | ym = %f\n", *xm, *ym);
	*/
	*xm = ((*xm - XO) / (X2 - XO) - 0.5) * (RESO_X / (mlx->zoom * (X2 - XO)));
	*ym = ((*ym - YO) / (Y2 - YO) - 0.5) * (RESO_Y / (mlx->zoom * (Y2 - YO)));
	printf("after\vxm = %f | ym = %f\n", *xm, *ym);

}

int		mouse_hook(int mousecode, int x, int y, void *params)
{
	double xm;
	double ym;

	printf("==>keycode = %d | x = %d | y = %d<==\n", mousecode, x, y);
	modify_coords(x, y, (t_mlx *)params, &xm, &ym);
	if (mousecode == 5)
		zoom_on(xm, ym, (t_mlx *)params);
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
	t_datas *datas;
	mlx = initialize_mlx();
	mlx->datas = init_datas(mlx);
	do_mandelbrot2(mlx, mlx->datas);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
}
