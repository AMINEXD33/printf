#include "main.h"
#include <stdlib.h>
#include <stdio.h>
char *_stringfy_long_double(long double x, int presision)
{
    int SIZE1 = (int) x;
    int BUFF_SIZE = 0;
    char *BUFF;
    int id, i, digit,divisor,num;

    while (SIZE1 > 0)
    {
        BUFF_SIZE++;
        SIZE1 /= 10;
    }

    BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
    BUFF = malloc (sizeof (char) * (BUFF_SIZE + presision));
    if (BUFF == NULL)
        exit(-1);    
    /*add the int to the BUFF */
    num = (int)x;
    BUFF_SIZE -= 2;
    id = 0;
    while (BUFF_SIZE > 0)
    {
        divisor = 1;
        for (i = 1; i < BUFF_SIZE; i++)
	    {
	       divisor *= 10;
	    }
        digit = num / divisor;
        BUFF[id] = (digit + '0');
        num %= divisor;
        BUFF_SIZE--;
        id++;
    }
    /*add the rest of the float to the BUFF */
    
    BUFF[id] = '.';
    while (presision > 0)
    {
        x = x - (int)x;
        x *= 10;
        
        presision--;
        id++;
        
        BUFF[id] = (x + '0');
    }
    return(BUFF);


}
char *_stringfy_double(double x, int presision)
{
    int SIZE1 = (int) x;
    int BUFF_SIZE = 0;
    char *BUFF;
    int id,num,i,digit;

    while (SIZE1 > 0)
    {
        BUFF_SIZE++;
        SIZE1 /= 10;
    }
    BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
    BUFF = malloc (sizeof (char) * (BUFF_SIZE + presision));
    if (BUFF == NULL)
        exit(-1);
    /*add the int to the BUFF */
    num = (int)x;
    BUFF_SIZE -= 2;
    id = 0;
    while (BUFF_SIZE > 0)
    {
         int divisor = 1;
        for (i = 1; i < BUFF_SIZE; i++)
	{
	    divisor *= 10;
	}
        digit = num / divisor;
        BUFF[id] = (digit + '0');
        num %= divisor;
        BUFF_SIZE--;
        id++;
    }
    /*add the rest of the float to the BUFF */
    
    BUFF[id] = '.';
    while (presision > 0)
    {
        x = x - (int)x;
        x *= 10;
        
        presision--;
        id++;
        
        BUFF[id] = (x + '0');
    }
    return(BUFF);


}
char *_stringfy_float(float x, int presision)
{
    int SIZE1 = (int) x;
    int BUFF_SIZE = 0;
    char *BUFF;
    int id, num, i, digit,divisor;

    while (SIZE1 > 0)
    {
        BUFF_SIZE++;
        SIZE1 /= 10;
    }

    BUFF_SIZE += 2;		/*add 1 bite for the "." and 1 bite for '\0' */
    BUFF = malloc (sizeof (char) * (BUFF_SIZE + presision));
    if (BUFF == NULL)
        exit(-1);
    /*add the int to the BUFF */
    num = (int)x;
    BUFF_SIZE -= 2;
    id = 0;
    while (BUFF_SIZE > 0)
    {
        divisor = 1;
        for (i = 1; i < BUFF_SIZE; i++)
	{
	    divisor *= 10;
	}
        digit = num / divisor;
        BUFF[id] = (digit + '0');
        num %= divisor;
        BUFF_SIZE--;
        id++;
    }
    /*add the rest of the float to the BUFF */
    
    BUFF[id] = '.';
    while (presision > 0)
    {
        x = x - (int)x;
        x *= 10;
        
        presision--;
        id++;
        
        BUFF[id] = (x + '0');
    }
    return(BUFF);
}

void _stringfy_int(int x,struct D_array *BUFF_)
{
    int num_length;
    int SIZE1, BUFF_SIZE;
    int flag_is_negative;
    char *BUFF;
    int id, i, digit;

    if (x == 0)
        array_push(BUFF_, "0");
    num_length = 0;
    BUFF_SIZE = 0;
    id = 0;
    flag_is_negative = 0;
    if (x < 0)
    {
        BUFF_SIZE += 1;/*add 1 bit for the - sign*/
        flag_is_negative = 1;/*negative true*/
        x = x * -1;/*convert to the positive value*/
    }
    SIZE1 = x;
    BUFF_SIZE += size_of_int(x);
    num_length = size_of_int(x);
    BUFF_SIZE += 1;/*add 1 bit for '\0' */
    BUFF = malloc (sizeof (char) * (BUFF_SIZE));/*allocate buffer*/
    if (BUFF == NULL)
        exit(-1);
    if (flag_is_negative == 1)
    {
        BUFF[id] = '-';
        id++;
    }
    while (x > 0)
    {
        SIZE1 = 1;
        for (i = 1; i < num_length; i++)
           SIZE1 *= 10;
        digit = x / SIZE1;
        BUFF[id] = (digit + '0');
        x %= SIZE1;
        num_length--;
        id++;
    }
    BUFF[id] = '\0';
    array_push(BUFF_, BUFF);/*push the str (int) into the main buff*/
    free(BUFF);
}

