#include "main.h"
/**
 *len- caluc the len of a string
 *@str: string
 *Return: len of the string
*/
int len(const char *str)
{
	int x;

	x = 0;
	while (str[x] != '\0')
	{
		x++;
	}
	return (x);
}
/**
 *is_digit- checks if the char is a digit
 *@x: is the char
 *Return: 0 if digit, 1 otherwise
 *
 */
int is_digit(char x)
{
	if (x >= 48 && x <= 57)
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
