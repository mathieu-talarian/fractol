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
#include <errno.h>
#include <sys/types.h>

int		no_file(void)
{
	ft_putstr("Usage : ./fractol <fractale>\n\t-Mandelbrot");
	ft_putendl("(2 - 3 - 4)\n\t-Julia\n\t-Boat");
	return (0);
}

pid_t create_process(void)
{
pid_t pid;
	do {
		pid = fork();
	} while ((pid == -1) && (errno == EAGAIN));
	return pid;
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

void	do_fork(int pid, char *name, int (*f)(char *))
{
	printf("%d\n", pid);
	f(name);
}

int		fractol_fork(char **av)
{
	pid_t pid;

	pid = create_process();
	if (pid == -1)
	{
		perror("fork");
		exit(0);
	}
	else if (pid == 0)
	{
		do_fork(0, av[2], check_fractale);
		exit(0);
	}
	else
	{
		do_fork(pid, av[1], check_fractale);
		exit (1);
	}
	return (1);
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
