#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 *_stringfy_long_double- get the str representation of a long double
 *@x: the double
 *@presision: is the number of digits after the .
 *Return: BUFF
 */
char *_stringfy_long_double(long double x, int presision)
{
	int SIZE1 = (int) x;
	int BUFF_SIZE = 0;
	char *BUFF;
	int id, i, digit, divisor, num;

	while (SIZE1 > 0)
	{
		BUFF_SIZE++;
		SIZE1 /= 10;
	}
	BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
	BUFF = malloc(sizeof(char) * (BUFF_SIZE + presision));
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);/*free and exit*/
	/*add the int to the BUFF */
	num = (int)x;
	BUFF_SIZE -= 2;
	id = 0;
	while (BUFF_SIZE > 0)
	{
		divisor = 1;
		for (i = 1; i < BUFF_SIZE; i++)
			divisor *= 10;
		digit = num / divisor;
		BUFF[id] = (digit + '0');
		num %= divisor;
		BUFF_SIZE--;
		id++;
	}
	/*add the rest of the float to the BUFF */
	BUFF[id] = '.';
	while (presision > 0)
	{
		x = x - (int)x;
		x *= 10;
		presision--;
		id++;
		BUFF[id] = (x + '0');
	}
	return (BUFF);
}
/**
 *_stringfy_double- get the str representation of a double
 *@x: the double
 *@presision: is the number of digits after the .
 *Return: BUFF
 */
char *_stringfy_double(double x, int presision)
{
	int SIZE1 = (int) x;
	int BUFF_SIZE = 0;
	char *BUFF;
	int id, num, i, digit, divisor;

	while (SIZE1 > 0)
	{
		BUFF_SIZE++;
		SIZE1 /= 10;
	}
	BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
	BUFF = malloc(sizeof(char) * (BUFF_SIZE + presision));
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);/*free and exit*/
	/*add the int to the BUFF */
	num = (int)x;
	BUFF_SIZE -= 2;
	id = 0;
	while (BUFF_SIZE > 0)
	{
		divisor = 1;
		for (i = 1; i < BUFF_SIZE; i++)
			divisor *= 10;
		digit = num / divisor;
		BUFF[id] = (digit + '0');
		num %= divisor;
		BUFF_SIZE--;
		id++;
	}
	BUFF[id] = '.';/*add the rest of the float to the BUFF*/
	while (presision > 0)
	{
		x = x - (int)x;
		x *= 10;
		presision--;
		id++;
		BUFF[id] = (x + '0');
	}
	return (BUFF);
}
/**
 *_stringfy_float- get the str representation of a float
 *@x: the double
 *@presision: is the number of digits after the .
 *Return: BUFF
 */
char *_stringfy_float(float x, int presision)
{
	int SIZE1 = (int) x;
	int BUFF_SIZE = 0;
	char *BUFF;
	int id, num, i, digit, divisor;

	while (SIZE1 > 0)
	{
		BUFF_SIZE++;
		SIZE1 /= 10;
	}
	BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
	BUFF = malloc(sizeof(char) * (BUFF_SIZE + presision));
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);/*free and exit*/
	/*add the int to the BUFF */
	num = (int)x;
	BUFF_SIZE -= 2;
	id = 0;
	while (BUFF_SIZE > 0)
	{
		divisor = 1;
		for (i = 1; i < BUFF_SIZE; i++)
			divisor *= 10;
		digit = num / divisor;
		BUFF[id] = (digit + '0');
		num %= divisor;
		BUFF_SIZE--;
		id++;
	}
	/*add the rest of the float to the BUFF */
	BUFF[id] = '.';
	while (presision > 0)
	{
		x = x - (int)x;
		x *= 10;
		presision--;
		id++;
		BUFF[id] = (x + '0');
	}
	return (BUFF);
}
/**
 *_stringfy_int- get the string representation of an int
 *@x: number
 *@BUFF_: is the main BUFF struct
 */
void _stringfy_int(int x, struct D_array *BUFF_)
{
	int num_length, SIZE1, BUFF_SIZE, flag_is_negative, id, i, digit;
	char *BUFF;

	if (x == 0)
		array_push(BUFF_, "0");
	num_length = 0, BUFF_SIZE = 0;
	id = 0;
	flag_is_negative = 0;
	if (x < 0)
	{
		BUFF_SIZE += 1;/*add 1 bit for the - sign*/
		flag_is_negative = 1;/*negative true*/
		x = x * -1;/*convert to the positive value*/
	}
	SIZE1 = x;
	BUFF_SIZE += size_of_int(x);
	num_length = size_of_int(x);
	BUFF_SIZE += 1;/*add 1 bit for '\0' */
	BUFF = malloc(sizeof(char) * (BUFF_SIZE));/*allocate buffer*/
	if (BUFF == NULL)
		charBUFF_exit_proto(BUFF);/*free and exit*/
	if (flag_is_negative == 1)
	{
		BUFF[id] = '-';
		id++;
	}
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
 * _toBinary- get a binary representation of a number as a string
 * @n: number
 * @BUFF_: the main BUFFER struct
 * Return: the jump value
 */
void _toBinary(unsigned int n, struct D_array *BUFF_)
{
	int i, remainder, size, tracker;
	char binary[33];
	char *result;

	if (n == 0)
	{
		array_push(BUFF_, "0");
		return;
	}
	size = 0;
	tracker = 0;
	for (i = 32; i >= 0; i--)
	{
		remainder = n % 2;
		n = n / 2;
		binary[i] = remainder + '0';
	}
	binary[33] = '\0';
	i = 0;
	while (binary[i] != '1' && binary[i] != '\0')
	{
		i++;
	}
	size = (33  -  i);
	result = malloc(sizeof(char) * (size + 1));/**1 is for the null**/
	if (result == NULL)
		charBUFF_exit_proto(binary);/*free and exit*/
	for (tracker = 0; tracker < size ; tracker++)
	{
		result[tracker] = binary[(i + tracker)];
	}
	result[tracker] = '\0';
	array_push(BUFF_, result);
	free(result);
}

