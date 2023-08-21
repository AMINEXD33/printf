#include "main.h"
#include <stdarg.h>
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>

/**
 *mapper- map eatch specifier to it's handling function
 *@str: string
 *@ptr: variadic variable
 *@BUFF: fixed remove
 *@x: the current index in which '%' is found
 *Return: 0 if the handling function is found
 */
int mapper(const char *str, int x, va_list ptr, struct D_array *BUFF)
{
	int i;
	int flag;
	handler Handler[] = {
		{'c', char_printer},
		{'s', string_printrt},
		{'d', int_printer},
		{'i', int_printer},
		{'b', binary_printer},
	};
	flag = 0;
	for (; str[x] != ' ' && str[x] != '\0'; x++)
	{
		i = 0;
		flag = 1;
		while (i < 5)
		{
			if (str[x] == Handler[i].letter)
			{
				return (Handler[i].handler(BUFF, ptr));
				flag = 2;/*a handling function is fund*/
			}
			else if (str[x] == '%')
			{
				return (pers(BUFF));
				flag = 2;/*a handling function is fund*/
			}
			i++;
		}
		if (flag == 1)
			_exit_proto(BUFF);/*free and exit*/
	}
	if (flag == 0)
		_exit_proto(BUFF);/*free and exit*/
	return (0);
}
