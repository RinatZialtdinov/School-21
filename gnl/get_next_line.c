/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:35:49 by damerica          #+#    #+#             */
/*   Updated: 2019/10/06 20:54:38 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "get_next_line.h"

int ft_get_next(const int fd, char **argv, char **line)
{
	int i;
	char *s;
	int j;

	j = 0;
	i = 0;
	while (argv[fd][j] != '\0')
		j++;
	while (argv[fd][i] != '\n' && argv[fd][i] != '\0')
		i++;
//	printf("%i eto i\n", i); 
	if (argv[fd][i] == '\n')
	{
		*line = ft_strsub(argv[fd], 0, i);
		s = ft_strsub(argv[fd], i+1, j);
		free(argv[fd]);
		argv[fd] = s;
		if (argv[fd][0] == '\0') // || argv[fd][0] == '\n') // || argv[fd][1] == '\0')
			ft_strdel(&argv[fd]);
		//return (1);
	}
	else if (argv[fd][i] == '\0')
	{
		*line = ft_strsub(argv[fd], 0, i);
		ft_strdel(&argv[fd]);
	}
	else 
	{
		ft_strdel(&argv[fd]);
		return (0);
	}
	return (1);
}

int	get_next_line(const int fd, char **line)
{
	static char *argv[255];
	char *s;
	int ret;
	char buf[BUFF_SIZE + 1];

	if (line == NULL || fd < 0)
		return (-1);
	ret = read(fd, buf, BUFF_SIZE);
//	printf("%i ---- ret_ne\n", ret);
	while (ret > 0)
	{
//		printf("%i -- ret || %i -- BUFF", ret, BUFF_SIZE);
		buf[ret] = '\0';
	//	printf("%s - eto buf\n", buf);
		if (argv[fd] == NULL)
			argv[fd] = ft_strnew(1);
		s = ft_strjoin(argv[fd], buf);
	//	printf("%s - eto s\n", s);
		free(argv[fd]);
		argv[fd] = s;
		if (ft_strchr(argv[fd], '\n'))
			break;
		ret = read(fd, buf, BUFF_SIZE);
	}
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && argv[fd] == NULL)) // || argv[fd][0] == '\n')
		return (0);
	return (ft_get_next(fd, argv, line));
}
/*
int main(int argc, char **argv)
{
	char *line;
	int i;
	int fd;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			ft_putstr(line);
			ft_putchar('\n');
		}
	}
	close(fd);
	return (1);
}*/
/*
int main(int argc, char **argv)
{
	char *line;
	int i;
	int fd;
	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		printf("%i", get_next_line(fd, &line));
	}
	return (0);
}*/
