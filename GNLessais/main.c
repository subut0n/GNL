/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:25:02 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/16 12:25:45 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int main (void)
{
    char *line;
    int fd;
    int nb;
    
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

    nb = get_next_line(fd, &line);
    printf("%s\n", line);
    printf("%d\n", nb);
}