#include <unistd.h>
#include <stdio.h>

# El proceso PADRE espera "wait()" hasta que el hijo termine. Entonces continúa

int	main(int ac, char **av)
{
	pid_t	father;

	father = fork();
	if (father > 0)
	{
		wait();
		printf("I AM YOUR FATHER\n");
	}
	if (father == 0)
	{
		sleep(60);
		execve("/bin/ls", av, NULL);
	}
}