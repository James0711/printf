#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - This is Printf function
 * @format: format string
 * @...: variable argument list
 *
 * Return: number of printed characters
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0, buff_ind = 0;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (*format)
	{
	if (*format != '%')
	{
		buffer[buff_ind++] = *format++;
		if (buff_ind == BUFF_SIZE)
		{
			print_buffer(buffer, &buff_ind);
		}
		printed_chars++;
	}
	else
	{
		format++;
		int flags = get_flags(format, &format);
		int width = get_width(format, &format, args);
		int precision = get_precision(format, &format, args);
		int size = get_size(format, &format);
		int printed = handle_print(format, &format, args, buffer,
				flags, width, precision, size);
		if (printed == -1)
			return (-1);
		printed_chars += printed;
		if (buff_ind)
		{
			print_buffer(buffer, &buff_ind);
		}
	}
	}
	print_buffer(buffer, &buff_ind);

	va_end(args);

	return (printed_chars);
}

/**
 * print_buffer - Prints the contents of the buffer if it exists
 * @buffer: buffer containing characters to be printed
 * @buff_ind: index at which to add next char, represents the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, &buffer[0], *buff_ind);
	}
	*buff_ind = 0;
}

