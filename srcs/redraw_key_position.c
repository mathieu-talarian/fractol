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
