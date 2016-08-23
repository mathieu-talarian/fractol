/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:30:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:05:50 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		no_file(void)
{
	ft_putstr("Usage : ./fractol <fractale>\n\t-Mandelbrot");
	ft_putendl("(2 - 3 - 4)\n\t-Julia\n\t-Boat");
	return (0);
}

int		check_fractale(char *name)
{
	t_fract *tab;

	tab = tab_fractales();
	while (tab->next)
	{
		if (ft_strcmp(name, tab->name) == 0)
			do_it(tab->funct);
		tab = tab->next;
	}
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (!check_fractale(av[1]))
		return (no_file());
	}
	if (ac == 1)
		return (no_file());
	if (ac == 3)
		fractol_fork(av);
	return (0);
}
