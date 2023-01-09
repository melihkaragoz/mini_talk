/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:56:04 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/01/09 19:16:51 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	bitoa();

void	handle(int signum)
{
	if (signum == SIGUSR2)
		printf("%d\n", 1);
	else if (signum == SIGUSR1)
		printf("%d\n", 0);
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
