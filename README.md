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
| `%d` | `int` | print an int |
| `%i` | `int` | print an octal/decimal |
| `%b` | `unsigned int` | print as binary |
| `%u` | `unsigned int` | print an unsigned int |
| `%x` | `unsigned int` | print as hex (lower case) |
| `%X` | `unsigned int` | print as hex (upper case)  |
| `%o` | `unsigned int` | print as octal  |
| ... | ... | in progress  |


## Examples
#### > string and char
```c
#include "main.h"
int main(void)
{
  _printf("test %s %c", "string", 'c');
  return(0);
}
```

#### output
`test string c`

#### > int
```c
#include "main.h"
int main(void)
{
  _printf("test %d %i", 123, 123);
  return(0);
}
```

#### output
`test 123 123`

#### > binary and unsigned int
```c
#include "main.h"
int main(void)
{
	printf("Binary_of_unsigned_max : %b  |  Unsigned_int_max : %u" , 4294967295, 4294967295);
	return (0);
}
```

#### output
`Binary_of_unsigned_max : 11111111111111111111111111111111  |  Unsigned_int_max  : 4294967295`

#### > hex(lower and upper case)
```c
#include "main.h"
int main(void)
{
	_printf("hex(lower-case) : %x  |  hex(upper-case) : %X" , 4294967295, 4294967295);
	return (0);
}
```

#### output
`hex(lower-case) : ffffffff  |  hex(upper-case) : FFFFFFFF`

##### > octal
```c
#include "main.h"
int main(void)
{
	_printf("octal: %o" , 4294967295);
	return (0);
}
```

#### output
`octal: 37777777777`
`
