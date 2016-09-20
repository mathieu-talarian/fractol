/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:30:18 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/20 15:20:02 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		no_file(void)
{
	ft_putstr("Usage : ./fractol <fractale> <fractale>\n\t-Mandelbrot");
	ft_putendl("(2 - 3 - 4)\n\t-Julia\n\t-Boat");
	return (0);
}

int		check_fractale(t_fract **ll, char *name)
{
	t_fract *tab;

	tab = *ll;
	while (tab)
	{
		if (ft_strcmp(name, tab->name) == 0)
			do_it(tab->funct);
		tab = tab->next;
	}
	return (0);
}

int		check_multi(t_fract **ll, char **av)
{
	t_fract	*tab;
	int		i;

	tab = *ll;
	i = 1;
	while (av[i])
	{
		if (ft_strcmp(av[i], tab->name))
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	t_fract *tab;

	tab = tab_fractales();
	if (ac == 2)
	{
		if (!check_fractale(&tab, av[1]))
			return (usage(av[1]) && no_file());
	}
	if (ac == 1 || ac > 3)
		return (no_file());
	if (ac == 3)
		fractol_fork(av, &tab);
	return (0);
}
