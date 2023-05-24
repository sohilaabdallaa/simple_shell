#include "main.h"
/**
 * handle_builtin_command - handles execution of built-in functions
 * @commd: tokenized commands
 * @lline: input read from stdin
 *
 * Return: 1 if executed, 0 if not
 */

int handle_builtin_command(char **commd, char *lline)
{
	struct shel_built shel_built = {"environment_command", "exit_shell_command"};

	if (_strcmp(*commd, "env") == 0)
	{
		print_environment_variables();
		return (1);
	}
	else if (_strcmp(*commd, shel_built.exit_shell_command) == 0)
	{
		execute_exit_command(commd, lline);
		return (1);
	}
	return (0);
}
