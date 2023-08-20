#include "main.h"
#include <stdlib.h>
#include <stdio.h>

/*DYNAMIC__ARRAY*/

/**
 *re_allocate-make space and copy a new value to the BUFFER
 *Description:if the new string that needs to be added to the BUFFER is over
*flowing , meaning there is
*no space for it , this function will reallocate a new BUFFER that can hold the
*wanted string and copythe old BUFFER to the new one will also add a marging of
*(1024 bits), to save up time , and call write as little as possible.
 *@BUFF: is the structure of the current BUFF
 *@str: is the string that will be added to the BUFFER
 *Return:0 if success, 1 if malloc failed
 */
int re_allocate(struct D_array *BUFF, char *str)
{
	int x;
	int y;
	int new_length;
	char *re_allocated_arr;

	/*calc length of the new BUFFER*/
	new_length = (BUFF->length) + 1024;
	/*allocate the new buffer and handle malloc if it failed*/
	re_allocated_arr = (char *) malloc(sizeof(char) * (new_length));
	if (re_allocated_arr == NULL)
		_exit_proto(BUFF);/*free and exit*/
	/*copy to new allocated memory*/
	for (x = 0; BUFF->arr[x] != '\0';  x++)
	{
		re_allocated_arr[x] = BUFF->arr[x];
		BUFF->length_of_string++;
	}
	/*update the struct*/
	free(BUFF->arr);/*free the old BUFFER*/
	BUFF->arr = re_allocated_arr; /*update the pointer to the new BUFFER*/
	BUFF->index = x; /*update the index to the current position*/
	BUFF->length = new_length;/*update the BUFFER length*/
	/*copy the new string*/
	y = 0;/*tracker for the str positioning*/
	for (x = BUFF->index ; str[y] != '\0'; x++)
	{
		re_allocated_arr[x] = str[y];
		y++;
		BUFF->length_of_string++;
	}
	re_allocated_arr[x] = '\0';/*add the 0 at the end of the copied str*/
	BUFF->index = x;/*re update the index to the current position after copying*/
	return (0);
}
/**
*array_push-push the new string to the BUFFER
*Description: if the new string can be copied to the BUFFER , this function
*will copy it,in the other
*hand if not , the function will pass so allocating and copying ,
*SEE (re_allocate) above
 *@BUFF: the BUFFER struct
 *@str:string
 *Return: 0 if success, exit(1) if re_alloc function failed
*/
int array_push(struct D_array *BUFF, char *str)
{
	int x;
	int y;
	int st_len;

	st_len = len(str);/*not including '\0'*/
	if ((BUFF->index + st_len) > BUFF->length)
	{
		if (re_allocate(BUFF, str) == 1)
		{
			_exit_proto(BUFF);/*free and exit*/
		}
	}
	else
	{
		y = 0;
		for (x = BUFF->index; str[y] != '\0'; x++)
		{
			BUFF->arr[x] = str[y];
			y++;
			BUFF->index += 1;
			BUFF->length_of_string++;
		}
		BUFF->arr[x] = '\0';
	}
	return (0);
}
