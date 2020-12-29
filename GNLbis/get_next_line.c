/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: addzikow <addzikow@42student.lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/20 09:35:34 by addzikow          #+#    #+#             */
/*   Updated: 2020/12/29 14:33:49 by addzikow         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

# define BUFFER_SIZE 32

int is_nl(char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while (str && str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

size_t	ft_strlen(char *str)
{
	size_t i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*cat_buf(char *buf_save, char *buf)
{
	char *str;
	size_t i;
	size_t j;
	size_t length;

	length = ft_strlen(buf_save) + ft_strlen(buf);
	if(!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (buf_save && buf_save[j] != '\0')
		str[i++] = buf_save[j++];
	j = 0;
	while(buf && buf[j] != '\n')
		str[i++] = buf[j++];
	str[i] = '\0';
	free(buf);
	return (str);
}

char	*get_line(char *buf_save)
{
	char *str;
	size_t i;
	size_t j;
	size_t length;

	if(!buf_save)
		return (NULL);
	length = ft_strlen(buf_save);
	if(!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	i = 0;
	j = 0;
	if (buf_save[j] == '\0')
		str[i] = '\0';
	while (buf_save[j] != '\n')
		str[i++] = buf_save[j++];
	str[i] = '\0';
	return (str);
}

char *new_buf_save(char *buf_save)
{
	char *str;
	size_t i;
	size_t j;
	size_t length;

	i = 0;
	j = 0;
	length = ft_strlen(buf_save);
	if (!(str = malloc(sizeof(char) * (length))))
		return (NULL);
	if(buf_save[j] == '\0')
		str[i] = '\0';
	while (buf_save[j] != '\0')
		str[i++] = buf_save[j++];
	free(buf_save);
	return (str);
}

int	get_next_line(int fd, char **line)
{
	static char *buf_save;
	char *buf;
	int ret;

	if (fd < 0 || BUFFER_SIZE == 0 || !line)
		return (-1);
	if (!(buf = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	ret = 1;
	while (!is_nl(buf_save) && ret != 0)
	{
		ret = read(fd, buf, BUFFER_SIZE);
		if (ret == -1)
		{
			free(buf);
			return (-1);
		}
		buf[ret] = '\0';
		buf_save = cat_buf(buf_save, buf);
		printf("la %s\n", buf_save);
	}
	free(buf);
	*line = get_line(buf_save);
	buf_save = new_buf_save(buf_save);
	if (ret == 0)
		return (0);
	return (1);
}

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