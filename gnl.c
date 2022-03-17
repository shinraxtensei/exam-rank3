#include "gnl.h"

char *ft_strdup(char *str)
{
    char *s;
    int i = 0;
    while (str[i])
        i++;
    s = malloc(sizeof(char) * i + 1);
    i = -1;
    while(str[++i])
        s[i] = str[i];
    s[i] = '\0';
    return s;
}

char *gnl(int fd)
{
    char line[8000000] = {0};
    char c;
    int ret = 1;
    int i = 0;
    while ((ret = read(fd, &c,1)) > 0)
    {
        line[i++] = c;
        if (c == '\n')
            break ;
    }
    if (line[0] == 0)
        return NULL;
    return (ft_strdup(line));
}
#include <stdio.h>

int main ()
{
    gnl(1);
}