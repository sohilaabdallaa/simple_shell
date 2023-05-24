#include "main.h"

/**
 * main - Entry point for the program
 * @ac: the number of argument
 * @av: pointer of array of string
 * @envp: enviromnet vector
 * Return: Always 0 (Success)
 */

int main(int ac, char **av, char *envp[])
{
	char *lline = NULL, *patthcommd = NULL, *patth = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	char **commd = NULL, **paths = NULL;
	(void)envp, (void)av;
	if (ac < 1)
		return (-1);
signal(SIGINT, handle_interrupt_signal);
	while (1)
	{
		free_memory_buffers(commd);
		free_memory_buffers(paths);
		free(patthcommd);
		display_command_prompt();
		linesize = getline(&lline, &bufsize, stdin);
		if (linesize < 0)
			break;
		shell_info.line_count++;
		if (lline[linesize - 1] == '\n')
			lline[linesize - 1] = '\0';
		commd = tokenize_user_input(lline);
		if (commd == NULL || *commd == NULL || **commd == '\0')
			continue;
		if (check_builtin_commands(commd, lline))
			continue;
		patth = find_path();
			paths = tokenize_user_input(patth);
		patthcommd = test_path(paths, commd[0]);
		if (!patthcommd)
			perror(av[0]);
		else
			execution(patthcommd, commd);
	}
	if (linesize < 0 && shell_flags.is_interactive_shell)
		write(STDERR_FILENO, "\n", 1);
	free(lline);
	return (0);
}
