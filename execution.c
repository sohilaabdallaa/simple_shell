#include "main.h"
/**
 * execution - executes commands entered by users
 * @conpath: command path
 * @arra: vector array of pointers to commands
 *
 * Return: void
 */

void execution(char *conpath, char **arra)
{
	pid_t child_pid;
	int stat;
	char **env = environ;

	child_pid = fork();

	if (child_pid < 0)
		perror(conpath);
	if (child_pid == 0)
	{
		execve(conpath, arra, env);
		perror(conpath);
		free(conpath);
		free_memory_buffers(arra);
		exit(98);
	}
	else
		wait(&stat);
}
