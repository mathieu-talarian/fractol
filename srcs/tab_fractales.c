/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_fractales.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/23 12:41:52 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/23 16:05:53 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_fract		*fract_lstnew(char *name, void (*funct)(void *))
{
	t_fract *new;
	if (!(new = (t_fract *)malloc(sizeof(*new))))
		return (NULL);
	else
	{
		if (!(name) || !(funct))
		{
			new->name = NULL;
			new->funct = NULL;
		}
		else
		{
			new->name = ft_strdup(name);
			new->funct = funct;
		}
		new->next = NULL;
	}
	return (new);
}

void		lst_add(t_fract **alst, t_fract *new)
{
	if (new)
	{
		new->next = *alst;
		*alst = new;
	}
}

t_fract		*tab_fractales(void)
{
	t_fract *tab;

	lst_add(&tab, fract_lstnew("Mandelbrot2", &do_mandelbrot2));
	lst_add(&tab, fract_lstnew("Mandelbrot3", &do_mandelbrot3));
	lst_add(&tab, fract_lstnew("Mandelbrot4", &do_mandelbrot4));
	lst_add(&tab, fract_lstnew("Julia", do_julia));
	lst_add(&tab, fract_lstnew("Boat", &do_boat));
	return(tab);
}
