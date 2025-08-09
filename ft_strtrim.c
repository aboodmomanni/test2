#include <stdlib.h>

size_t FrontTrim(char const *s1, char const *set)
{
    size_t i = 0;
    size_t j;

    while (s1[i])
    {
        j = 0;
        while (set[j] && s1[i] != set[j])
            j++;
        if (!set[j])
            break;
        i++;
    }
    return (i);
}

size_t EndTrim(char const *s1, char const *set, size_t start)
{
    size_t end;
    ;
    size_t j;

    end = 0;
    while (s1[end])
        end++;
    while (end > start)
    {
        j = 0;
        while (set[j] && s1[end - 1] != set[j])
            j++;
        if (!set[j])
            break;
        end--;
    }
    return (end);
}

char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;
    char *res;
    size_t i;

    if (!s1 || !set)
        return (NULL);
    start = FrontTrim(s1, set);
    end = EndTrim(s1, set, start);
    res = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!res)
        return (NULL);
    i = 0;
    while (start < end)
        res[i++] = s1[start++];
    res[i] = '\0';
    return (res);
}
