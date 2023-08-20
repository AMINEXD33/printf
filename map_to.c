#include "main.h"
#include <stdarg.h>
#include <stddef.h>

/*
 *mapper-map eatch specifier to it's handling function
 *@str: string
 *@x: the current index in which '%' is found
 *Return: 0 if the handling function is found
 */
int mapper(const char *str, int x, va_list ptr, struct D_array *BUFF)
{
    for (; str[x]!= ' ' && str[x] != '\0';x++)
    {
        if (str[x] == 'c')
        {
            char tmp[2];
            int char_;

            char_ = va_arg(ptr, int);
            tmp[0] = char_;
            tmp[1] = '\0';
            array_push(BUFF,tmp);
            return(1);
        }
        else if(str[x] == 's')
        {
            array_push(BUFF, va_arg(ptr, char*));
            return(1);
        }
        else if(str[x] == '%')
        {
            char tmp[2];
            tmp[0] = '%';
            tmp[1] = '\0';
            array_push(BUFF,tmp);
            return(1);
        }

    }
    return(0);
}
