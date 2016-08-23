/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 14:44:54 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:29:25 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		mouse_hook(int mousecode, int x, int y, void *params)
{
	t_pts pts;

	pts.window_x = x;
	pts.window_y = y;
	modify_coords(pts, (t_mlx *)params, \
			&pts.map_x, &pts.map_y);
	if (mousecode == 5)
		zoom_on(pts, (t_mlx *)params);
	else if (mousecode == 4)
		zoom_off(pts, (t_mlx *)params);
	return (0);
}
