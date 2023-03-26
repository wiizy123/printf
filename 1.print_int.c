#include "main.h"

/**
 * print_int - Prints integers
 * @types: List of arguments
 * @buffer: buffer array for print
 * @flags: calculates active flags
 * @width: width
 * @precision: precise specification
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_int(va_list types, char buffer[],
int flags, int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	int negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int b;

	n = convert_size_number(n, size);

	if (n == 0)
		buffer[a--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';
	b = (unsigned long int)n;

	if (n < 0)
	{
		b = (unsigned long int)((-1) * n);

		negative = 1;
	}

	while (num > 0)
	{
		buffer[a--] = (b % 10) + '0';

		b /= 10;
	}
	a++;

	return (write_number(negative, a, buffer, flags, width, precision, size));
}
