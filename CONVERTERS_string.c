#include "main.h"
#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _stringfy_non_printable_chars- the char passed as an int , the function
 * checks if it represent a Non printable char , if so it checks if the hex
 * value is more or less than one digit, based on it , one digits-->(\x0D)
 * more than one-->(\x1A)
 * @n: the int representation of a char
 * @BUFF_: main BUFFER structure
 */
void _stringfy_non_printable_chars(int n, struct D_array *BUFF_)
{
	char tmp[2];

	if (((n > 0) && (n < 32)) || n >= 127)/*if the char is unprintable*/
	{
		/*the unprintable char hex less than two digit*/
		if (n < 16)
			array_push(BUFF_, "\\x0");
		/*the unprintable char hex more than two digit*/
		else
			array_push(BUFF_, "\\x");
		/*push the hex value to the buffer*/
		_stringfy_unsigned_int_hex_A(n, BUFF_);
	}
	else
	{/*else just print the char as it it*/
		tmp[0] = (char)n;
		tmp[1] = '\0';
		array_push(BUFF_, tmp);
	}
}
