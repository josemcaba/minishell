#include	<unistd.h>
#include	<string.h>
#include	<stdio.h>
#include	<fcntl.h>
#include	<sys/wait.h>


/* Ejecuta   */

void	main(void)
{
	int			fd			= -1;
	pid_t		child		= -1;
	char		*filename	= NULL;
	char		*cmd		= NULL;
	char		*args[3];

	filename = "./output.txt";

	cmd = "/bin/ls";
	args[0] = cmd;
	args[1] = "-lF";
	args[2] = NULL;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
	{
		perror("error -1");
		return (-1);
	}

	child = fork();
	switch ((int)child)
	{
	case -1: /* error */
		close(fd);
		perror("error -11");
		break;

	case 0:	/* child */
		dup2(fd, STDIN_FILENO);
		close(pdes[READ_END]);
		execve(cmd, args, NULL);
		perror("error 00");
		break;
	}	

	/* parent */
	close(fd);
	wait(NULL);
	return 0;	
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