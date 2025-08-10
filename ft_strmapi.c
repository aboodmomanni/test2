#include <stdlib.h>

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *mal;
    unsigned int i;

    if (!s || !f)
        return (NULL);
    mal = malloc(sizeof(char) * (strlen(s) + 1));
    if (!mal)
        return (NULL);
    i = 0;
    while (s[i])
    {
        mal[i] = f(i, s[i]);
        i++;
    }
    mal[i] = '\0';
    return (mal);
}
