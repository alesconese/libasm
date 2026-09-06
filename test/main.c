#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>

int main(void)
{
	/********** Test of ft_strlen **********/
	printf("***** TESTING FUNCTION: ft_strlen** ***\n");
	{
		printf("\n* TEST 1 - Non-empty string\n");

		const char *test_str = "Hello, World!";
		printf("  <Input: \"%s\"\n", test_str);

		size_t result1 = strlen(test_str);
		printf("  >Output with strlen: %zu\n", result1);

		size_t result2 = ft_strlen(test_str);
		printf("  >Output with ft_strlen: %zu\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 2 - Empty string\n");

		const char *test_str = "";
		printf("  <Input: \"%s\"\n", test_str);

		size_t result1 = strlen(test_str);
		printf("  >Output with strlen: %zu\n", result1);

		size_t result2 = ft_strlen(test_str);
		printf("  >Output with ft_strlen: %zu\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}

	/********** Test of ft_strcpy **********/
	printf("\n***** TESTING FUNCTION: ft_strcpy** ***\n");
	{
		printf("\n* TEST 1 - Non-empty string\n");

		const char *src = "Copy this string!";
		printf("  <Source: \"%s\"\n", src);
		
		char dest1[50];
		char *dest1_ptr = strcpy(dest1, src);
		printf("  >Destination with strcpy: \"%s\"\n", dest1_ptr);
		
		char dest2[50];
		char *dest2_ptr = ft_strcpy(dest2, src);
		printf("  >Destination with ft_strcpy: \"%s\"\n", dest2_ptr);

		if (strcmp(dest1, dest2) == 0)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 2 - Empty string\n");

		const char *src = "";
		printf("  <Source: \"%s\"\n", src);

		char dest1[50];
		char *dest1_ptr = strcpy(dest1, src);
		printf("  >Destination with strcpy: \"%s\"\n", dest1_ptr);

		char dest2[50];
		char *dest2_ptr = ft_strcpy(dest2, src);
		printf("  >Destination with ft_strcpy: \"%s\"\n", dest2_ptr);

		if (strcmp(dest1, dest2) == 0)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	
	/********** Test of ft_strcmp **********/
	printf("\n***** TESTING FUNCTION: ft_strcmp** ***\n");
	{
		printf("\n* TEST 1 - Identical strings\n");

		const char *s1 = "Hello World!";
		const char *s2 = "Hello World!";
		printf("  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 2 - S1 longer than S2\n");

		const char *s1 = "Hello World!";
		const char *s2 = "Hello";
		printf("  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 3 - Different character found\n");

		const char *s1 = "Hello World!";
		const char *s2 = "Hello Wxrld!";
		printf("\n* TEST 3\n  <String 1: \"%s\"\n  <String 2: \"%s\"\n", s1, s2);

		int result1 = strcmp(s1, s2);
		printf("  >Output with strcmp: %d\n", result1);

		int result2 = ft_strcmp(s1, s2);
		printf("  >Output with ft_strcmp: %d\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}

	/********** Test of ft_write **********/
	printf("\n***** TESTING FUNCTION: ft_write *****\n");
	{
		printf("\n* TEST 1 - Valid string to stdout\n");

		const char *str = "Hello, World!";
		printf("  <String: \"%s\"\n", str);

		ssize_t result1 = write(1, str, strlen(str));
		printf("\n  >Output with write: %zd\n", result1);

		ssize_t result2 = ft_write(1, str, strlen(str));
		printf("\n  >Output with ft_write: %zd\n", result2);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 2 - NULL string to stdout\n");

		const char *str = NULL;
		printf("  <String: \"%s\"\n", str);

		errno = 0;
		ssize_t result1 = write(1, str, 42);
		printf("  >Output with write: %zd\n", result1);
		printf("  >Error with write: %s [errno: %d]\n", strerror(errno), errno);

		errno = 0;
		ssize_t result2 = ft_write(1, str, 42);
		printf("  >Output with ft_write: %zd\n", result2);
		printf("  >Error with ft_write: %s [errno: %d]\n", strerror(errno), errno);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 3 - Invalid file descriptor\n");

		const char *str = "Hello, World!";
		printf("  <String: \"%s\"\n", str);

		errno = 0;
		ssize_t result1 = write(-1, str, strlen(str));
		printf("  >Output with write: %zd\n", result1);
		printf("  >Error with write: %s [errno: %d]\n", strerror(errno), errno);

		errno = 0;
		ssize_t result2 = ft_write(-1, str, strlen(str));
		printf("  >Output with ft_write: %zd\n", result2);
		printf("  >Error with ft_write: %s [errno: %d]\n", strerror(errno), errno);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}

    return (0);
}