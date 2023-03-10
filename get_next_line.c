/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itovar-n <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:09:15 by itovar-n          #+#    #+#             */
/*   Updated: 2022/12/28 15:55:10 by itovar-n         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>

char	*get_until_nl(char *s, int loopret)
{
	int		i;
	int		j;
	char	*temp;
	int		pos;

	i = 0;
	j = 0;
	pos = 0;
	temp = malloc((ft_strlen(s) + 1) * sizeof(*temp));
	if (!temp)
		return (NULL);
	while (s[i] != '\0' && pos <= loopret)
	{
		if (pos == loopret)
		{
			temp[j] = s[i];
			j++;
		}
		if (s[i] == '\n' || s[i] == '\0')
			pos++;
		i++;
	}
	temp[j] = '\0';
	return (temp);
}

char	*ft_get_line(char *line, char *buf, int fd)
{
	int	ret;

	ret = read (fd, buf, BUFFER_SIZE);
	if (ret == 0)
	{
		buf[0] = '\0';
		if (line[0] != '\0')
			return (line);
	}
	line = ft_testret(line, ret, buf, 1);
	if (line == NULL)
		return (NULL);
	buf[ret] = '\0';
	while (ft_totalloop(buf) == 0)
	{
		line = ft_strjoin(line, buf);
		ret = read (fd, buf, BUFFER_SIZE);
		line = ft_testret(line, ret, buf, 0);
		if (line == NULL)
			return (NULL);
		buf[ret] = '\0';
	}
	return (line);
}

int	ft_totalloop(char *buf)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] == '\n')
			count++;
		i++;
	}
	if (ft_strlen(buf) < BUFFER_SIZE)
		count++;
	return (count);
}

char	*ft_loopbuf(int looprep, char *buf)
{
	char	*temp;

	temp = get_until_nl(buf, looprep);
	if (ft_strlen(temp) == 0)
	{
		ft_free(temp);
		return (NULL);
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	char		*line;
	char		*temp;
	static char	buf[BUFFER_SIZE + 1];
	static int	looprep = 0;

	if (fd < 0)
		return (NULL);
	if (looprep < ft_totalloop(buf) - 1)
	{
		looprep++;
		temp = ft_loopbuf(looprep, buf);
		return (temp);
	}
	line = get_until_nl(buf, looprep + 1);
	if (!line)
		return (NULL);
	line = ft_get_line(line, buf, fd);
	if (!line)
		return (NULL);
	temp = get_until_nl(buf, 0);
	line = ft_strjoin(line, temp);
	ft_free(temp);
	looprep = 0;
	return (line);
}
/*
int	main(void)
{
	int		fd;
	char	*line;
	int i = 0;

	fd = open("42", O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n");
		return (1);
	}
	while(i < 6)
	{
			line = get_next_line(fd);
			printf("New Line: %s",  line);
			i++;
	}
	if (close(fd) == -1)
	{
		printf("Error\n");
		return (1);
	}
	return (0);
}*/