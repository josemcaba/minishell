#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<sys/wait.h>


/* Ejecuta "ls -lF | cat -e"  */

void	run_pipe(void)
{
	int const	READ_END	= 0;
	int const	WRITE_END	= 1;
	pid_t		child		= -1;
	char		*cmd1		= NULL;
	char		*cmd2		= NULL;
	char		*args1[3];
	char		*args2[3];
	int			pdes[2];

	cmd1 = "/bin/ls";
	args1[0] = cmd1;
	args1[1] = "-lF";
	args1[2] = NULL;

	cmd2 = "/bin/cat";
	args2[0] = cmd2;
	args2[1] = "-e";
	args2[2] = NULL;

	pipe(pdes);

	child = fork();
	switch ((int)child)
	{
	case -1:
		close(pdes[READ_END]);
		close(pdes[WRITE_END]);
		perror("error -11");
		break;

	case 0:
		/* child */
		dup2(pdes[WRITE_END], STDIN_FILENO);
		close(pdes[READ_END]);
		execve(cmd1, args1, NULL);
		perror("error 00");
		break;
	}	

	/* parent */
	dup2(pdes[READ_END], STDIN_FILENO);
	close(pdes[WRITE_END]);
	wait(NULL);
	execve(cmd2, args2, NULL);
	return;	
}

int	main(void)
{
	pid_t	child = -1;

	child = fork();
	switch ((int)child)
	{
	case -1:
		perror("error -1");
		break;

	case 0:
		/* child */
		run_pipe();
		perror("error 0");
		break;
	}
	/* parent */
	wait(NULL);

	return 0;
}