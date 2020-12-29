/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@42student.lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/16 12:17:28 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/29 02:37:30 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

int     is_nl(char *save);
size_t  ft_strlen(char *str);
char    *cat_bufs(char *save, char *buf);
char    *get_buf_save(char *save);
char    *get_line(char *save);
int     get_next_line(int fd, char **line);

#endif