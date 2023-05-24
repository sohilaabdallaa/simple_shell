#include "main.h"

#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @cha: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned and errno set appropriately
 */
int _putchar(char cha)
{
	return (write(1, &cha, 1));
}

/**
 * print_str - prints a string
 *@str: string to be printed
 *
 *  Return: number of characters printed
 */
int print_str(char *str)
{
	int k = 0;

	while (str[k] != '\0')
	{
		_putchar(str[k]);
		k++;
	}
	return (k);
}

