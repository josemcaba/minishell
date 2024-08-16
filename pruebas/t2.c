#include <unistd.h>

# La función EXECVE toma el control total del programa y cuando finaliza la función
# también finaliza el programa. Por eso no se ejecuta el bucle infinito.
#
# Al menos eso es lo que he entendido del video en frances de la intra 42

int	main(int ac, char **av)
{
	while (42)
		execve("/bin/ls", av, NULL);
}
