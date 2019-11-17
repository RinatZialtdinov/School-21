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

int find_max_x(t_tetris *trm)
{
	int i;
	int j;
	int max;
	int result;
	printf("find_max_x 0\n");
	j = 0;
	max = 0;
	result = 0;
	while (j <= 3)
	{
		i = 0;
		//printf("j = %i\n", j);
		while (i <= 3)
		{
			while (trm->pos[j][i] == '#')
			{
				i++;
				max++;
			}
			if (max > result)
			{
				result = max;
				max = 0;
			}
			i++;
			//printf("i = %i\n", i);
		}
		j++;
	}
	printf("find_max_x 1\n");
	return (result);
}

int find_max_y(t_tetris *trm)
{
	int i;
	int j;
	int max;
	int result;
	printf("find_max_y 0\n");
	j = 0;
	max = 0;
	while (i <= 3)
	{
		j = 0;
		while (j <= 3)
		{
			while (trm->pos[j][i] == '#')
			{
				j++;
				max++;
			}
			if (max > result)
			{
				result = max;
				max = 0;
			}
			j++;
		}
		i++;
	}
	printf("find_max_y 1\n");
	return (result);
}

int improve_length(char *buf)
{
	int i;
	int count;
	int result;

	result = 4;
	count = 0;
	i = 0;
	while (i < 21)
	{
		while (buf[i] != '\n')
		{
			if (buf[i] == '.')
			{
				count++;
			}
			i++;
		}
		if (count == 4)
		{
			result--;
		}
		count = 0;
		i++;
	}
	//printf("improve_lenght = %i\n", result);
	//while (getchar()!='\n');
	return (result);
}

int improve_width(char *buf)
{
	int i;
	int count;
	int result;
	//printf("improve_width 0\n");
	result = 4;
	count = 0;
	i = 0;
	while (i != 4)
	{
		while (i <= 19)
		{
			if (buf[i] == '.')
			{
				count++;
			}
			i = i + 5;
		}
		if (count == 4)
		{
			result --;
		}
		count = 0;
		i = i - 19;
	}
	//printf("improve_width 1\n");
	if (result == 0)
		return (0);
	return (result + 1);
}

int dot(char *buf, int i1)
{
	int count;
	int count1;

	count1 = 0;
	count = 0;
	if (buf[i1] == '#')
		return (1);
	else 
	{
		if (i1 - 5 >= 0 && buf[i1 - 5] == '.')
		{
			count++;
			//printf("-5\n");
		}
		if (i1 - 10 >= 0 && buf[i1 - 10] == '.')
		{
			count++;
			//printf("-10\n");
		}
		if (i1 - 15 >= 0 && buf[i1 - 15] == '.')
		{
			count++;
			//printf("-15\n");
		}
		if (i1 + 5 <= 19 && buf[i1 + 5] == '.')
		{
			count++;
			//printf("+5\n");
		}
		if (i1 + 10 <= 19 && buf[i1 + 10] == '.')
		{
			count++;
			//printf("+10\n");
		}
		if (i1 + 15 <= 19 && buf[i1 + 15] == '.')
		{
			count++;
			//printf("+15\n");
		}
		if (i1 >= 0 && i1 <= 3)
		{
			i1 = 0;
			while (i1 <= 3)
			{
				if (buf[i1] == '.')
					count1++;
				i1++;
			}
		}
		if (i1 >= 5 && i1 <= 8)
		{
			i1 = 5;
			while (i1 <= 8)
			{
				if (buf[i1] == '.')
					count1++;
				i1++;
			}
		}
		if (i1 >= 10 && i1 <= 13)
		{
			i1 = 10;
			while (i1 <= 13)
			{
				if (buf[i1] == '.')
					count1++;
				i1++;
			}
		}
		if (i1 >= 15 && i1 <= 18)
		{
			i1 = 15;
			while (i1 <= 18)
			{
				if (buf[i1] == '.')
					count1++;
				i1++;
			}
		}
	}
	//printf("count == %i\n count1 == %i\n", count, count1);
	if (count == 3 || count1 == 4)
		return (0);
	else
		return (1);
}

