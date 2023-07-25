#include "main.h"


char* _rot13(const char* s) 
{
    char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghjklmnopqrstuvwxyz";
    char rot[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    char* t = str_dup(s);
    if (!t) 
    {
        return (NULL);
    }

    for (int i = 0; t[i] != '\0'; i++)
    {
        for (int j = 0; j < 52; j++)
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
