#include "main.h"
#include <stdio.h>
/*
 *mapper-map eatch specifier to it's handling function
 *@str: string
 *@x: the current index in which '%' is found
 *Return: 0 if the handling function is found
 */
int mapper(char *str, int x)
{
    for (x; str[x]!= ' ' && str[x] != '%' && str[x] != '\0';x++)
    {
        if (str[x] == 'd')
        {
            printf("printing an int\n");
        }
        else if(str[x] == 'c')
        {
            printf("printing a char\n");
        }
        else if(str[x] == '.')
        {
            if (is_digit(str[x+1]) == 0)
            {
                printf("is digit->%c\n", (str[x+1]));
            }
            printf("presision of %c\n", str[x + 1]);
        }

    }
    return(0);
}
