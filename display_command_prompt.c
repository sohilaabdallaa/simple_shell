#include "main.h"
/**
 * display_command_prompt - Prints the shell prompt to
 * indicate that the program is
 * ready to receive user input. If the shell is in interactive mode,
 * the prompt displayed to the user.
 * Return: No return value.
 */
void display_command_prompt(void)
{
	/* Check whether the shell is running in interactive mode */
	if ((isatty(STDIN_FILENO) == 1) && (isatty(STDOUT_FILENO) == 1))
		shell_flags.is_interactive_shell = true;

	/* If the shell is in interactive mode, display the prompt to the user */
	if (shell_flags.is_interactive_shell)
		write(STDERR_FILENO, "$ ", 2);
}

