#include "libasm.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <fcntl.h>
#include <stdlib.h>

int main(void)
{
	/********** Test of ft_strlen **********/
	printf("***** TESTING FUNCTION: ft_strlen*****\n");
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
	printf("\n***** TESTING FUNCTION: ft_strcpy*****\n");
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
	printf("\n***** TESTING FUNCTION: ft_strcmp*****\n");
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
		printf("\n* TEST 3 - S1 shorter than S2\n");

		const char *s1 = "Hello";
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
		printf("\n* TEST 4 - Different character found\n");

		const char *s1 = "Hello World!";
		const char *s2 = "Hello Wxrld!";
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
		printf("\n* TEST 5 - Empty strings\n");

		const char *s1 = "";
		const char *s2 = "";
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
		int err1 = errno;
		printf("  >Output with write: %zd\n", result1);
		printf("  >Error with write: %s [errno: %d]\n", strerror(err1), err1);

		errno = 0;
		ssize_t result2 = ft_write(1, str, 42);
		int err2 = errno;
		printf("  >Output with ft_write: %zd\n", result2);
		printf("  >Error with ft_write: %s [errno: %d]\n", strerror(err2), err2);

		if (result1 == result2 && err1 == err2)
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
		int err1 = errno;
		printf("  >Output with write: %zd\n", result1);
		printf("  >Error with write: %s [errno: %d]\n", strerror(err1), err1);

		errno = 0;
		ssize_t result2 = ft_write(-1, str, strlen(str));
		int err2 = errno;
		printf("  >Output with ft_write: %zd\n", result2);
		printf("  >Error with ft_write: %s [errno: %d]\n", strerror(err2), err2);

		if (result1 == result2 && err1 == err2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}

	/********** Test of ft_read **********/
	printf("\n***** TESTING FUNCTION: ft_read *****\n");
	{
		printf("\n* TEST 1 - Read from file\n");

		int fd = open("Makefile", O_RDONLY);
		if (fd < 0) {
			perror("(!) ERROR: failed to open test file");
			return (1);
		}
		else
			printf("  <Makefile successfully opened for reading\n");

		char buffer1[32];
		ssize_t result1 = read(fd, buffer1, sizeof(buffer1) - 1);
		if (result1 >= 0)
			buffer1[result1] = '\0'; // Null-terminate the string
		printf("  >Output with read: \"%s\" (bytes read: %zd)\n", buffer1, result1);
		close(fd);

		fd = open("Makefile", O_RDONLY);
		char buffer2[32];
		ssize_t result2 = ft_read(fd, buffer2, sizeof(buffer2) - 1);
		if (result2 >= 0)
			buffer2[result2] = '\0'; // Null-terminate the string
		printf("  >Output with ft_read: \"%s\" (bytes read: %zd)\n", buffer2, result2);
		close(fd);

		if (result1 == result2 && strcmp(buffer1, buffer2) == 0)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 2 - Invalid file descriptor\n");

		char buffer1[32];
		errno = 0;
		ssize_t result1 = read(-1, buffer1, sizeof(buffer1) - 1);
		int err1 = errno;
		printf("  >Output with read: %zd\n", result1);
		printf("  >Error with read: %s [errno: %d]\n", strerror(err1), err1);

		char buffer2[32];
		errno = 0;
		ssize_t result2 = ft_read(-1, buffer2, sizeof(buffer2) - 1);
		int err2 = errno;
		printf("  >Output with ft_read: %zd\n", result2);
		printf("  >Error with ft_read: %s [errno: %d]\n", strerror(err2), err2);

		if (result1 == result2 && err1 == err2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}
	{
		printf("\n* TEST 3 - Invalid buffer (NULL)\n");

		int fd = open("Makefile", O_RDONLY);
		if (fd < 0) {
			perror("(!) ERROR: failed to open test file");
			return (1);
		}
		else
			printf("  <Makefile successfully opened for reading\n");
		
		errno = 0;
		char *buffer1 = NULL;
		ssize_t result1 = read(fd, buffer1, 32);
		printf("  >Output with read: %zd\n", result1);
		printf("  >Error with read: %s [errno: %d]\n", strerror(errno), errno);
		close(fd);

		fd = open("Makefile", O_RDONLY);
		errno = 0;
		char *buffer2 = NULL;
		ssize_t result2 = ft_read(fd, buffer2, 32);
		printf("  >Output with ft_read: %zd\n", result2);
		printf("  >Error with ft_read: %s [errno: %d]\n", strerror(errno), errno);
		close(fd);

		if (result1 == result2)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");
	}

	/********** Test of ft_strdup **********/
	printf("\n***** TESTING FUNCTION: ft_strdup *****\n");
	{
		printf("\n* TEST 1 - Non-empty string\n");

		const char *test_str = "Hello, World!";
		printf("  <Input: \"%s\" (address: %p)\n", test_str, (void*)test_str);

		char *result1 = strdup(test_str);
		printf("  >Output with strdup: \"%s\" (address: %p)\n", result1, (void*)result1);

		char *result2 = ft_strdup(test_str);
		printf("  >Output with ft_strdup: \"%s\" (address: %p)\n", result2, (void*)result2);

		if (strcmp(result1, result2) == 0 && result1 != result2 && result2 != test_str)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");

		free(result1);
		free(result2);
	}
	{
		printf("\n* TEST 2 - Empty string\n");

		const char *test_str = "";
		printf("  <Input: \"%s\" (address: %p)\n", test_str, (void*)test_str);

		char *result1 = strdup(test_str);
		printf("  >Output with strdup: \"%s\" (address: %p)\n", result1, (void*)result1);

		char *result2 = ft_strdup(test_str);
		printf("  >Output with ft_strdup: \"%s\" (address: %p)\n", result2, (void*)result2);

		if (strcmp(result1, result2) == 0 && result1 != result2 && result2 != test_str)
			printf("* RESULT: ✅ PASS\n");
		else
			printf("* RESULT: ❌ FAIL\n");

		free(result1);
		free(result2);
	}


    return (0);
}