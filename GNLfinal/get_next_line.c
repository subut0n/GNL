/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 14:34:34 by addzikow          #+#    #+#             */
/*   Updated: 2021/01/16 16:51:26 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_line(char *buf_save)
{
	char		*str;
	size_t		i;

	if (!buf_save)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	i = 0;
	while (buf_save[i] && buf_save[i] != '\n')
		i++;
	if (!(str = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (buf_save[i] && buf_save[i] != '\n')
	{
		str[i] = buf_save[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*get_buf_save(char *buf_save)
{
	char		*str;
	size_t		i;
	size_t		j;

	i = 0;
	if (!buf_save)
		return (NULL);
	while (buf_save[i] && buf_save[i] != '\n')
		i++;
	if (!buf_save[i])
	{
		free(buf_save);
		return (0);
	}
	if (!(str = malloc(sizeof(char) * ((ft_strlen(buf_save) - i) + 1))))
		return (NULL);
	i = i + 1;
	j = 0;
	while (buf_save[i])
		str[j++] = buf_save[i++];
	str[j] = '\0';
	free(buf_save);
	return (str);
}

int		get_next_line(int fd, char **line)
{
	char		*buf;
	static char	*buf_save;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = 1;
	while (!is_nl(buf_save) && (ret = read(fd, buf, BUFFER_SIZE)) != 0)
	{
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		buf_save = cat_buf(buf_save, buf);
	}
	free(buf);
	*line = get_line(buf_save);
	buf_save = get_buf_save(buf_save);
	if (ret == 0)
		return (0);
	return (1);
}
