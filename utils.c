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
/**
 *size_of_int-gets the length of the string representation of a number
 *@x: number
 *Return: the length of the int
 */
int size_of_int(int x)
{
	int BUFF_SIZE;

	BUFF_SIZE = 0;
	while (x > 0)
	{
		BUFF_SIZE++;
		x /= 10;
	}
	return (BUFF_SIZE);
}