t_tetris	*write_in_list(char *buf, t_tetris **trm)
{
	int i;
	//t_tetris *trm;
	int j;
	int i1;
	int k;
	//int k;
	//printf("tut\n");
	//int count;

	//count = 0;
	k = 0;
	i1 = 0;
	j = 0;
	//k = 0;
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
	(*trm)->max_y = improve_length(buf);
	(*trm)->max_x = improve_width(buf) - 1;
	while (i1 < 21 && buf[i1] != '\0')
	{
		i = 0;
		while ((buf[i1] != '\n' && i1 < 21) || (buf[i1] != '\n' && buf[i1 + 1] != '\n'))
		{
			//printf("i1 == %i\n", i1);
			if (dot(buf, i1))
			{
				//printf("ix == %i\n", i);
				(*trm)->pos[j][i] = buf[i1];
				i++;
				k = 1;
			}
			i1++;
		}
		i1++;
		if (k == 1)
		{
			j++;
			k = 0;
		}
		//printf("|%i|\n", i1);
	}
	printf("trm_x = %i   trm_y = %i\n", (*trm)->max_x, (*trm)->max_y);
	//trm = trm->head;
	//while ((*trm))
	//{
		//for (int u = 0; u < (*trm)->max_y; u++)
		//	printf("%s\n", (*trm)->pos[u]);
		//(*trm) = (*trm)->next;	
	//}
	/*printf("%s\n", (*trm)->pos[0]);
	printf("%s\n", (*trm)->pos[1]);
	printf("%s\n", (*trm)->pos[2]);
	printf("%s\n\n", (*trm)->pos[3]);*/
	printf("\n");

	return((*trm)->next);
}

/*int improve_length(char *buf)
{
	int i;
	int count;
	int result;

	result = 4;
	count = 0;
	i = 0;
	while (i < 21)
	{
		while (buf[i] != '\n')
		{
			if (buf[i] == '.')
			{
				count++;
			}
			i++;
		}
		if (count == 4)
		{
			result--;
		}
		count = 0;
		i++;
	}
	printf("improve_lenght = %i\n", result);
	//while (getchar()!='\n');
	return (result);
}

int improve_width(char *buf)
{
	int i;
	int count;
	int result;
	printf("improve_width 0\n");
	result = 4;
	count = 0;
	i = 0;
	while (i != 4)
	{
		while (i <= 19)
		{
			if (buf[i] == '.')
			{
				count++;
			}
			i = i + 5;
		}
		if (count == 4)
		{
			result --;
		}
		count = 0;
		i = i - 19;
	}
	printf("improve_width 1\n");
	if (result == 0)
		return (0);
	return (result + 1);
}*/

t_tetris *create_list(char *buf, t_tetris **trm)
{
	int j;
	int res;
	j = 0;
	int k;

	k = improve_length(buf);
	//printf("k = %i\n", k);
	if (!(*trm))
	{
		//printf("ya tut\n");
		*trm = (t_tetris*)malloc(sizeof(t_tetris));
		(*trm)->head = *trm;
		(*trm)->pos = (char**)malloc(sizeof(char*)*k);
		(*trm)->next = NULL;
		//printf("ya tut\n");
	}
	else
	{
		//printf("dudu\n");
		(*trm)->next = (t_tetris*)malloc(sizeof(t_tetris));
		//printf("aaaa\n");
		//write(1, "G", 1);
		(*trm)->next->head = (*trm)->head;
		(*trm) = (*trm)->next;
		(*trm)->pos = (char**)malloc(sizeof(char*)*k);
		(*trm)->next = NULL;
	}
	while (j != k)
	{
		res = improve_width(buf);
		//printf("res = %i\n", res);
		(*trm)->pos[j] = (char*)malloc(sizeof(char) * res);
		(*trm)->pos[j][res - 1] = '\0';
		j++;
		//printf("aaaaaaa\n");
	}
	return (write_in_list(buf, trm));
}

