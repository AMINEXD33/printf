#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
/**
 * address_printer-takes care of printing a variable address
 * @BUFF: main Buffer structure
 * @ptr: variadic variable
 * Return:jump value
 */
int address_printer(struct D_array *BUFF, va_list ptr)
{
	intptr_t **address;

	address = va_arg(ptr, void *);
	array_push(BUFF, "0x");
	_stringfy_unsigned_long_int_hex((intptr_t)&(address), BUFF);

	return (1);
}
/**
 * reverse_string_printer-takes care of printing a vstring in reverse
 * @BUFF: main Buffer structure
 * @ptr: variadic variable
 * Return:jump value
 */
int reverse_string_printer(struct D_array *BUFF, va_list ptr)
{
	char *str;
	int len_;
	char tmp[2];

	str = va_arg(ptr, char *);
	len_ = len(str);

	while (len_ >= 0)
	{
		tmp[0] = str[len_];
		tmp[1] = '\0';
		array_push(BUFF, tmp);
		len_--;
	}
	return (1);
}
