#include "main.h"
#include <stdlib.h>
#include <stdio.h>
/**
 * _exit_proto- this function makes sure to free the buffer befor exiting
 * @BUFF: the buffer struct
 */
void _exit_proto(struct D_array *BUFF)
{
	free(BUFF->arr);
	exit(-1);
}
/**
 * charBUFF_exit_proto- this function makes sure to free the
 * buffer befor exiting.
 * @BUFF: the buffer struct
 */
void charBUFF_exit_proto(char *BUFF)
{
	free(BUFF);
	exit(-1);
}
