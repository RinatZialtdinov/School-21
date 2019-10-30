/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:28:56 by damerica          #+#    #+#             */
/*   Updated: 2019/10/30 22:20:31 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <sys/types.h>
# include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "filit.h"
# include <unistd.h>
void write_in_list(char *buf)
{
	int i;
	int k;
	t_tetris *trm;
	int j;
	int i1;

	k = 0;
	i1 = 0;
	write(1, "voo\n", 4);
	j = 0;
	trm = (t_tetris*)malloc(sizeof(t_tetris));
	trm->head = trm;
	trm->pos = (char**)malloc(sizeof(char*)*4);
	trm->next = NULL;
	while (j < 4)
	{
		trm->pos[j] = (char*)malloc(sizeof(char)*5);
		trm->pos[j][4] = '\0';
		j++;
	}
	j = 0;
	while (i1 <= 21)
	{
		i = 0;
		printf("%i\n", i1);
		while (buf[i1] != '\n' && i1 < 21)
		{
			printf("%i\n", i1);
			trm->pos[j][i] = buf[i1];
			i++;
			i1++;
		}
		i1++;
		k++;
		/*if (k > 4)
		{
			trm->next = (t_tetris*)malloc(sizeof(t_tetris));
			trm->next->head = trm->head;
			trm = trm->next;
			trm->next = NULL;
			k = 0;
		}*/
		j++;
	}
	trm = trm->head;
	while (trm)
	{
		for (int u = 0; u < 4; u++)
			printf("%s\n", trm->pos[u]);
		trm = trm->next;	
	}
}

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[1000];
	int i;
	
	i = 0;
	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 1000)) > 0)
	{
		write(1, "tut\n", 4);
		printf("%i\n", ret);
		buf[ret] = '\0';
		while (buf[i] != '\0')
		{
			write(1, &buf[i], 1);
			i++;
		}
		write_in_list(buf);
	}
	return(0);
}
