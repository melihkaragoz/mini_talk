#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void	handle(int signum)
{
	if(signum == SIGUSR2)
		printf("%d\n",1);
	else if(signum == SIGUSR1)
		printf("%d\n",0);
}

int main(void)
{
	printf("pid : %d\n", getpid());
	signal(SIGUSR1, &handle);
	signal(SIGUSR2, &handle);
	while (1)
	{
		;
	}

	return (0);
}
