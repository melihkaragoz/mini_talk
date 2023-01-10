/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkaragoz <mkaragoz@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 18:55:57 by mkaragoz          #+#    #+#             */
/*   Updated: 2023/01/09 19:41:04 by mkaragoz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int		ft_atoi(char *s);
void	ft_send(int num, int rem, int pid);

void	send_signal(int n, int pid)
{
	if (n == 1)
	{
		kill(pid, SIGUSR2);
		printf("1 gitti\n");
	}
	else if (n == 0)
	{
		kill(pid, SIGUSR1);
		printf("0 gitti\n");
	}
	else
		printf("sıkıntı");
	usleep(10);
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
		printf("server pid: %d\n", pid);
		while (str[++i])
		{
			num = 128;
			rem = (unsigned char)(str)[i];
			ft_send(num, rem, pid);
			write(1, "\n", 1);
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
