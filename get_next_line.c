/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:31:36 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/15 21:04:12 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int is_nl(char *save)
{
    int         i;

    if (!save)
        return(0);
    i = 0;
    while (save[i])
    {
        if (save[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

size_t  ft_strlen(char *str)
{
    size_t      i;

    if (!str)
        return (NULL);
    while (str[i])
        i++;
    return (i);
}

char *ft_strjoin(char *save, char *buf)
{
    size_t      length;
    char        *str;
    int         i;
    int         j;

    length = ft_strlen(save) + ft_strlen(buf);
    if (!(str = malloc(sizeof(char) * (length + 1))))
        return (0);
    i = 0;
    j = 0;
    while (save[j])
        str[i++] = save[j++];
    j = 0;
    while (buf[j])
        str[i++] = buf[j++];
    str[i] = '\0';
    free(save);
    return (str);
}


char *get_buf_save(char *save)
{
    char        *str;
    int         i;
    int         j; 

    i = 0;
    if (!save)
        return (NULL);
    while (save[i] && save[i] != '\n')
        i++;
    if (!save[i])
    {
        free(save);
        return (NULL);
    }
    if (!(str = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
        return (NULL);
    i++;
    j = 0;
    while (save[i])
        str[j++] = save[i++];
    str[j] = '\0';
    free(save);
    return(str);
}

char *get_line(char *save)
{
    char        *str;
    int         i;

    if (!save)
        return (NULL);
    i = 0;
    while (save[i] && save[i] != '\n')
        i++;
    if(!(str = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (save[i] && save[i] != '\n')
    {
        str[i] = save[i];
        i++;
    }
    str[i] = '\0';
    return (str);   
}

int get_next_line(int fd, char **line)
{
    int         ret;
    char        *buf;
    static char *buf_save;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (-1);
    if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
        return (-1);
    ret = 1;
    while(!is_nl(buf_save) && ret != 0)
    {
        ret = read(fd, buf, BUFFER_SIZE);
        if (ret == -1)
        {
            free(buf);
            return (-1);
        }
        buf[ret] = '\0';
        buf_save = ft_strjoin(buf_save, buf);
    }
    free(buf);
    *line = get_line(buf_save);
    buf_save = get_buf_save(buf_save);
    if (ret == 0)
        return (0);
    return (1);
}

#include <stdio.h>

int main (void)
{
    char *line;
    int fd;
    
    fd = open("42", O_RDONLY);

    get_next_line(fd, &line);
    printf("%s\n", line);
    
    get_next_line(fd, &line);
    printf("%s\n", line);

}