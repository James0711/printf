#include "main.h"

/**
 * is_printable - A function that Checks if a character is printable
 *
 * @c: character to check
 *
 * Return: 1 if printable, 0 otherwise
 */
int is_printable(char c)
{
	return (c >= 32 && c < 127);
}

/**
 * append_hexa_code - A function that appends the hexadecimal representation of
 * a character to a buffer
 *
 * @ascii_code: the character to convert to hexadecimal and append
 * @buffer: the buffer to append the hexadecimal representation to
 * @i: the index to start appending at
 *
 * Return: always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char hex[] = "0123456789ABCDEF";
	unsigned char c = (unsigned char)ascii_code;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = hex[c / 16];
	buffer[i] = hex[c % 16];

	return (3);
}

/**
 * is_digit - this function Checks if a character is a digit
 *
 * @c: character to check
 *
 * Return: 1 if a digit, 0 otherwise
 */
int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * convert_size_number - the function Casts a number to the specified size
 *
 * @num: the number to cast
 * @size: the size to cast to (S_LONG or S_SHORT)
 *
 * Return: the casted value of num
 */
long int convert_size_number(long int num, int size)
{
	switch (size)
	{
		case S_LONG:
			return (num);
		case S_SHORT:
			return ((short)num);
		default:
			return ((int)num);
	}
}

/**
 * convert_size_unsgnd - this functiom Casts an unsigned number
 * to the specified size
 *
 * @num: the number to cast
 * @size: the size to cast to (S_LONG or S_SHORT)
 *
 * Return: the casted value of num
 */
unsigned long int convert_size_unsgnd(unsigned long int num, int size)
{
	switch (size)
	{
		case S_LONG:
			return (num);
		case S_SHORT:
			return ((unsigned short)num);
		default:
			return ((unsigned int)num);
	}
}

