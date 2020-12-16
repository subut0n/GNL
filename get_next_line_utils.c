/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:17:40 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/16 12:28:10 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int     is_nl(char *save)
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

    i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

char    *ft_strjoin(char *save, char *buf)
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
    while (save && save[j])
        str[i++] = save[j++];
    j = 0;
    while (buf && buf[j])
        str[i++] = buf[j++];
    str[i] = '\0';
    free(save);
    return (str);
}