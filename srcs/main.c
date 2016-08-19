/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:54:17 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/19 15:34:27 by mmoullec         ###   ########.fr       */
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
	mlx->zoom *= 1.1;
	printf("ZOOOM\nnew zoom = %f\n", mlx->zoom);
	mlx->iter_max += 6;
	new_datas(mlx, &mlx->datas, xm, ym);
	mlx_destroy_image(mlx->mlx, mlx->img);
	do_mandelbrot2(mlx, mlx->datas);
}

void	modify_coords(int x, int y, t_mlx *mlx, double*xm, double *ym)
{
	*xm = (DX1 / ((DX2 - DX1) * mlx->zoom / RESO_X)) + x / mlx->zoom;
	*ym = (DY1 / ((DY2 - DY1) * mlx->zoom / RESO_Y)) + y / mlx->zoom;
	printf("before\vxm = %f | ym = %f\n", *xm, *ym);
//	*xm = ((*xm - DX1) / (DX2 - DX1) - 0.5) * (RESO_X / (mlx->zoom * (DX2 - DX1)));
//	*ym = ((*ym - DY1) / (DY2 - DY1) - 0.5) * (RESO_Y / (mlx->zoom * (DY2 - DY1)));
//	*xm = *xm * 2;
//	*ym = *ym * 2;
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
