/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:04:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 17:28:35 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <libft.h>
# include <fcntl.h>
# include <math.h>
# include <mlx.h>
# include </System/Library/Frameworks/Tk.framework/Versions/8.5/Headers/X11/X.h>
# include <errno.h>
# include <sys/types.h>
# define AD mlx->d_addr
# define RESO_X 540
# define RESO_Y 480
# define X1 -0.6
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
# define ABS(x) ((x) < 0 ? (x * - 1) : (x))

typedef void		(*t_funct)(void *);

typedef struct		s_pts
{
	double			window_x;
	double			window_y;
	double			map_x;
	double			map_y;
}					t_pts;

typedef struct		s_datas
{
	double		c_r;
	double		c_i;
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
	void			*funct;
	int				bpp;
	int				sizeline;
	int				endian;
	double			zoom;
	unsigned int	iter_max;
	int				tt;
	int				color_style;
}					t_mlx;

typedef struct		s_rgb
{
	unsigned int	r;
	unsigned int	g;
	unsigned int	b;
}					t_rgb;

typedef struct		s_fract
{
	char			*name;
	t_funct			funct;
	struct s_fract	*next;
}					t_fract;

typedef struct		s_iter
{
	unsigned int	image_x;
	unsigned int	image_y;
	unsigned int	x;
	unsigned int	y;
	double			z_r;
	double			z_i;
	double			c_i;
	double			c_r;
	unsigned int	i;
	double			tmp;
}					t_iter;

typedef struct		s_col
{
	int				a;
	int				b;
}					t_col;

t_mlx				*initialize_mlx(void);

int					main(int ac, char **av);
t_fract				*tab_fractales(void);
void				do_it(void (*funct)(void *));

/*
** figures
*/
void				prepa_draw(void *params);
void				do_mandelbrot2(void *params);
void				do_mandelbrot3(void *params);
void				do_mandelbrot4(void *params);
void				do_julia(void *params);
void				do_boat(void *params);

t_datas				*init_datas(t_mlx *mlx);

/*
** color
*/

void				color(t_mlx *mlx, t_iter iter, t_rgb *rgb);
void				init_color(t_mlx *mlx, t_iter iter);
void				put_color_to_pixel1(t_mlx *mlx, int x, int y, t_rgb rgb);
void				put_color_to_pixel2(t_mlx *mlx, int x, int y, t_rgb rgb);
void				put_color_to_pixel3(t_mlx *mlx, int x, int y, t_rgb rgb);
void				put_color_to_pixel4(t_mlx *mlx, int x, int y, t_rgb rgb);
void				make_colors(t_col col, unsigned int *r, unsigned int *g,\
		unsigned int *b);
unsigned int		mod_color(int i, int iter_max);
void				make_colors2(int color_style, t_rgb *rgb, t_iter \
		iter, int iter_max);
void				col(unsigned int *color, t_iter iter, int iter_max);

/*
**maths
*/
double				carre(double x);
double				cube(double x);
double				p_4(double x);

/*
**hooks
*/
void				rd(t_mlx *mlx, int a);
int					key_press(int mousecode, int x, int y, void *params);
int					key_release(int mousecode, int x, int y, void *params);
void				motion(int x, int y, t_mlx *mlx);
int					motion_mouse(int x, int y, void *params);
int					movement_hook(int keycode, void *params);
int					key_hook(int keycode, void *params);

void				zoom_on(t_pts pts, t_mlx *mlx);
void				zoom_off(t_pts pts, t_mlx *mlx);
void				redraw_key_position(t_mlx *mlx, int keycode);

int					mouse_hook(int mousecode, int x, int y, void *params);

/*
**calculs coords zoom
*/
void				modify_coords(t_pts pts, t_mlx *mlx, double *xm, \
		double *ym);
void				new_datas(t_mlx *mlx, t_datas **ll, t_pts pts);

void				try_to_redraw(t_mlx *mlx);
void				draw(t_mlx *mlx, void (*funct)(void *));

/*
**fork
*/
int					fractol_fork(char **av, t_fract **tab);
int					check_fractale(t_fract **tab, char *name);

int					no_file();
int					usage(char *name);

#endif
