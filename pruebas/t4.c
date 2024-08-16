#include <unistd.h>
#include <stdio.h>

int	main(int ac, char **av)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		sleep(30);
		printf("I AM YOUR FATHER\n");
	}
	if (father == 0)
	{
		sleep(60);
		execve("/bin/ls", av, NULL);
	}
}
