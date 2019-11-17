/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filit.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: damerica <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 19:32:52 by damerica          #+#    #+#             */
/*   Updated: 2019/10/30 22:20:33 by damerica         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_tetris
{
	char **pos;
	int max_x;
	int max_y;
	struct s_tetris *next;
	struct s_tetris *head;
}				t_tetris;

typedef struct	s_cord
{
	int map_x;
	int map_y;
}				t_cord;