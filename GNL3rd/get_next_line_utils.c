/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:49:15 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/05 15:06:55 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int is_nl(char *buf_save)
{
    int i;

    i = 0;
    if (!buf_save)
        return(0);
    while (buf_save[i] != '\0')
    {
        if (buf_save[i] == '\n')
            return (1);
        i++;
    }
    return (0);
}

size_t  ft_strlen(char *str)
{
    size_t i;

    i = 0;
    if (!str)
        return(0);
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