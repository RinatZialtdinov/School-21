/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/26 14:35:49 by damerica          #+#    #+#             */
/*   Updated: 2019/10/13 21:55:53 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_get_next(const int fd, char **argv, char **line)
{
	int		i;
	char	*s;
	int		j;

	j = 0;
	i = 0;
	while (argv[fd][j] != '\0')
		j++;
	while (argv[fd][i] != '\n' && argv[fd][i] != '\0')
		i++;
	if (argv[fd][i] == '\n')
	{
		*line = ft_strsub(argv[fd], 0, i);
		s = ft_strsub(argv[fd], i + 1, j);
		free(argv[fd]);
		argv[fd] = s;
		if (argv[fd][0] == '\0')
			ft_strdel(&argv[fd]);
	}
	else if (argv[fd][i] == '\0')
	{
		*line = ft_strsub(argv[fd], 0, i);
		ft_strdel(&argv[fd]);
	}
	return (1);
}

int	ft_check(int ret, char **argv, const int fd, char **line)
{
	if (ret < 0)
		return (-1);
	else if ((ret == 0 && argv[fd] == NULL))
		return (0);
	return (ft_get_next(fd, argv, line));
}

int	get_next_line(const int fd, char **line)
{
	static char	*argv[255];
	char		*s;
	int			ret;
	char		buf[BUFF_SIZE + 1];

	if (line == NULL || fd < 0)
		return (-1);
	if (argv[fd] && ft_strchr(argv[fd], '\n'))
		return (ft_get_next(fd, argv, line));
	ret = read(fd, buf, BUFF_SIZE);
	while (ret > 0)
	{
		buf[ret] = '\0';
		if (argv[fd] == NULL)
			argv[fd] = ft_strnew(1);
		s = ft_strjoin(argv[fd], buf);
		free(argv[fd]);
		argv[fd] = s;
		if (ft_strchr(argv[fd], '\n'))
			break ;
		ret = read(fd, buf, BUFF_SIZE);
	}
	return (ft_check(ret, argv, fd, line));
}
