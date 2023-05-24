#include "main.h"

/**
 * find_path - finds the path from the global enviroment
 * Return: NULL if path is not found or path if path is found.
 */

char *find_path(void)
{
	int mm;
	char **env = environ, *patth = NULL;

	while (*env)
	{
		if (_strncmp(*env, "PATH=", 5) == 0)
		{
			patth = *env;
			while (*patth && mm < 5)
			{
				patth++;
				mm++;
			}
			return (patth);
		}
		env++;
	}
	return (NULL);
}

