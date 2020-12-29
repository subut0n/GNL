#include <stdio.h>
#include <stdlib.h>
#include <string.h>

size_t ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return(i);
}

char    *cat_buf(char *buf_save, char *buf)
{
    char *str;
    size_t i;
    size_t j;
    size_t length;

    i = 0;
    length = ft_strlen(buf_save) + ft_strlen(buf);
    if (!(str = malloc(sizeof(char) *(length + 1))))
        return (NULL);
    if (buf_save)
    {    
        while (buf_save[i] != '\0')
        {
            str[i] = buf_save[i];
            i++;
        }
    }
    j = 0;
    while (buf && buf[j] != '\0')
        str[i++] = buf[j++];
    str[i] = '\0';
    free(buf_save);
    return (str);
}

int main()
{
    char buf[] = "adrien\ndzi";
    static char *buf_save;
    int i = 0;

    buf_save = malloc(sizeof(char) * 5);
    while (i < 4)
    {
        buf_save[i] = 'l';
        i++;
    }
    buf_save[i] = '\0';
    buf_save = cat_buf(buf_save, buf);
    printf("%s\n", buf_save);
    printf("%ld\n", ft_strlen(buf_save));
}