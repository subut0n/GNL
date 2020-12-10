/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 17:30:00 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/10 15:32:02 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define BUF_SIZE 4096

int main ()
{
    int fd;
    int ret;
    char buf[BUF_SIZE];

    fd = open("42", O_RDONLY);
    if (fd == -1)
    {
        printf("open() error");
        return (1);
    }
    ret = read(fd, buf, BUF_SIZE);
    buf[ret] = '\0';
    printf("%d\n", ret);
    printf("%s\n", buf);
    if (close(fd) == -1)
    {
        printf("close() error");
        return (1);
    }
    return (0);
}