#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * unsigned_int_printer- takes care of pushing an unsigned
 * int to the main BUFFER
 * @BUFF: main BUFFER structure
 * @ptr: variadic variable
 * Return: jump value
 */
int unsigned_int_printer(struct D_array *BUFF, va_list ptr)
{
	unsigned int x;

	x = va_arg(ptr, unsigned int);
	_stringfy_unsigned_int(x, BUFF);
	return (1);
}
/**
 * unsigned_int_to_octal_printer- takes care of pushing an octal
 * to main BUFFER
 * @BUFF: main BUFFER structure
 * @ptr: variadic variable
 * Return: jump value
 */
int unsigned_int_to_octal_printer(struct D_array *BUFF, va_list ptr)
{
	unsigned int x;


	x = va_arg(ptr, unsigned int);
	_stringfy_int_to_octal(x, BUFF);
	return (1);
}
/**
 * unsigned_int_to_hex_printer_A- takes care of pushing a hex to
 * the main BUFFER
 * @BUFF: main BUFFER structure
 * @ptr: variadic variable
 * Return: jump value
 */
int unsigned_int_to_hex_printer_A(struct D_array *BUFF, va_list ptr)
{
	unsigned int x;


	x = va_arg(ptr, unsigned int);
	_stringfy_unsigned_int_hex_A(x, BUFF);
	return (1);
}
/**
 * unsigned_int_to_hex_printer_a- takes care of pushing a hex to
 * the main BUFFER
 * @BUFF: main BUFFER structure
 * @ptr: variadic variable
 * Return: jump value
 */
int unsigned_int_to_hex_printer_a(struct D_array *BUFF, va_list ptr)
{
	unsigned int x;


	x = va_arg(ptr, unsigned int);
	_stringfy_unsigned_int_hex_a(x, BUFF);
	return (1);
}
