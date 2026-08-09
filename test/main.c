#include <stdio.h>
#include "libasm.h"

int main(void)
{
    int a = 15;
    int b = 27;
    int result = ft_add(a, b);

    printf("Testing ft_add(%d, %d):\n", a, b);
    printf("  Result: %d\n", result);

    if (result == (a + b))
        printf("  Status: \033[0;32mOK\033[0m\n");
    else
        printf("  Status: \033[0;31mKO\033[0m\n");

    return (0);
}