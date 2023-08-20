#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <unistd.h>
/**
 *_printf- a function that prints to stdout ,respecting specifiers
 *@input: initial strig passed to the _printf
 *Return: the lenght of the BUFFER
 */
int _printf(const char *input, ...)
{
	int x;
	va_list ptr;/*variadic VAR*/
	int length = 1000;/*a 1024 buffer*/
	char tmp[2];
	D_array BUFF;

	va_start(ptr, input);
	/*initialize MAIN BUFFER*/
	BUFF.arr = (char *)malloc(sizeof(char) * length);
	if (input == NULL || BUFF.arr == NULL || (input[0] == '%' && !input[1]))
		return (-1);
	if (!input[0])
		return (0);
	/*initialize the length of BUFFER*/
	BUFF.length = length;
	/*initialize thestarting point*/
	BUFF.index = 0;
	BUFF.length_of_string = 0;
	for (x = 0;input[x] != '\0'; x++)
	{
		if (input[x] == '%')
		{
			int val;

			val = mapper(input, (x + 1), ptr, &BUFF);
			x = x + val;/*how many char to jump*/
		}
		else
		{
			tmp[0] = input[x];
			tmp[1] = '\0';
			if (array_push(&BUFF, tmp) == 1)/*if not a specifer just push it to BUFFER*/
				x++;
		}
	}
	write(STDOUT_FILENO, BUFF.arr, BUFF.length_of_string);
	free(BUFF.arr);
	return (BUFF.length_of_string);
}
