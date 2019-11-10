/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:01:39 by mgalt             #+#    #+#             */
/*   Updated: 2019/11/07 20:03:30 by mgalt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filit.h"
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <stdlib.h>
# include "libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
#include "libft/libft.h"

int		check2(char	*s)
{
	int		i;
	int		n; //кол-во касаний

	i = 0;
	n = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '#' && s[i + 1] == '#')
			n++;
		if (s[i] == '#' && s[i - 1] == '#')
			n++;
		if (s[i] == '#' && s[i - 5] == '#')
			n++;
		if (s[i] == '#' && s[i + 5] == '#')
			n++;
		i++;
	}
	//printf("n in check2: %d\n", n);
	if (n >= 6)
		return (1);
	return (0);
}

int     check1(char *s)
{
    int     i;
    int     n;

    i = 0;
    n = 0; // кол-во \n (должно быть 5)
    while (s[i] != '\0' && (s[i] == '#' || s[i] == '.' || s[i] == '\n'))
    {
        if (s[i] == '\n' && (i - n) % 4 == 0)
         	n++;
		i++;
	}
	if (n == 5 && i == 21)
		return (1);
	return (0);
}

t_tetris	*write_in_list(char *buf, t_tetris **trm)
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
			(*trm)->pos[j][i] = buf[i1];
			i++;
			i1++;
		}
		i1++;
		j++;
		//printf("|%i|\n", i1);
	}
	(*trm)->max_x = find_max_x(buf);
	(*trm)->max_y = find_max_y(buf);
	//trm = trm->head;
	/*while (trm)
	{
		for (int u = 0; u < 4; u++)
			printf("%s\n", trm->pos[u]);
		trm = trm->next;	
	}*/
	printf("%s\n", (*trm)->pos[0]);
	printf("%s\n", (*trm)->pos[1]);
	printf("%s\n", (*trm)->pos[2]);
	printf("%s\n\n", (*trm)->pos[3]);
	return((*trm)->next);
}

t_tetris *create_list(char *buf, t_tetris **trm)
{
	int j;

	j = 0;
	if (!(*trm))
	{
		printf("ya tut\n");
		*trm = (t_tetris*)malloc(sizeof(t_tetris));
		(*trm)->head = *trm;
		(*trm)->pos = (char**)malloc(sizeof(char*)*4);
		(*trm)->next = NULL;
	}
	else
	{
		printf("dudu\n");
		(*trm)->next = (t_tetris*)malloc(sizeof(t_tetris));
		//printf("aaaa\n");
		//write(1, "G", 1);
		(*trm)->next->head = (*trm)->head;
		(*trm) = (*trm)->next;
		(*trm)->pos = (char**)malloc(sizeof(char*)*4);
		(*trm)->next = NULL;
	}
	while (j < 4)
	{
		(*trm)->pos[j] = (char*)malloc(sizeof(char) * 5);
		(*trm)->pos[j][4] = '\0';
		j++;
	}
	return (write_in_list(buf, trm));
}




int     main(int ac, char **av)
{
    int     fd;
    char    buf[23];
    int     n;
	int		ret;
	int		ret2;
	int		c; //кол-во вызовов read
	t_tetris *trm;

	trm = NULL;
    n = 0;
	ret = 0;
	ret2 = 0;
	c = 0;	
    if (ac != 2)
    {
        ft_putstr("usage: ./fillit file\n");
        return (0);
    }
    else 
    {
        fd = open(av[1], O_RDONLY);
        while ((n = read(fd, buf, 21)) > 0)
		{
        	buf[n] = '\0';
        	//printf("buf:\n%s\n", buf);
        	ret = check1(buf);
			//printf("Ret: %d\n", ret);
			if (ret == 1)
				ret2 = check2(buf);
			if (ret2 != 1)
			{
				ft_putstr("error\n");
				return (0);
			}
			//printf("ret2: %d\n", ret2);
			c++;
			//trm = create_list(buf, trm);
			create_list(buf, &trm);
			//trm->head = trm;
			//trm = trm->next;
		}
		trm = trm->head;
		/*for (int i = 0; i < 3; i++)
		{
			for(int j = 0; j < 4; j++)
				printf("%s\n", trm->pos[j]);
			printf("\n");
			trm = trm->next;
		}*/
		if (c > 26)
		{
			ft_putstr("error\n");
			return (0);	
		}
    }
    return (0);
}

void create_map(int size)
{
	char **map;
	int i;

	i = 0;
	map = (char**)malloc(sizeof(char*)* (size + 1));
	while (i <= size)
	{
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		i++;
	}
	//return (&map);
}

void write_dots(char **map, int size)
{
	int i;
	int j;

	j = 0;
	while (j <= size)
	{
		i = 0;
		while (i != size)
		{
			map[j][i] = '.';
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	map[j][0] = '\0';
}

int write_str(char *map, char *trm, t_cord *cord, char set)
{
	int i;
	int size;
	int j;

	j = 0;
	size = 0;
	while (map[size] != '\0')
		size++;
	i = 0;
	while (map[i] != '\0')
	{
		
		i++;
	}
}

int check_put_tetrimo(char **map, t_tetris *trm, char set)
{
	int size;
	t_cord cord;
	int i;
	int j;

	j = 0;
	i = 0;
	size = 0;
	while (map[size + 1] != '\0')
		size++;
	if (trm->max_x > size || trm->max_y > size)
		return (size + 1);
	else
	{
		while (j <= size)
		{
			if (!(write_str(map[j], trm->pos[i], &cord, set)))
			{
				del_all_str(map, trm, set);
				i = 0;
			}
			else
				i++;
			j++;
		}
	}
}

void erase_map(char **map)
{
	int i;

	i = 0;
	while (map[0] != '\0')
	{
		free(map[i]);
		i++;
	}
	free(map[i]);
	free(map);
}

void write_tetrimo_in_map(char **map, t_tetris *trm)
{

}

void put_tetrimo(char **map, t_tetris *trm)
{
	int size;
	int i;
	char set;

	set = 'A';
	if ((size = check_put_tetrimo(map, trm, set)) != 0)
	{
		erase_map(map);
		create_map(size);
		put_tetrimo(map, trm);
	}
	write_tetrimo_in_map(map, trm);
	if (trm->next != NULL)
		put_tetrimo(map, trm->next);
}