/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/05 14:52:33 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/16 16:41:10 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/stat.h>

int is_nl(char *buf_save);
size_t  ft_strlen(char *str);
char    *cat_buf(char *buf_save, char *buf);
char    *get_line(char *buf_save);
char    *get_buf_save(char *buf_save);
int get_next_line(int fd, char **line);

#endif