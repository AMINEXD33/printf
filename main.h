#ifndef __printf_H
#define __printf_H

int _printf(const char *format, ...);
int re_allocte(struct D_array *BUFF, int st_len, char *str);
int array_push(struct D_array *BUFF,char *str);

#endif
