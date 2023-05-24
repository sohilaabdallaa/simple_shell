#include "main.h"
/**
 * execution - executes commands entered by users.
 * @conpath: command path.
 * @arra: vector array of pointers to commands.
 * @lineNumber : interger tell us the order of current input line.
 * Return: void
 */

void execution(char *conpath, char **arra, int lineNumber)
{
	pid_t child_pid;
	int stat;
	char **env = environ;

	child_pid = fork();

	if (child_pid < 0)
		fprintf(stderr, "./hsh: %d:%s\n", lineNumber, strerror(errno));
	if (child_pid == 0)
	{
		execve(conpath, arra, env);
		fprintf(stderr, "./hsh: %d:%s\n", lineNumber, strerror(errno));
		free(conpath);
		free_memory_buffers(arra);
		exit(98);
	}
	else
		wait(&stat);
}
