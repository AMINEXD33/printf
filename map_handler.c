#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/**
 *char_printer- takes care of pushing a char to the main BUFF
 *@BUFF: main BUFFER struct
 *@ptr: variadic variable
 *Return: a jump value
 */
int char_printer(struct D_array *BUFF, va_list ptr)
{
	char tmp[2];

	tmp[0] = va_arg(ptr, int);
	tmp[1] = '\0';
	array_push(BUFF, tmp);
	return (1);
}
/**
 *string_printrt- takes care of pushing a string to the main BUFF
 *@BUFF: main BUFFER struct
 *@ptr: variadic variable
 *Return: a jump value
 */
int string_printrt(struct D_array *BUFF, va_list ptr)
{
	char *tmp;

	tmp = va_arg(ptr, char*);
	array_push(BUFF, tmp);
	return (1);
}
/**
 *int_printer- takes care of pushing an int to the main BUFF
 *@BUFF: main BUFFER struct
 *@ptr: variadic variable
 *Return: a jump value
 */
int int_printer(struct D_array *BUFF, va_list ptr)
{
	int x;

	if (x < (-2147483647 - 1) || x > 2147483647)/*if int is over the limits*/
		_exit_proto(BUFF);/*free and exit*/
	x = va_arg(ptr, int);
	_stringfy_int(x, BUFF);
	return (1);
}
/**
 * pers-takes care of pushing the special char '%' to the main BUFF
 * @BUFF: the main BUFF struct
 * Return: a jump value
 */
int pers(struct D_array *BUFF)
{
	array_push(BUFF, "%");
	return (1);
}
/**
 * binary_printer- takes care of pushing a binary to the main BUFF
 * @BUFF: main BUFFER struct
 * @ptr: variadic variable
 * Return: a jump value
 */
int binary_printer(struct D_array *BUFF, va_list ptr)
{
	unsigned int x;

	x = va_arg(ptr, unsigned int);
	_toBinary(x, BUFF);
	return (1);
}

