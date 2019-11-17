/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgalt <mgalt@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:01:39 by mgalt             #+#    #+#             */
/*   Updated: 2019/11/17 19:16:46 by damerica         ###   ########.fr       */
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

int			check2(char	*s)
{
	int		i;
	int		n;

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
	if (n >= 6)
		return (1);
	return (0);
}

int			check1(char *s)
{
	int		i;
	int		n;

	i = 0;
	n = 0; 
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

int			improve_length(char *buf)
{
	int i;
	int count;
	int result;

	result = 4;
	count = 0;
	i = 0;
	while (i < 20)
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
	return (result);
}

int			improve_width(char *buf)
{
	int i;
	int count;
	int result;

	result = 4;
	count = 0;
	i = 0;
	while (i != 4)
	{
		while (i <= 19)
		{
			if (buf[i] == '.')
				count++;
			i = i + 5;
		}
		if (count == 4)
		{
			result--;
		}
		count = 0;
		i = i - 19;
	}
	if (result == 0)
		return (0);
	return (result + 1);
}

int			dot(char *buf, int i1)
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
			count++;
		if (i1 - 10 >= 0 && buf[i1 - 10] == '.')
			count++;
		if (i1 - 15 >= 0 && buf[i1 - 15] == '.')
			count++;
		if (i1 + 5 <= 19 && buf[i1 + 5] == '.')
			count++;
		if (i1 + 10 <= 19 && buf[i1 + 10] == '.')
			count++;
		if (i1 + 15 <= 19 && buf[i1 + 15] == '.')
			count++;
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
	if (count == 3 || count1 == 4)
		return (0);
	else
		return (1);
}

t_tetris	*write_in_list(char *buf, t_tetris **trm)
{
	int i;
	int j;
	int i1;
	int k;

	k = 0;
	i1 = 0;
	j = 0;
	(*trm)->max_y = improve_length(buf);
	(*trm)->max_x = improve_width(buf) - 1;
	while (i1 < 21 && buf[i1] != '\0')
	{
		i = 0;
		while ((buf[i1] != '\n' && i1 < 21) || (buf[i1] != '\n' && buf[i1 + 1] != '\n'))
		{
			if (dot(buf, i1))
			{
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
	}
	return((*trm)->next);
}

t_tetris *create_list(char *buf, t_tetris **trm)
{
	int j;
	int res;
	j = 0;
	int k;
	k = improve_length(buf);
	if (!(*trm))
	{
		*trm = (t_tetris*)malloc(sizeof(t_tetris));
		(*trm)->head = *trm;
		(*trm)->pos = (char**)malloc(sizeof(char*)*k);
		(*trm)->next = NULL;
	}
	else
	{
		(*trm)->next = (t_tetris*)malloc(sizeof(t_tetris));
		(*trm)->next->head = (*trm)->head;
		(*trm) = (*trm)->next;
		(*trm)->pos = (char**)malloc(sizeof(char*)*k);
		(*trm)->next = NULL;
	}
	while (j != k)
	{
		res = improve_width(buf);
		(*trm)->pos[j] = (char*)malloc(sizeof(char) * res);
		(*trm)->pos[j][res - 1] = '\0';
		j++;
	}
	return (write_in_list(buf, trm));
}

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
	while (j != size)
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
			i++;
		}
		j++;
	}
}

void erase_map(char ***map)
{
	int i;
	i = 0;
	while ((*map)[i][0] != '\0')
	{
		free((*map)[i]);
		i++;
	}
	free((*map)[i]);
	free((*map));
}

int put_figure(t_tetris *trm, char ***map, t_cord *coords, char set)
{
	int x;
	int y;

	y = 0;
	while (trm->max_y > y)
	{
		x = -1;
		while (trm->max_x > ++x)
		{
			if (((*map)[coords->map_y + y] == NULL && trm->pos[y] != NULL) ||
			((*map)[coords->map_y + y][coords->map_x + x] == '\0' &&
			trm->pos[y][x] == '#') ||
			((*map)[coords->map_y + y][coords->map_x + x] != '.' &&
			trm->pos[y][x] == '#'))
			{
				del_all_pos(map, set);
				return (0);
			}
			if ((*map)[coords->map_y + y][coords->map_x + x] == '.' &&
					trm->pos[y][x] == '#')
			{
				(*map)[coords->map_y + y][coords->map_x + x] = set;
			}
		}
		y++;
	}
	return (1);
}

