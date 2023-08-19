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
	int length = len(input);
	char tmp[2];
	D_array BUFF;

	va_start(ptr, input);
	/*initialize MAIN BUFFER*/
	BUFF.arr = (char *)malloc(sizeof(char) * length);
	/*initialize the length of BUFFER*/
	BUFF.length = length;
	/*initialize thestarting point*/
	BUFF.index = 0;


	for (x = 0; input[x] != '\0'; x++)
	{
		if (input[x] == '%')
		{
			int val;

			val = mapper(input, (x + 1), ptr, &BUFF);
			x = x + val;
		}
		else
		{
			/*if not a specifer just push it to BUFFER*/
			tmp[0] = input[x];
			tmp[1] = '\0';
			if (array_push(&BUFF, tmp) == 1)
			{
				x++;
			}
		}
	}
	write(STDOUT_FILENO, BUFF.arr, BUFF.length);
	free(BUFF.arr);
	return (BUFF.length);
}
