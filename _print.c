#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - customized printf function
 * @format: format
 * Return: Printed Characters
 */

int _printf(const char *format, ...)
{
	int a, ptd = 0, cptd = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[i];

			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/** write(1, &format[i], 1); */
			cptd++;
		}
		else
		{
		print_buffer(buffer, buff_ind);

		flags = get_flags(format, &a);

		width = get_width(format, &a, list);

		precision = get_precision(format, &a, list);

		size = get_size(format, &a);

		++a;

		ptd = handle_print(format, &a, list, buffer, flags, width, precision, size);

		if (ptd == -1)
			return (-1);

		cptd = cptd + ptd;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (cptd);
}

/**
 * print_buffer - Prints the contents of an existing buffer
 * @buffer: Array of characters
 * @buff_ind: an index to add the next character which
 * represents the length
 */

void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
