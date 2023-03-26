#include "main.h"

/**
 * print_binary - Prints an unsigned number to be
 * converted to binary.
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: Size specifier
 * Return: Number of characters printed
 */

int print_binary(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	unsigned int c, b, d, sum = 0;
	unsigned int a[32];
	int count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	c = va_arg(types, unsigned int);
	b = 2147483648; /** (2 ^ 31) */
	a[0] = b / c;

	for (d = 1; d < 32; d++)
	{
		b = b / 2;
		a[d] = (c / b) % 2;
	}

	for (d = 0; d < 32; d++)
	{
		sum = sum + a[d];

		if (sum || a == 31)
		{
			char z = '0' + a[d];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}
