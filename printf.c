#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>/*REMOVE------------------------------------------<*/
#include "main.h"
int _printf(const char *input,...)
{
    va_list ptr;/*variadic VAR*/
    struct D_array BUFF;/*initialize BUFFER*/
    int length = len(input);
    char tmp[0];

    va_start(ptr, input);
    /*initialize MAIN BUFFER*/
    BUFF.arr = (char*)malloc(sizeof(char) * length);
    /*initialize the length of BUFFER*/
    BUFF.length = length;
    /*initialize thestarting point*/
    BUFF.index = 0;


    for (int x = 0; input[x] != '\0'; x++)
    {
        if (input[x] == '%')
        {
            mapper(input, (x+1));
        }
        else
        {
            tmp[0] = input[x];
            array_push(&BUFF, tmp);
        }
    }
}
