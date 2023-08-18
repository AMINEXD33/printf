#include "main.h"
int len (char *str)
{
    int x;
    
    x = 0;
    while(str[x] != '\0')
    {
        x++;
    }
    return(x);
}
int is_digit(char x)
{
    if (x >= 48 && x <= 57)
    {
        return (0);
    }
    else
    {
        return (1);
    }
}