char **create_map(int size)
{
	char **map;
	int i;

	i = 0;
	printf("create_map 0\n");
	map = (char**)malloc(sizeof(char*)* (size + 1));
	while (i <= size)
	{
		map[i] = (char*)malloc(sizeof(char) * (size + 1));
		i++;
	}
	printf("create_map 1\n");
	return (map);
}

char **write_dots(char **map, int size)
{
	int i;
	int j;
	printf("write_dots 0\n");
	j = 0;
	while (j != size)
	{
		i = 0;
		while (i != size)
		{
			map[j][i] = '.';
			i++;
		}
		printf("write_dots -> [%i][%i]\n", j, i);
		map[j][i] = '\0';
		j++;
	}
	map[j][0] = '\0';
	printf("write_dots - size = %i\n", size);
	printf("write_dots 1\n");
	//проверка
	i = 0;
	while (i <= size - 1)
	{
		printf("%s\n", map[i]);
		i++;
	}
	return (map);
}

void del_all_pos(char ***map, char set)
{
	int i;
	int j;

	j = 0;
	printf("del_all_pos 0\n");
	while ((*map)[j][0] != '\0')
	{
		i = 0;
		while ((*map)[j][i] != '\0')
		{
			if ((*map)[j][i] == set)
			{
				(*map)[j][i] = '.';
			}
			i++;
		}
		j++;
	}
	printf("del_all_pos 1\n");
}

int write_pos(char ***map, char **trm, t_cord *cord, char set)
{//это тоже надо изменить
	int i;
	int size;
	int j;
	printf("write_pos 0\n");
	j = 0;
	size = 0;
	while ((*map)[0][size] != '\0')
		size++;
	if (((*map)[(*cord).map_y][(*cord).map_x] != '.'))
	{
		printf("write_pos 0.1\n");
		(*cord).map_x++;
		if ((*cord).map_x == size)
		{
			(*cord).map_x = 0;
			(*cord).map_y++;
		}
		return (0);
	}
	else  
	//if (trm[(*cord).trm_y][(*cord).trm_x] == '#')
	{
		printf("cord.trm_y = %i\n", (*cord).trm_y);
		printf("cord.trm_x = %i\n", (*cord).trm_x);
		printf("yay\n");
		(*map)[(*cord).map_y][(*cord).map_x] = set;
		(*cord).map_x++;
		if ((*cord).map_x == size)
		{
			(*cord).map_x = 0;
			(*cord).map_y++;
		}
		//printf("write_pos 1.1\n");
	}
	/*(*cord).trm_x++;
	if ((*cord).trm_x == 4)
	{
		(*cord).trm_x = 0;
		(*cord).trm_y++;
	}*/
	printf("write_pos 2.1\n");
	return (1);
}

int check_put_tetrimo(char **map, t_tetris *trm, char set)
{
	int size;
	t_cord cord;
	//int j;

	//j = 0;
	size = 0;
	cord.map_x = 0;
	cord.map_y = 0;
	cord.trm_x = 0;
	cord.trm_y = 0;
	printf("___size  =  %i\n", size);
	printf("x = %i   y = %i\n", trm->max_x, trm->max_y);
	printf("check_put_tetrimo 0\n");
	while (map[0][size] != '\0')
		size++;
	printf("|||size  =  %i\n", size);
	if (trm->max_x > size || trm->max_y > size)
		return (size + 1);
	else
	{// тут надо изменить
		while (cord.trm_y != size)
		{
			printf("cord.map_y = %i\n", cord.map_y);
			printf("cord.map_x = %i\n", cord.map_x);
			if (!(write_pos(&map, trm->pos, &cord, set)))
			{
				del_all_pos(&map, set);
				cord.trm_x++;
			}
			else
			{
				cord.trm_x++;
			}
			if (cord.trm_x == trm->max_x)
			{
				cord.trm_x = 0;
				cord.trm_y++;
			}
			printf("la_x = %i\n", cord.trm_x);
			printf("la_y = %i\n", cord.trm_y);
			printf("la_s = %i\n", size);
		}
		printf("check_put_tetrimo 1\n");
		printf("____%i\n", size);
		return (0); //size + 1
	}
}

