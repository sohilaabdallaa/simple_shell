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

/**
 * checkspace - check if the whole line is only empty space.
 * @lline : pointer to char input line.
 * Return:true if all is space otherwise false.
 */
bool checkspace(char *lline)
{
	int i = 0;

	while (lline[i])
	{
		if (!isspace(lline[i]))
			return (false);
		i++;
	}
	return (true);
}
