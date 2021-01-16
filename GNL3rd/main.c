#include <stdio.h>
#include "get_next_line.h"

int main (int argc, char **argv)
{
    char *line=NULL;
    int fd;
    int nb;
    
    (void)argc;
    (void)argv;

    fd = open("42.txt", O_RDONLY);

    nb = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%d\n", nb);

    nb = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%d\n", nb);

    nb = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%d\n", nb);

    // fd = open("test", O_RDONLY);
    // nb = get_next_line(fd, &line);
    // if (line)
    //     printf("YES\n");
    // else
    //     printf("FUCK\n");
    // printf("%d\n", nb);
    // free(line);
}