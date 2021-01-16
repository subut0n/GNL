/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:31:36 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/16 14:20:59 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_buf_save(char *save)
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

char    *get_line(char *save)
{
    char        *str;
    int         i;

    if (!save)
        return (NULL);
    i = 0;
    while (save && save[i] != '\n')
        i++;
    if(!(str = malloc(sizeof(char) * (i + 1))))
        return (NULL);
    i = 0;
    while (save && save[i] != '\n')
    {
        str[i] = save[i];
        i++;
    }
    str[i] = '\0';
    return (str);   
}

int     get_next_line(int fd, char **line)
{
    int         ret;
    char        *buf;
    static char *buf_save;

    if (fd < 0 || BUFFER_SIZE <= 0 || !line)
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