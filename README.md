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
| `%p` | `long unsigned int` | print an adress  |
| `%r` | `string` | print a reverced string  |
| `%R` | `string` | print string as ROT13  |


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
	_printf("Binary_of_unsigned_max : %b  |  Unsigned_int_max : %u" , 4294967295, 4294967295);
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

.. same thing applies for the rest of the specifiers.

# Behind the scenes
### How Does this printf Implementation Work?
#### Let's delve into the inner workings of the _printf() function and its core component: the main buffer.
##### The _printf() function employs a dynamic array called the buffer, initially set to a default size of 1024. This buffer expands dynamically as needed to accommodate new values. This design proves to be more efficient than direct writes to the standard output. Rather than writing to the standard output each time the buffer is full, data is accumulated in the buffer until the end of the process. This accumulation minimizes the number of write() calls to just one.

##### 1-Dynamic Array Buffer: _printf() utilizes a dynamically allocated array to store the data to be printed. This array is referred to as the buffer. Its initial size is 1024 bytes, but it dynamically grows as more data is added to it.

##### 2-Efficiency in Accumulation: Instead of immediately writing to the standard output every time a new piece of data is ready, the data is efficiently collected in the buffer. This approach reduces the overhead associated with numerous small write operations.

##### 3-Delayed Output: The buffer continues to accumulate data as the program progresses. This means that multiple printf() calls within the same process can efficiently aggregate their outputs in the buffer without immediate output.

##### 4-Single write() Call: Once the program's main tasks are completed and there's no more data to add to the buffer, a single write() call is used to send the entire accumulated buffer to the standard output. This consolidated write operation significantly reduces the number of system calls, improving performance.

##### 5-Diagram of the Process: Here is a simple Diagram that explains what's going on.

![FINALDYNAMIC drawio (1)](https://github.com/AMINEXD33/printf/assets/136008817/3f3fcc6c-5ec9-49d1-aae6-9f5a62d68d0a)
