#include "main.h"
/**
 * execute_exit_command - handles the exit command
 * @commd: tokenized command
 * @lline: input read from stdin
 *
 * Return: no return
 **/
void execute_exit_command(char **commd, char *lline)
{
	free(lline);
	free_memory_buffers(commd);
	mysh_exit();
}
