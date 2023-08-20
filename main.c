#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include "main.h"


int main() {

    int len;
    int len2;


    len = _printf("Let's try to printf a simple sentence.\n");
    len2 = printf("Let's try to printf a simple sentence.\n");
    _printf("Character:[%c]\n", 'H');
    printf("Character:[%c]\n", 'H');
    _printf("String:[%s]\n", "I am a string !");
    printf("String:[%s]\n", "I am a string !");
    len = _printf("Percent:[%%]\n");
    len2 = printf("Percent:[%%]\n");
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    


    len = _printf("%d\n",005);
    len2 = printf("%d\n",005);
    printf("Len:[%d]\n", len);
    printf("Len:[%d]\n", len2);
    return 0;
}