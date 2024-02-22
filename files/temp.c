#include "stdio.h"

void    change_int_ptr(int *n)
{
    *n = 10;
    printf("change_int_ptr:%d\n", *n);
}

void    change_int(int num)
{
    num = 10;
    printf("change_int:%d\n", num);
}

int main(void)
{
    int a;
    int *ptr;
    ptr = &a;
    a = 5;
    printf("a:%d\n", a);
    change_int(a);
    printf("a:%d\n", a);
    change_int_ptr(ptr);
    printf("a:%d\n", a);
    return (0);
}