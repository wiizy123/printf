#include "main.h"

/**
 * print_string - Prints a string
 * @types: List of arguments
 * @buffer: Buffer array for print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int len = 0, a;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[len] != '\0')
		len++;

	if (precision >= 0 && precision < len)
		len = precision;

	if (width > len)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], len);
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - len; i > 0; i--)
				write(1, " ", 1);
			write(1, &str[0], len);
			return (width);
		}
	}
	return (write(1, str, len));
}
/**
 * print_non_printable - Prints ascii codes in hexadecimal
 * of non printable characters
 * @types: List of arguments
 * @buffer: Buffer array for print
 * @flags: calculates active flags
 * @width: width
 * @precision: precision specifier
 * @size: size specifier
 * Return: Number of characters printed
 */

int print_string(va_list types, char buffer[], int flags,
int width, int precision, int size)
{
	int a = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[a] != '\0')
	{
		if (is_printable(str[a]))
			buffer[a  + offset] = str[a];
		else
			offset = offset + append_hexa_code(str[a], buffer, a + offset);
		a++
	}

	buffer[a + offset] = '\0';

	return (write(1, buffer, a + offset));
}
