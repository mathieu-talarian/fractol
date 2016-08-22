#include "fractol.h"

void	draw_rect(int x1, int x2, int y1, int y2, t_rgb rgb, t_mlx *mlx)
{
	int x = x2;
	int y = y2;
	printf("x = %d <=> x2 = %d\n", x, x2);
	if (y < y1 && x < x1)
	{
	while (y < y1)
	{
		x = x2;
		while (x < x1)
		{
			rgb.r = 255;
			rgb.g = 255;
			rgb.b = 255;
			put_color_to_pixel(mlx, x, y, rgb);
			x++;
		}
		y++;
	}
	}
}



void	draw(int n, float x1, float y1, float x2, float y2, t_mlx *mlx)
{
	t_rgb rgb;
	draw_rect(((2 * x1 + x2) / 3.0), ((2 * y1 + y2) / 3.0), \
	((x1 + 2 * x2) / 3.0) - 1, ((y1 + 2 * y2) / 3.0) - 1, rgb, mlx);
	if(n < 6)
	{
//		draw(n + 1, x1, y1, (2 * x1 + x2) / 3.0, (2 * y1 + y2) / 3.0, mlx);
		//draw(n + 1, (2 * x1 + x2) / 3.0, y1, (x1 + 2 * x2) / 3.0, (2 * y1 + y2) / 3.0, mlx);
		//draw(n + 1, (x1 + 2 * x2) / 3.0, y1, x2, (2 * y1 + y2) / 3.0, mlx);
		//draw(n + 1,  x1, (2 * y1 + y2) / 3.0, (2 * x1 + x2) / 3.0, (y1 + 2 * y2) / 3.0, mlx);
		draw(n + 1, (x1 + 2 * x2) / 3.0, (2 * y1 + y2) / 3.0, x2, (y1 + 2 * y2) / 3.0, mlx);
		//draw(n + 1, x1, (y1 + 2 * y2) / 3.0, (2 * x1 + x2) / 3.0, y2, mlx);
		//draw(n + 1, (2 * x1 + x2) / 3.0, (y1 + 2 * y2) / 3.0, (x1 + 2 * x2) / 3.0,  y2, mlx);
		//draw(n + 1, (x1 + 2 * x2) / 3.0, (y1 + 2 * y2) / 3.0, x2, y2, mlx);
	}
}


void	sierpinski_init(t_mlx *mlx)
{
	int width = RESO_X;
	int	height = RESO_Y;
	mlx->img = mlx_new_image(mlx->mlx, RESO_X, RESO_Y);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	

	draw(1, 0, 0, width - 1, height - 1, mlx);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
}
