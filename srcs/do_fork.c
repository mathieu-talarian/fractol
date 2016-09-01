/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:50:25 by mmoullec          #+#    #+#             */
/*   Updated: 2016/09/01 18:16:19 by mmoullec         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

pid_t	create_process(void)
{
	pid_t pid;

	pid = fork();
	while ((pid == -1) && (errno == EAGAIN))
		pid = fork();
	return (pid);
}

int		usage(char *name)
{
	ft_putstr("Le nom : ");
	ft_putstr(name);
	ft_putendl(" ne fonctionne pas");
	no_file();
	return (0);
}

void	do_fork(int pid, char *name, int (*f)(t_fract **, char *), t_fract **tab)
{
	ft_putnbr_fd(pid, 3);
	if (!f(tab, name))
		usage(name);
	exit(0);
}

int		fractol_fork(char **av, t_fract **tab)
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
		do_fork(0, av[2], check_fractale, tab);
		exit(0);
	}
	else
	{
		do_fork(pid, av[1], check_fractale, tab);
		exit(1);
	}
	return (1);
}
