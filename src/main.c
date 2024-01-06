#include <stdio.h>
#include <stdlib.h>
#include "../libft/libft.h"

int main(int argc, char *argv[], char *envp[]) {

	if (argc != 1) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}
	while (*envp) 
	{
		if (ft_strncmp(*envp, "PWD=", 4) == 0)
			printf("%s\n", &(*envp)[4]);
		envp++;
	}

	printf("msh42> \n");
	
	return 0;
}
