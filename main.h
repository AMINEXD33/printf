#ifndef __printf_H
#define __printf_H

/*dynamic_array.c*/
#include <stdarg.h>

/**
 * struct D_array - Represents a buffer for _printf function.
 * @arr: Pointer to the character array (buffer).
 * @length: Length of the buffer.
 * @index: Current index within the buffer.
 */
typedef struct D_array
{
	int length; /* length of the allocated array */
	int index; /* the last index written into */
	char *arr; /* array or (BUFFER) */
} D_array;




int _printf(const char *format, ...);
int re_allocte(struct D_array *BUFF, int st_len, char *str);
int array_push(struct D_array *BUFF, char *str);
int len(const char *str);
int is_digit(char x);
int mapper(const char *str, int x, va_list ptr, struct D_array *BUFF);
#endif
