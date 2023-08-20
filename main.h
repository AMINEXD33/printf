#ifndef __PRINTF_H
#define __PRINTF_H
/*dynamic_array.c*/
#include <stdarg.h>
#include <stddef.h>

/**
 * struct D_array - Represents a buffer for _printf function.
 * @arr: Pointer to the character array (buffer).
 * @length: Length of the buffer.
 * @index: Current index within the buffer.
 * @length_of_string: only the length of the string
 */
typedef struct D_array
{
	int length; /* length of the allocated array */
	int length_of_string;/*only the length of the str inside the buff*/
	int index; /* the last index written into */
	char *arr; /* array or (BUFFER) */
} D_array;
/**
 *struct handler - struct that maps a char to a function
 *@letter: a char
 *@handler: the function
 */
typedef struct handler
{
	char letter;
	int (*handler)(struct D_array *, va_list);
} handler;


int _printf(const char *format, ...);
int re_allocte(struct D_array *BUFF, char *str);
int array_push(struct D_array *BUFF, char *str);
int len(const char *str);
int is_digit(char x);
int mapper(const char *str, int x, va_list ptr, struct D_array *BUFF);
char *_stringfy_long_double(long double x, int presision);
char *_stringfy_double(double x, int presision);
char *_stringfy_float(float x, int presision);
void _stringfy_int(int x, struct D_array *BUFF);
int size_of_int(int x);
int char_printer(struct D_array *BUFF, va_list ptr);
int string_printrt(struct D_array *BUFF, va_list ptr);
int int_printer(struct D_array *BUFF, va_list ptr);
void _stringfy_int_octal(int x /**, struct D_array *BUFF**/);
int pers(struct D_array *BUFF);
#endif /*__PRINTF_H*/