int find_pos(t_tetris *trm, char ***map, t_cord **coords, char set)
{
	int ans;

	while ((*map)[(*coords)->map_y][0] != '\0')
	{
		while ((*map)[(*coords)->map_y][(*coords)->map_x])
		{
			if ((ans = put_figure(trm, map, *coords, set)) == 1)
			{
				return (1);
			}
			(*coords)->map_x++;
		}
		(*coords)->map_x = 0;
		(*coords)->map_y++;
	}
	if (ans == 0)
	{
		return (0);
	}
	return (1);
}

int put_tetrimo(t_tetris *trm, char ***map, t_cord *coords, char set)
{
	int ans;
	
	if (trm == NULL)
	{
		return (1);
	}
	if (coords == NULL)
	{
		coords = malloc(sizeof(t_cord));
		coords->map_x = 0;
		coords->map_y = 0;
	}
	if (!(find_pos(trm, map, &coords, set)))
	{
		free(coords);
		coords = NULL;
		return (0);
	}
	ans = put_tetrimo(trm->next, map, NULL, set + 1);
	if (ans == 0)
	{
		del_all_pos(map, set);
		coords->map_x++;
		return(put_tetrimo(trm, map, coords, set));
	}
	free(coords);
	return (1);
}

void clean_trm(t_tetris **trm)
{
	t_tetris *k;
	int i;
	printf("%i\n", (*trm)->max_y);
	while ((*trm))
	{
		i = 0;
		printf("hey\n");
		k = (*trm)->next;
		while (i < (*trm)->max_y)
		{
			printf("ololo\n");
			free((*trm)->pos[i]);
			i++;
		}
		printf("eee\n");
		free((*trm)->pos);
		free(*trm);
		*trm = k;
	}
}

char **solution_map(t_tetris *trm)
{
	char **map;
	int size;
	char set;

	size = 2;
	set = 'A';
	map = write_dots(create_map(size), size);
	while ((put_tetrimo(trm, &map, NULL, set) == 0))
	{
		size++;
		erase_map(&map);
		map = write_dots(create_map(size), size);
	}
	clean_trm(&trm);
	return (map);
}

void print_map(char **map)
{
	int i;
	//printf("hey\n");
	i = 0;
	while (map[i][0] != '\0')
	{
		//printf("i = %i\n", i);
		ft_putstr(map[i]);
		ft_putchar('\n');
		i++;
	}
}

/*void clean_map(char **map)
{
	int i;
	//printf("hey\n");
	i = 0;
	while (map[i][0] != '\0')
	{
		printf("i = %i\n", i);
		free(map[i]);
		i++;
	}
	free(map);
}*/

int     main(int ac, char **av)
{
    int     fd;
    char    buf[23];
    int     n;
	int		ret;
	int		ret2;
	int		c; //кол-во вызовов read
	t_tetris *trm;
	char **map;

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
        	ret = check1(buf);
			if (ret == 1)
				ret2 = check2(buf);
			if (ret2 != 1)
			{
				ft_putstr("error\n");
				return (0);
			}
			c++;
			create_list(buf, &trm);
		}
		trm = trm->head;
		//int a = scanf("%i", &a);
		if (c > 26)
		{
			ft_putstr("error\n");
			return (0);	
		}
    }
    map = solution_map(trm);
	print_map(map);
	erase_map(&map);
	//printf("^%s\n", map[0]);
	//printf("^%s\n", map[1]);
	//printf("^%s\n", map[2]);
	//printf("^%s\n", map[3]);
	//printf("^%s\n", map[4]);
	//printf("^%s\n", map[5]);
	//printf("^%s\n", map[6]);
	int a = scanf("%i", &a);
	return (0);
}

