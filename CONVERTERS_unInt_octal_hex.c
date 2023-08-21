#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *_stringfy_unsigned_int- get the string representation of an int
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_unsigned_int(unsigned int x, struct D_array *BUFF_)
{
	int num_length, SIZE1, BUFF_SIZE, id, i, digit;
	char *BUFF;

	if (x == 0)
		array_push(BUFF_, "0");
	num_length = 0, BUFF_SIZE = 0;
	id = 0;


	SIZE1 = x;
	BUFF_SIZE += size_of_unsigned_int(x);
	num_length = size_of_unsigned_int(x);
	BUFF_SIZE += 1;/*add 1 bit for '\0' */
	BUFF = malloc(sizeof(char) * (BUFF_SIZE));/*allocate buffer*/
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);/*free and exit*/

	while (x > 0)
	{
		SIZE1 = 1;
		for (i = 1; i < num_length; i++)
			SIZE1 *= 10;
		digit = x / SIZE1;
		BUFF[id] = (digit + '0');
		x %= SIZE1;
		num_length--;
		id++;
	}
	BUFF[id] = '\0';
	array_push(BUFF_, BUFF);/*push the str (int) into the main buff*/
	free(BUFF);
}
/**
 *_stringfy_int_to_octal- get the string representation of an octal
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_int_to_octal(unsigned int x, struct D_array *BUFF_)
{
	int index;
	char *octalStr;
	int i;
	int length;

	index = 0;
	octalStr = malloc(sizeof(char) * 101);
	if (octalStr == NULL)
		charBUFF_exit_proto(octalStr);
	while (x > 0)
	{
		octalStr[index] = (x % 8) + '0';
		x /= 8;
		index++;
	}
	octalStr[index] = '\0';
	length = len(octalStr);
	for (i = 0; i < length / 2; i++)
	{
		char temp = octalStr[i];

		octalStr[i] = octalStr[length - 1 - i];
		octalStr[length - 1 - i] = temp;
	}
	array_push(BUFF_, octalStr);
	free(octalStr);
}
/**
 *_stringfy_unsigned_int_hex_A- get the string representation of a hex
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_unsigned_int_hex_A(unsigned int x, struct D_array *BUFF_)
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
			BUFF[index] = remainder - 10 + 'A';
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
/**
 *_stringfy_unsigned_int_hex_a- get the string representation of a hex
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_unsigned_int_hex_a(unsigned int x, struct D_array *BUFF_)
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

