#include "main.h"



int char_printer(struct D_array *BUFF,va_list ptr )
{
	char tmp[2];
	tmp[0] = va_arg(ptr , int);
	tmp[1] = '\0';
	array_push(BUFF,tmp);
	return(1);
}
int string_printrt(struct D_array *BUFF,va_list ptr )
{
	char *tmp;
	tmp = va_arg(ptr, char*);
	array_push(BUFF,tmp);
	return(1);
}
int int_printer(struct D_array *BUFF,va_list ptr)
{
	int x;
	x = va_arg(ptr, int);
	_stringfy_int(x,BUFF);
	return(1);
}
int pers(struct D_array *BUFF)
{
	array_push(BUFF, "%");
	return(1);
}
