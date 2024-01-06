#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[]) {

	if (argc != 1) {
		printf("Usage: %s\n", argv[0]);
		return 1;
	}
	while (*envp) 
	{
		printf("%s******\n", *envp);
		envp++;
	}

	printf("msh42> \n");
	
	return 0;
}
