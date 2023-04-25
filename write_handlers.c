#include "main.h"

/**
 * handle_write_char - A function that prints a character
 * @c: character to be printed
 * @buffer: buffer to hold printed character
 * @flags: active flags
 * @width: width specifier
 *
 * Return: Number of characters printed.
 */
int handle_write_char(char c, char buffer[], int flags, int width)
{
	int printed_chars = 0;
	char padd = (flags & F_ZERO) ? '0' : ' ';

	buffer[0] = c;
	buffer[1] = '\0';

	if (width > 1)
	{
		int padding_width = width - 1;

		if (flags & F_MINUS)
		{
			printed_chars += write(1, &buffer[0], 1);
			printed_chars += write_padding(buffer, padding_width, padd);
		}
		else
		{
			printed_chars += write_padding(buffer, padding_width, padd);
			printed_chars += write(1, &buffer[0], 1);
		}
	}
	else
	{
		printed_chars += write(1, &buffer[0], 1);
	}

	return (printed_chars);
}

/**
 * write_number - A function that writes a number
 * @is_negative: a flag indicating if the number is negative
 * @ind: starting index of the number in the buffer
 * @buffer: buffer to hold the number
 * @flags: active flags
 * @width: width specifier
 * @precision: precision specifier
 *
 * Return: Number of characters printed.
 */
int write_number(int is_negative, int ind, char buffer[],
		int flags, int width, int precision)
{
	int length = BUFF_SIZE - ind - 1;
	char padd = (flags & F_ZERO) ? '0' : ' ';
	char extra_ch = 0;

	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	length += (extra_ch != 0);

	if (precision > length - (extra_ch != 0))
	{
		precision -= length - (extra_ch != 0);
		length = write_padding(buffer, precision, '0') +
			length - (precision - (extra_ch != 0));
	}

	if (extra_ch != 0)
		buffer[--ind] = extra_ch;

	return (write(1, &buffer[ind], length) +
			write_padding(buffer, width - length, padd));
}

/**
 * write_padding - A function that writes padding to the buffer
 * @buffer: buffer to hold the padding
 * @width: width of the padding
 * @padd: padding character
 *
 * Return: Number of characters printed.
 */
int write_padding(char buffer[], int width, char padd)
{
	int i;

	for (i = 0; i < width; i++)
		buffer[i] = padd;

	return (write(1, &buffer[0], width));
}

