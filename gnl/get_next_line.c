/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:35:49 by damerica          #+#    #+#             */
/*   Updated: 2019/09/30 17:07:25 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#define BUF_SIZE 10
#include "get_next_line.h"


void ft_get_next(char **argv, const int fd, char **line)
{
	char *tmp;
	int i;

	i = 0;
	while (argv[fd][i] != '\n')
	{
		*line[i] = argv[fd][i];
		i++;
	}
	tmp = argv[fd];
	argv[fd] = ft_strdup(&argv[fd][i + 1]);
	free(tmp);
}

int	get_next_line(const int fd, char **line)
{
	static char *argv[255];
	int ret;
	int i;
	char *tmp;
	char buf[BUF_SIZE + 1];
	int j;

	j = 0;
	i = 0;
	//write(1, "ds", 2);
//	if (fd < 0 || line == NULL)
//		return (-1);
	while ((ret = read(fd, buf, BUF_SIZE) > 0))
	{
		write(1, "a\n", 2);
		buf[ret] = '\0';
		if (argv[fd] == NULL)
			argv[fd] = ft_strnew(1);
		argv[fd] = ft_strjoin(argv[fd], buf);
		printf("%s\n", argv[fd]);
		if (ft_strchr(argv[fd], '\n'))
		{
			write(1, "tyt", 3);
			ft_get_next(argv, fd, line);
			break;
		}
	}
	//ft_get_next(argv, fd, line);
	return (1);
}

int main(int argc, char **argv)
{
	char *line;
	int a;
	int fd;
	a = open(argv[1], O_RDONLY);
	get_next_line(a, &line);
	printf("%s", line);
	return (1);
}
