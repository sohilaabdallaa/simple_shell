#include "main.h"
/**
 * free_memory_buffers - frees buffers
 * @buf: buffer to be freed
 * Return: no return
 */

void free_memory_buffers(char **buf)
{
	int n = 0;

	if (!buf || buf == NULL)
		return;
	while (buf[n])
	{
		free(buf[n]);
		n++;
	}
	free(buf);

}
/**
 * mysh_exit - close the shell
 * Return: always 0
 */

int mysh_exit(void)
{
	exit(0);
}

