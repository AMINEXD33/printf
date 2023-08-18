#include <stdarg.h>
#include <stdlib.h>
#include "main.h"
int _printf(char *input,...)
{
    va_list ptr;/*variadic VAR*/
    struct D_array BUFF;/*initialize BUFFER*/


    va_start(ptr, input);

    /*initialize MAIN BUFFER*/
    BUFF.arr = (char*)malloc(sizeof(char) * len(input));
    /*initialize the length of BUFFER*/
    BUFF.length = 6;
    /*initialize thestarting point*/
    BUFF.index = 0;


 
    for (int x = 0; input[x] != '\0'; x++){
        if (input[x] == '%')
        {
            mapper(input, (x+1));
        }
        else
        {
            currentchar[0] = input[x];
            currentchar[1] = '\0';
            array_push(&BUFF,currentchar);
        }
        
    }
}
