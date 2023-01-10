/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:55:57 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/01/10 17:18:44 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_signal(int n, int pid)
{
	if (n == 1)
		kill(pid, SIGUSR2);
	else if (n == 0)
		kill(pid, SIGUSR1);
	usleep(50);
}

int	main(int ac, char **av)
{
	int		i;
	int		num;
	int		rem;
	int		pid;
	char	*str;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		str = av[2];
		i = -1;
		while (str[++i])
		{
			num = 128;
			rem = (unsigned char)(str)[i];
			ft_send(num, rem, pid);
		}
		return (0);
	}
}

void	ft_send(int num, int rem, int pid)
{
	while (num > 0)
	{
		send_signal(rem / num, pid);
		if (rem >= num)
			rem = rem - num;
		num /= 2;
	}
}

int	ft_atoi(char *s)
{
	long	r;
	int		sign;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	if (*s == '-')
		sign = -1;
	else
		sign = 1;
	if (*s == '-' || *s == '+')
		s++;
	r = 0;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return ((int)r * sign);
}
