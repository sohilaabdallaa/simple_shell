#include "main.h"
/**
 * test_path - checks whether path is valid
 * @patth: tokenized path
 * @commd: user entered command
 *
 * Return: path appended with command on success, NULL on failure
 */
char *test_path(char **patth, char *commd)
{
	int i = 0;
	char *output;
	int path_found = 0;

	while (patth[i])
	{
		output = append_to_path_string(patth[i], commd);
		if (access(output, F_OK | X_OK) == 0)
		{
			path_found = 1;
			break;
		}
		free(output);
		i++;
	}
	if (!path_found)
		output = NULL;
	return (output);
}
