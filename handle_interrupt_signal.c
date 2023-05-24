#include "main.h"
/**
 * handle_interrupt_signal - handles interrupt signal in interactive mode
 * @m: the signal number
 *
 * Return: nothing
 */

void handle_interrupt_signal(int m)
{
	(void)m;
	write(STDERR_FILENO, "\n", 1);
	write(STDERR_FILENO, "$ ", 2);
}
