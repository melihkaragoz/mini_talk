/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:56:04 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/01/10 13:10:15 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	bitoa();

void	handle(int signum)
{
	static int	i = 128;
	static char	c = 0;

	if (signum == SIGUSR2)
		c += i;
	i /= 2;
	if (i == 0)
	{
		write(1,&c,1);
		i = 128;
		c = 0;
	}
}

int	*prepare(int sig)
{
	return (0);
}

int	main(void)
{
	printf("pid : %d\n", getpid());
	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	while (1)
	{
		continue ;
	}
	return (0);
}
