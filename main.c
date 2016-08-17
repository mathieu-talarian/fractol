#include <libft.h>
#include <mlx.h>
#ifndef FR_H
# define X1 -1
# define X2 1
# define Y1 -1.2
# define Y2 1.2
# define I_MAX 150
# define IMAGE_X 1000
# define IMAGE_Y 800
#endif 

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*win2;
	void			*img;
	void			*img2;
	char			*d_addr;
	int				bpp;
	int				sizeline;
	int				endian;
	unsigned int	color;
}					t_mlx;

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

void		put_color_to_pixel(t_mlx *mlx, int x, int y, t_rgb rgb)
{
	unsigned int j;
	j = (x * 4) + (y * mlx->sizeline);
	mlx->d_addr[j] = mlx_get_color_value(mlx->mlx, rgb.r);
	mlx->d_addr[++j] = mlx_get_color_value(mlx->mlx, rgb.g);
	mlx->d_addr[++j] = mlx_get_color_value(mlx->mlx, rgb.b);
}

void		do_fract(t_mlx *mlx, int x, int y)
{
	t_rgb rgb;
	double zoom_x = IMAGE_X/(X2 - X1);
	double zoom_y = IMAGE_Y/(Y2 - Y1);
	double c_r = x / zoom_x + X1;
	double c_i = y / zoom_y + Y1;
	double z_r = 0;
	double z_i = 0;
	double tmp;
	int i = 0;
	rgb.r = 0;
	rgb.g = 0;
	rgb.b = 0;

	while ((z_r * z_r + z_i * z_i) < 4 && i < 50)
	{
		tmp = z_r;
		z_r = z_r * z_r - z_i * z_i + c_r;
		z_i = 2 * z_i * tmp + c_i;
		i++;
	}
	if (i == 50)
	{
		put_color_to_pixel(mlx, x, y, rgb);
	}
	else
	{
		if (i < 50 && 40 <= i)
		{
			rgb.r = i * 255 / 50;
		}
		else if (i < 40 && 25 < i)
		{
			rgb.b = i * 255 / 50;
		}
		else 
			rgb.g = i * 255 / 50;
		put_color_to_pixel(mlx, x, y, rgb);
	}
}

void	fractol(t_mlx *mlx)
{
	int x = 0;
	int y = 0;
	while (y < IMAGE_Y)
	{
		x = 0;
		while (x < IMAGE_X)
		{
			do_fract(mlx, x, y);
			x++;
		}
		y++;
	}
}

int main(void)
{
	t_mlx *mlx;
	t_mlx *mlx2;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx2 = (t_mlx *)malloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, 1000, 800, "fractol");
	mlx->img = mlx_new_image(mlx->mlx, 1000, 800);
	mlx->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	mlx2->win = mlx_new_window(mlx->mlx, 1000, 800, "julia");
	mlx2->img = mlx_new_image(mlx->mlx, 1000, 800);
	mlx2->d_addr = mlx_get_data_addr(mlx->img, &mlx->bpp, &mlx->sizeline, &mlx->endian);
	fractol(mlx);
	julia(mlx2);
	mlx_put_image_to_window(mlx->mlx, mlx->win, mlx->img, 0, 0);
	mlx_put_image_to_window(mlx->mlx, mlx2->win, mlx2->img, 0, 0);
	mlx_loop(mlx->mlx);
	return (0);
}
