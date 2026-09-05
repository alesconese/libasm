#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	/********** Test of ft_strlen **********/
	printf("*** TESTING FUNCTION: ft_strlen ***\n");
	{
		const char *test_str = "Hello, World!";
		printf("\n  TEST 1\n  <Input: \"%s\"\n", test_str);

		size_t result1 = strlen(test_str);
		printf("  >Output with strlen: %zu\n", result1);

		size_t result2 = ft_strlen(test_str);
		printf("  >Output with ft_strlen: %zu\n", result2);

		if (result1 == result2)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}

	/********** Test of ft_strcpy **********/
	printf("\n*** TESTING FUNCTION: ft_strcpy ***\n");
	{
		const char *src = "Copy this string!";
		printf("\n  TEST 1\n  <Source: \"%s\"\n", src);
		
		char dest1[50]; // Ensure the destination buffer is large enough
		
		strcpy(dest1, src);
		printf("  >Destination with strcpy: \"%s\"\n", dest1);
		
		char dest2[50]; // Ensure the destination buffer is large enough

		ft_strcpy(dest2, src);
		printf("  >Destination with ft_strcpy: \"%s\"\n", dest2);

		if (strcmp(dest1, dest2) == 0)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}
	{
		const char *src = "";
		printf("\n  TEST 2\n  <Source: \"%s\"\n", src);

		char dest1[50]; // Ensure the destination buffer is large enough
		strcpy(dest1, src);
		printf("  >Destination with strcpy: \"%s\"\n", dest1);

		char dest2[50]; // Ensure the destination buffer is large enough
		ft_strcpy(dest2, src);
		printf("  >Destination with ft_strcpy: \"%s\"\n", dest2);

		if (strcmp(dest1, dest2) == 0)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}
	
	/********** Test of ft_strcmp **********/
	printf("\n*** TESTING FUNCTION: ft_strcmp ***\n");
	{
		const char *s1 = "Hello";
		const char *s2 = "Hello";
		printf("\n  TEST 1\n  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}
	{
		const char *s1 = "Hello1";
		const char *s2 = "Hello";
		printf("\n  TEST 2\n  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}
	{
		const char *s1 = "Hello1";
		const char *s2 = "Hello5";
		printf("\n  TEST 3\n  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("  RESULT: ✅ PASS\n");
		else
			printf("  RESULT: ❌ FAIL\n");
	}


    return (0);
}