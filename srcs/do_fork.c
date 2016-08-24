/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_fork.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmoullec <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/24 12:50:25 by mmoullec          #+#    #+#             */
/*   Updated: 2016/08/24 12:51:23 by mmoullec         ###   ########.fr       */
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

void	do_fork(int pid, char *name, int (*f)(char *))
{
	ft_putnbr_fd(pid, 3);
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
		exit(1);
	}
	return (1);
}
