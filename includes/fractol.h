/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:04:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/22 17:37:41 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# define AD mlx->d_addr
# define RESO_X 540
# define RESO_Y 460
# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2
# define JX1 -1
# define JX2 1
# define XO mlx->datas->xold
# define YO mlx->datas->yold
# define DX1 mlx->datas->x1
# define DX2 mlx->datas->x2
# define DY1 mlx->datas->y1
# define DY2 mlx->datas->y2

typedef struct		s_pts
{
	double			window_x;
	double			window_y;
	double			map_x;
	double			map_y;
}					t_pts;

typedef struct		s_datas
{
	double		x1;
	double		x2;
	double		y1;
	double		y2;
	double		xold;
	double		yold;
	double		zoomold;
}					t_datas;

typedef struct		s_mlx
{
	t_datas			*datas;
	void			*mlx;
	void			*win;
	void			*img;
	char			*d_addr;
	int				bpp;
	int				sizeline;
	int				endian;
	double			zoom;
	unsigned int	iter_max;
}					t_mlx;

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

t_mlx				*initialize_mlx(void);

int					main(int ac, char **av);

/*
** figures
*/
void				do_mandelbrot(t_mlx *mlx);
void				do_mandelbrot2(t_mlx *mlx, t_datas *datas);
void				do_julia(t_mlx *mlx, t_datas *datas);

t_datas				*init_datas(t_mlx *mlx);
void		new_datas(t_mlx *mlx, t_datas **ll, t_pts pts);
void				put_color_to_pixel(t_mlx *mlx, int x, int y, t_rgb rgb);


/*
** color
*/

void	color(t_mlx *mlx, int i, t_rgb rgb, int x, int y);
#endif
