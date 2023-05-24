#include "main.h"
/**
 * print_environment_variables - prints the environment string to stdout
 *
 * Return: void
 */
void print_environment_variables(void)
{
	int x = 0;
	char **env = environ;

	while (env[x])
	{
		write(STDOUT_FILENO, (const void *)env[x], _strlen(env[x]));
		write(STDOUT_FILENO, "\n", 1);
		x++;
	}
}
