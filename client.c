#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int ft_atoi(char *s);

void	sendSignal(int n, int pid)
{
	if (n == 1)
	{
		kill(pid, SIGUSR2);
		printf("1 gitti\n");
	}
	else if(n == 0)
	{
		kill(pid, SIGUSR1);
		printf("0 gitti\n");
	}
	else
	{
		printf("sıkıntı");
	}
	usleep(10);
}

int	main(int ac, char **av)
{
	if (ac == 3)
	{
		int i;
		int num;
		int rem;
		int pid = ft_atoi(av[1]);
		char *str = av[2];
		printf("server pid: %d\n", pid);

		while (str[i])
		{
			num = 128;
			rem = (unsigned char)(str)[i];
			while (num > 0)
			{
				sendSignal(rem / num, pid);
				if (rem >= num)
					rem = rem - num;
				num /= 2;
			}
			write(1,"\n",1);
			i++;
		}

		return (0);
	}
}

int ft_atoi(char *s)
{
	long r;
	int sign;

	while (*s == 32 || (*s >= 9 && *s <= 13))
		s++;
	sign = (*s == '-') ? -1 : 1;
	(*s == '-' || *s == '+') ? s++ : s;
	r = 0;
	while (*s >= '0' && *s <= '9')
		r = r * 10 + *s++ - '0';
	return ((int)r * sign);
}
