#include <unistd.h>

int	main(int ac, char **av)
{
	execve("/bin/ls", av, NULL);
}