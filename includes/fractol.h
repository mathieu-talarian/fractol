/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 14:04:41 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/17 16:36:05 by mmoullec         ###   ########.fr       */
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
# define RESO_X 1080
# define RESO_Y 960
# define X1 -2.1
# define X2 0.6
# define Y1 -1.2
# define Y2 1.2

typedef struct		s_mlx
{
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
void				do_mandelbrot(t_mlx *mlx);
void				do_mandelbrot2(t_mlx *mlx);

void				put_color_to_pixel(t_mlx *mlx, int x, int y, t_rgb rgb);

#endif
