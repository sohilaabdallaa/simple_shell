#include "main.h"

/**
 * main - Entry point for the program
 * Return: Always 0 (Success)
 */

int main(void)
{
	char *lline = NULL, *patthcommd = NULL, *patth = NULL;
	size_t bufsize = 0;
	ssize_t linesize = 0;
	int lineNumber = 0;
	char **commd = NULL, **paths = NULL;

signal(SIGINT, handle_interrupt_signal);
	while (linesize >= 0)
	{
		free_memory_buffers(commd);
		free_memory_buffers(paths);
		lineNumber++, shell_info.line_count++;
		display_command_prompt();
		linesize = getline(&lline, &bufsize, stdin);
		if (linesize < 0)
			break;
		if (checkspace(lline) == true)
			continue;
		if (lline[linesize - 1] == '\n')
			lline[linesize - 1] = '\0';
		commd = tokenize_user_input(lline);
		if ((_strcmp("exit", commd[0]) == 0))
			execute_exit_command(commd, lline);
		if (commd == NULL || *commd == NULL || **commd == '\0')
			continue;
		if (check_builtin_commands(commd, lline, lineNumber))
			continue;
		patth = find_path();
		paths = tokenize_user_input(patth);
		patthcommd = test_path(paths, commd[0]);
		if (!patthcommd)
			fprintf(stderr, "./hsh: %d:%s\n", lineNumber, strerror(errno));
		else
			execution(patthcommd, commd, lineNumber);
		free(patthcommd);
	}
	free(lline);
	if (linesize < 0 && shell_flags.is_interactive_shell)
		write(STDERR_FILENO, "\n", 1);
	return (0);
}
