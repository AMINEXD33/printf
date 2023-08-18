#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
#include <string.h>
#include <unistd.h>
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
            int val;
            /*depending on whiche specifer jump val chars ahead*/
            val = mapper(input, (x+1), ptr, &BUFF);
            x = x + val;
        }
        else
        {
            /*if not a specifer just push it to BUFFER*/
            tmp[0] = input[x];
            if (array_push(&BUFF, tmp) == 1)
            {
                x++;
            }
        }
    }
    write(STDOUT_FILENO, BUFF.arr, BUFF.length);
    free(BUFF.arr);
    
}
