#include "main.h"
/**
 * check_builtin_commands- checks to see weather its a built in function
 * @c: tokenized user input
 * @buf: line drived fromgetline function
 * Return: 1 if c excuted 0 if c is not executed
 */

int check_builtin_commands(char **c, char *buf, int lineNumber)
{
	if (handle_builtin_command(c, buf))
		return (1);
	else if (**c == '/')
	{
		execution(c[0], c, lineNumber);
		return (1);
	}
	return (0);
}

