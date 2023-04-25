#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * print_char - Prints a char
 * @types: List a of arguments
 * Return: Number of chars printed
 */
int print_char(va_list types)
{
	char c = va_arg(types, int);
	char buffer[2];

	buffer[0] = c;
	buffer[1] = '\0';

	return (handle_write(buffer));
}

/************************* PRINT A STRING *************************/
/**
 * print_string - Prints a string
 * @types: List a of arguments
 * Return: Number of chars printed
 */
int print_string(va_list types)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	if (str == NULL)
	{
		str = "(null)";
	}

	while (str[length] != '\0')
		length++;

	return (handle_write(str));
}

/************************* PRINT PERCENT SIGN *************************/
/**
 * print_percent - Prints a percent sign
 * @types: Lista of arguments
 * Return: Number of chars printed
 */
int print_percent(va_list types)
{
	char buffer[2];

	buffer[0] = '%';
	buffer[1] = '\0';

	return (handle_write(buffer));
}

/************************* PRINT INT *************************/
/**
 * print_int - Print int
 * @types: Lista of arguments
 * Return: Number of chars printed
 */
int print_int(va_list types)
{
	char buffer[BUFF_SIZE];
	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n);

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buffer));
}

/************************* PRINT BINARY *************************/
/**
 * print_binary - Prints an unsigned number
 * @types: Lista of arguments
 * Return: Numbers of char printed.
 */
int print_binary(va_list types)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;
	char buffer[33];

	n = va_arg(types, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			buffer[count++] = '0' + a[i];
		}
	}
	buffer[count] = '\0';
	return (handle_write(buffer));
}

