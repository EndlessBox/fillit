/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 15:29:39 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 20:15:51 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	show_tetrisa(char **tetrisa)
{
	int jumper;

	jumper = -1;
	while (tetrisa[++jumper])
	{
		ft_putendl(tetrisa[jumper]);
	}
}

void	first_allocation(t_tlist **tempo)
{
	if (!((*tempo) = (t_tlist*)malloc(sizeof(t_tlist))))
		return ;
	if (!((*tempo)->teter = (char**)malloc(sizeof(char*) * 5)))
		return ;
	((*tempo)->teter)[4] = NULL;
	(*tempo)->next = NULL;
	if (!((*tempo)->pos = (int**)malloc(sizeof(int*) * 2)))
		return ;
	if (!((*tempo)->pos[0] = (int*)malloc(sizeof(int) * 4)))
		return ;
	if (!((*tempo)->pos[1] = (int*)malloc(sizeof(int) * 4)))
		return ;
}

int		check_line(t_tlist **tempo, char **holder, int *jumper, int *counter)
{
	if ((*holder)[0] != '\0')
		return (0);
	lst_creation(&((*tempo)->next));
	(*tempo) = (*tempo)->next;
	(*jumper) = 0;
	(*counter) = 0;
	return (1);
}

int		read_tetrim(int fd, t_tlist *tempo, char c, int *jumper)
{
	char	*holder;
	int		counter;

	counter = 0;
	while (get_next_line(fd, &holder))
	{
		if (counter == 4)
		{
			if (check_line(&tempo, &holder, jumper, &counter) == 0)
				return (0);
			c++;
		}
		else
		{
			if (verify_counting(holder) == 0)
				return (0);
			tempo->c = c;
			(tempo->teter)[(*jumper)] =
				ft_strjoin((tempo->teter)[(*jumper)], holder);
			replace((char**)&tempo->teter[(*jumper)++], c);
			counter++;
		}
	}
	return (1);
}

int		is_it_possible(char **tetr, int x, int y, t_tlist *tet)
{
	int	checker;
	int	si;

	checker = 0;
	si = ft_strlen(tetr[0]);
	if (x + tet->pos[0][0] >= si || x + tet->pos[0][0] < 0 ||
		x + tet->pos[0][1] >= si || x + tet->pos[0][1] < 0 ||
		x + tet->pos[0][2] >= si || x + tet->pos[0][2] < 0 ||
		x + tet->pos[0][3] >= si || x + tet->pos[0][3] < 0 ||
		y + tet->pos[1][0] >= si || y + tet->pos[1][0] < 0 ||
		y + tet->pos[1][1] >= si || y + tet->pos[1][1] < 0 ||
		y + tet->pos[1][2] >= si || y + tet->pos[1][2] < 0 ||
		y + tet->pos[1][3] >= si || y + tet->pos[1][3] < 0)
		return (0);
	else if (tetr[x + tet->pos[0][0]][y + tet->pos[1][0]] == '.'
			&& tetr[x + tet->pos[0][1]][y + tet->pos[1][1]] == '.'
			&& tetr[x + tet->pos[0][2]][y + tet->pos[1][2]] == '.'
			&& tetr[x + tet->pos[0][3]][y + tet->pos[1][3]] == '.')
		return (1);
	else
		return (0);
}