void erase_map(char ***map)
{
	int i;
	printf("erase_map 0\n");
	i = 0;
	while ((*map)[i][0] != '\0')
	{
		printf("1\n");
		free((*map)[i]);
		i++;
	}
	free((*map)[i]);
	free((*map));
	printf("erase_map 1\n");
}

int put_tetrimo(char **map, t_tetris *trm)
{
	int size;
	int i;
	char set;
	printf("put_tetrimo 0\n");
	printf("Size -> %i\n", size);
	printf("trm->max_y -  %i\n", trm->max_y);
	for (int u = 0; u < trm->max_y; u++)
		printf("^%s^\n", trm->pos[u]);
	set = 'A';
	if ((size = check_put_tetrimo(map, trm, set)) != 0)
	{
		printf("SSIZE%i\n", size);
		erase_map(&map);
		map = write_dots(create_map(size), size);
		put_tetrimo(map, trm);
	}
	printf("%s\n", map[0]);
	printf("%s\n", map[1]);
	printf("%s\n", map[2]);
	printf("%s\n", map[3]);
	//write_tetrimo_in_map(map, trm, set);
	if (trm->next != NULL)
	{
		printf("_________________________________________________\n");
		put_tetrimo(map, trm->next);
	}
	printf("put_tetrimo 1\n");
	return (1);
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
		printf("main 0.5\n");
		if (c > 26)
		{
			ft_putstr("error\n");
			return (0);	
		}
    }
	//improve_tetrimo(&trm);
	c = put_tetrimo(write_dots(create_map(2), 2), trm);
    return (0);
}
/*
char **create_map(int size)
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
	return (map);
}

char **write_dots(char **map, int size)
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
	return (map);
}

void del_all_pos(char ***map, char set)
{
	int i;
	int j;

	j = 0;
	while ((*map)[j][0] != '\0')
	{
		i = 0;
		while ((*map)[j][i] != '\0')
		{
			if ((*map)[j][i] == set)
			{
				(*map)[j][i] = '.';
			}
		}
		j++;
	}
}

int write_pos(char ***map, char **trm, t_cord *cord, char set)
{
	int i;
	int size;
	int j;

	j = 0;
	size = 0;
	while ((*map)[0][size] != '\0')
		size++;
	if (((*cord).x >= size || (*cord).y >= size) || ((*map)[(*cord).y][(*cord).y] != '.'))
	{
		return (0);
	}
	else if (trm[(*cord).y][(*cord).x] == '#')
	{
		(*map)[(*cord).y][(*cord).y] = set;
		return (1);
	}
	return (1);
}

int check_put_tetrimo(char **map, t_tetris *trm, char set)
{
	int size;
	t_cord cord;
	int i;
	int j;
//вроде сделал
	j = 0;
	i = 0;
	size = 0;
	cord.x = 0;
	cord.y = 0;
	while (map[size + 1] != '\0')
		size++;
	if (trm->max_x > size || trm->max_y > size)
		return (size + 1);
	else
	{
		while (cord.y <= size)
		{
			if (!(write_pos(&map, trm->pos, &cord, set)))
			{
				del_all_pos(&map, set);
				i = 0;
			}
			else
			{
				i++;
				cord.x++;
			}
			if (cord.x == 4)
			{
				cord.x = 0;
				cord.y++;
			}
		}
		return (size + 1);
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

int put_tetrimo(char **map, t_tetris *trm)
{
	int size;
	int i;
	char set;

	set = 'A';
	if ((size = check_put_tetrimo(map, trm, set)) != 0)
	{
		erase_map(map);
		map = write_dots(create_map(size), size);
		put_tetrimo(map, trm);
	}
	//write_tetrimo_in_map(map, trm, set);
	if (trm->next != NULL)
		put_tetrimo(map, trm->next);
	return (1);
}*/