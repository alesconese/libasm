#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	// // Test of test
    // int a = 15;
    // int b = 27;
    // int result = ft_add(a, b);

    // printf("Testing ft_add(%d, %d):\n", a, b);
    // printf("  Result: %d\n", result);

    // if (result == (a + b))
    //     printf("  Status: \033[0;32mOK\033[0m\n");
    // else
    //     printf("  Status: \033[0;31mKO\033[0m\n");

	// Test of ft_strlen
	const char *test_str = "Hello, World!";
	size_t result = ft_strlen(test_str);
	printf("%zu\n", result);
	// printf("Testing ft_strlen(\"%s\"):\n", test_str);
	// printf("  Result: %zu\n", result);
	// if (result == strlen(test_str))
	// 	printf("  Status: \033[0;32mOK\033[0m\n");
	// else
	// 	printf("  Status: \033[0;31mKO\033[0m\n");


    return (0);
}