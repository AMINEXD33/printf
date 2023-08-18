#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include "main.h"
void _printf(char *input,...)
{
    char *currentchar;
    va_list ptr;
    int start ,flag1;
    int end ,fla2;
    struct D_array BUFF;

    currentchar = malloc(sizeof(char) * 2);
    BUFF.arr = (char*)malloc(sizeof(char) * 6);
    BUFF.length = 6;
    BUFF.index = 0;
    // Initializing argument to the
    // list pointer
    //va_start(ptr, input);
    //printf("%s\n",input);

    //for (int x = 0; x <= 2; x++)
      //  printf("%d\n",va_arg(ptr, int));
    
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
    printf("%s\n", BUFF.arr);
}
