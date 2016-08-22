/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/10 10:54:17 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:58:04 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "fractol.h"

void	zoom_more(t_mlx *mlx)
{
	mlx->zoom++;
//	mlx->iter_max++;
	mlx_destroy_image(mlx->mlx, mlx->img);
	do_mandelbrot2(mlx, mlx->datas);
//	do_julia(mlx, mlx->datas);
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

void	zoom_on(t_pts pts, t_mlx *mlx)
{
	mlx->zoom *= 1.1;
	printf("ZOOOM\nnew zoom = %f\n", mlx->zoom);
	mlx->iter_max += 6;
	new_datas(mlx, &mlx->datas, pts);
	mlx_destroy_image(mlx->mlx, mlx->img);
//	do_mandelbrot2(mlx, mlx->datas);
	do_julia(mlx, mlx->datas);
}

void	modify_coords(t_pts pts, t_mlx *mlx, double *xm, double *ym)
{
	*xm = (DX1 / ((DX2 - DX1) * mlx->zoom / RESO_X)) + \
		  pts.window_x / mlx->zoom;
	*ym = (DY1 / ((DY2 - DY1) * mlx->zoom / RESO_Y)) + \
		  pts.window_y / mlx->zoom;
}

int		mouse_hook(int mousecode, int x, int y, void *params)
{
	t_pts pts;

	pts.window_x = x;
	pts.window_y = y;
	modify_coords(pts, (t_mlx *)params, \
			&pts.map_x, &pts.map_y);
	if (mousecode == 5)
		zoom_on(pts, (t_mlx *)params);
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
//	do_mandelbrot2(mlx, mlx->datas);
	do_julia(mlx, mlx->datas);
	mlx_key_hook(mlx->win, key_hook, mlx);
	mlx_mouse_hook(mlx->win, mouse_hook, mlx);
	mlx_loop(mlx->mlx);
}
