#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
/**
 *_stringfy_unsigned_long_int_hex- get the string representation of a hex
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_unsigned_long_int_hex(intptr_t x
, struct D_array *BUFF_)
{
	int index = 0;
	char *BUFF;
	int length;
	int i;

	if (x == 0)
	{
		array_push(BUFF_, "0");
	}
	BUFF = malloc(sizeof(char) * 100);
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);
	while (x > 0)
	{
		int remainder = x % 16;

		if (remainder < 10)
		{
			BUFF[index] = remainder + '0';
		}
		else
		{
			BUFF[index] = remainder - 10 + 'a';
		}
		x /= 16;
		index++;
	}

	BUFF[index] = '\0';
	length = len(BUFF);
	for (i = 0; i < length / 2; i++)
	{
		char temp = BUFF[i];

		BUFF[i] = BUFF[length - 1 - i];
		BUFF[length - 1 - i] = temp;
	}
	array_push(BUFF_, BUFF);
	free(BUFF);
}
