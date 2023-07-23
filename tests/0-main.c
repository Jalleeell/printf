#include <stdio.h>
#include <stdlib.h>
#include "../main.h"

/**
 * main - Entry point
 *
 * Return: 0 on success, error code otherwise
 */
int main(void)
{
		printf("[1]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 2 */
// 	len = _printf("%c", 'S');
// 	len2 = printf("%c", 'S');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[2]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	printf("\n");

// 	/* Test 3 */
// 	len = _printf("A char inside a sentence: %c. Did it work?\n", 'F');
// 	len2 = printf("A char inside a sentence: %c. Did it work?\n", 'F');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[3]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 4 */
// 	len = _printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
// 	len2 = printf("Let'see if the cast is correctly done: %c. Did it work?\n", 48);
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[4]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 5 */
// 	len = _printf("%s", "This sentence is retrieved from va_args!\n");
// 	len2 = printf("%s", "This sentence is retrieved from va_args!\n");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[5]: Lengths differ.\n");
// 		printf("len: %d, len2: %d\n", len, len2);
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 6 */
// 	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
// 	len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", "know");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[6]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 7 */
// 	len = _printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
// 	len2 = printf("Complete the sentence: You %s nothing, Jon Snow.\n", (char *)0);
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[7]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 8 */
// 	len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
// 	len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[8]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 9 */
// 	len = _printf("%%");
// 	len2 = printf("%%");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[9]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	printf("\n");

// 	/* Test 10 */
// 	len = _printf("Should print a single percent sign: %%\n");
// 	len2 = printf("Should print a single percent sign: %%\n");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[10]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 11 */
// 	len = _printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
// 	len2 = printf("%s%c%c%c%s%%%s%c", "Loading ", '.', '.', '.', " 99", " Please wait", '\n');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[11]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	printf("\n");

// 	/* Test 12 */
// 	len = _printf("css%ccs%scscscs", 'T', "Test");
// 	len2 = printf("css%ccs%scscscs", 'T', "Test");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[12]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	printf("\n");

// 	/* Test 13 */
// 	len = _printf(str);
// 	len2 = printf(str);
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[13]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}


// 	/* Test 14 */
// 	len = _printf("man gcc:\n%s", str);
// 	len2 = printf("man gcc:\n%s", str);
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[14]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 15 */
// //	len = _printf(NULL);
// //	len2 = printf(NULL);
// //	fflush(stdout);
// //	if (len != len2)
// //	{
// //		printf("[15]: Lengths differ.\n");
// //		fflush(stdout);
// //		return (1);
// //	}

// 	/* Test 16 */
// 	len = _printf("%c", '\0');
// 	len2 = printf("%c", '\0');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[16]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 17 */
// 	len = _printf("%");
// 	len2 = printf("%");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[17]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 18 */
// 	len = _printf("%!\n");
// 	len2 = printf("%!\n");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[18]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	len = _printf("%K\n");
// 	len2 = printf("%K\n");
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[19]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

// 	/* Test 20 */
// 	len = _printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
// 	len2 = printf("%c%cth %s%s a%cg%s: Y%sou %s no%ching%s Snow.%c", 'W', 'i', "some ", "more", 'r', "s", "", "know", 't', ", Jon", '\n');
// 	fflush(stdout);
// 	if (len != len2)
// 	{
// 		printf("[20]: Lengths differ.\n");
// 		fflush(stdout);
// 		return (1);
// 	}

	/* todo: */
	/* 	- No memory leaks */
	/*  - Handle malloc return */
	/*  - Return success or failure */
	/*  - Betty style */

	return (0);
}
