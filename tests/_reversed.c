#include "main.h"


char *rev_str(const char *s)
{
	int i, n = 0;

	while (s[n])
		n++;

	 char r = (char *)malloc(sizeof(char) * (n + 1));
    if (!r)
        return (NULL);

    for (i = 0; i < n; i++)
    {
        r[i] = s[n - 1 - i];
    }
    r[n] = '\0';

    return r;
}
