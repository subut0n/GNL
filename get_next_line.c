/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/10 15:31:36 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/10 16:53:43 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#define BUFFER_SIZE 4096

int get_next_line(int fd, char **line)
{
    static int i = 0;
    int courant;
    char buf[BUFFER_SIZE];
    int ret;

    if (fd < 0)
        return (-1);
    while (*line[i] != '\n')
        i++;
    courant = 0;
    while (courant < i)
        buf[courant] = *line[courant];
    ret = read(fd, buf, BUFFER_SIZE);
    return (ret);
}