#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_unsigned(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int i = va_arg(types, unsigned long int);

	i = convert_size_unsgnd(i, size);

	if (i == 0)
		buffer[a--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (i > 0)
	{
		buffer[a--] = (i % 10) + '0';
		i = i / 10;
	}
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints unsigned integers in octal notation
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_octal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int i = va_arg(types. unsigned long int);
	unsigned long int num = i;

	UNUSED(width);

	i = convert_size_unsgnd(i, size);

	if (i == 0)
		buffer[a--] = '\0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (i > 0)
	{
		buffer[a--] = (i % 8) + '0';
		i = i / 8;
	}
	if (flags & F_HASH && num != 0)
		buffer[a--] = '0';
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned integer in hex notation
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_hexadecimal(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		int flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Prints an unisigned number in upper hex notation
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_hexa_upper(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: List of arguments
 * @buffer: Buffer array to print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_hexa(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int a = BUFF_SIZE - 2;
	unsigned long int i = va_arg(types, unsigned long int);
	unsigned long int num = i;

	UNUSED(width);

	i = convert_size_unsgnd(i, size);

	if (i == 0)
		buffer[a--] = '\0';

	while (i > 0)
	{
		buffer[a--] = map_to[i % 16]
		i = i / 16;
	}
	if (flags & F_HASH && num != 0)
	{
		buffer[a--] = flag_ch;
		buffer[a--] = '0';
	}
	a++;

	return (write_unsgnd(0, a, buffer, flags, width, precision, size));
}
