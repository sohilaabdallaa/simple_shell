#include "main.h"
/**
 * append_to_path_string - adds path to command
 * @patth: path of command
 * @commd: user entered command
 *
 * Return: buffer containing command with path on success, NULL on failure
 */
char *append_to_path_string(char *patth, char *commd)
{
	char *buf;
	size_t i = 0, j = 0;

	if (commd == NULL)
		commd = "";
	if (patth == NULL)
		patth = "";
	buf = malloc(sizeof(char) * (_strlen(patth) + _strlen(commd) + 2));
	if (!buf)
		return (NULL);
	while (patth[i])
	{
		buf[i] = patth[i];
		i++;
	}
	if (patth[i - 1] != '/')
	{
		buf[i] = '/';
		i++;
	}
		while (commd[j])
		{
			buf[i + j] = commd[j];
			j++;
		}
		buf[i + j] = '\0';
		return (buf);
}
