#include "main.h"

/**
 * rot13 -  encodes a string using rot13.
 * @s: string
 *
 * Return: *s
 */

char* _rot13(const char* s)
{
	char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	char* t = str_dup(s);

	if (!t)
	{
		return (NULL);
	}

	int i;

	for (i = 0; t[i] != '\0'; i++)
	{
		int j;

		for (j = 0; j < 52; j++)
		{
			if (t[i] == alpha[j])
			{
				t[i] = rot[j];
				break;
			}
		}
	}

	return (t);
}
