/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:28:56 by damerica          #+#    #+#             */
/*   Updated: 2019/11/07 17:32:00 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include <sys/types.h>
# include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include "filit.h"
# include <unistd.h>
#include <stdio.h>

t_tetris	*write_in_list(char *buf, t_tetris *trm)
{
	int i;
	//t_tetris *trm;
	int j;
	int i1;
	//printf("tut\n");
	i1 = 0;
	j = 0;
	/*trm = (t_tetris*)malloc(sizeof(t_tetris));
	trm->head = trm;
	trm->pos = (char**)malloc(sizeof(char*)*4);
	trm->next = NULL;
	while (j < 4)
	{
		trm->pos[j] = (char*)malloc(sizeof(char)*5);
		trm->pos[j][4] = '\0';
		j++;
	}*/
	j = 0;
	while (i1 < 21 && buf[i1] != '\0')
	{
		i = 0;
		while ((buf[i1] != '\n' && i1 < 21) || (buf[i1] != '\n' && buf[i1 + 1] != '\n'))
		{
			trm->pos[j][i] = buf[i1];
			i++;
			i1++;
		}
		i1++;
		j++;
		//printf("|%i|\n", i1);
	}
	//trm = trm->head;
	/*while (trm)
	{
		for (int u = 0; u < 4; u++)
			printf("%s\n", trm->pos[u]);
		trm = trm->next;	
	}*/
	printf("%s\n", trm->pos[0]);
	printf("%s\n", trm->pos[1]);
	printf("%s\n", trm->pos[2]);
	printf("%s\n\n", trm->pos[3]);
	return(trm->next);
}

t_tetris *create_list(char *buf, t_tetris *trm)
{
	int j;

	j = 0;
	if (trm)
	{
		//printf("ya tut\n");
		trm = (t_tetris*)malloc(sizeof(t_tetris));
		trm->head = trm;
		trm->pos = (char**)malloc(sizeof(char*)*4);
		trm->next = NULL;
	}
	else
	{
		//printf("dudu\n");
		trm = (t_tetris*)malloc(sizeof(t_tetris));
		//printf("aaaa\n");
		//write(1, "G", 1);
		//trm->next->head = trm;
		//trm = trm->next;
		trm->pos = (char**)malloc(sizeof(char*)*4);
		trm->next = NULL;
	}
	while (j < 4)
	{
		trm->pos[j] = (char*)malloc(sizeof(char) * 5);
		trm->pos[j][4] = '\0';
		j++;
	}
	return (write_in_list(buf, trm));
}

int main(int argc, char **argv)
{
	int fd;
	int ret;
	char buf[21];
	t_tetris *trm;

	fd = open(argv[1], O_RDONLY);
	while ((ret = read(fd, buf, 21)) > 0)
	{
		buf[ret] = '\0';
		//printf("|||\n%s|||\n", buf);
		trm = create_list(buf, trm);
		//write_in_list(buf);
	}
	return(0);
}
