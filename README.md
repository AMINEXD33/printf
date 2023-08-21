![logo-white](https://github.com/AMINEXD33/printf/assets/89471262/1fa3e4b7-fe4f-4334-88ea-c04b15c37b12)

# _printf
Hi there reader ! from the name of the project you can guess that it's a reimplementation of the famous , printf() 
 function in C , and you'll be correct !, first we're going to discuss the usage of the function , then whats going 
 on behind the scenes.
## Usage
The usage of the _printf() function is quite straightforward. This function requires a format argument in the form of a string. Depending on the specifiers included within this format string, the function will process values and output them to the standard output (STDOUT) using the following syntax: `_printf("format", ...)`.
#### specifiers

| specifiers | Type     | Description                |
| :-------- | :------- | :------------------------- |
| `%c` | `char` | print a char |
| `%s` | `string`| print a string|
| `%d` | `int` | print a int |
| `%i` | `octal` | print a octal |

## Examples
##### > string and char
```c
#include "main.h"
int main(void)
{
  _printf("test %s %c %d %i", "string", 'c');
  return(0);
}
```
## Examples
##### > int and octal
```c
#include "main.h"
int main(void)
{
  _printf("test %d %i", "int", 'i');
  return(0);
}
```

#### output
`test string c`
`test int i`
