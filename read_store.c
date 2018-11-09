/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_store.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:15:11 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 18:33:51 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	lst_creation(t_tlist **new)
{
	int	jumper;

	jumper = 0;
	if (!((*new) = (t_tlist*)malloc(sizeof(t_tlist))))
		return ;
	if (!((*new)->teter = (char**)malloc(sizeof(char*) * 5)))
		return ;
	if (!((*new)->pos = (int**)malloc(sizeof(int*) * 2)))
		return ;
	if (!((*new)->pos[0] = (int*)malloc(sizeof(int) * 4)))
		return ;
	if (!((*new)->pos[1] = (int*)malloc(sizeof(int) * 4)))
		return ;
	jumper = 0;
	((*new)->teter)[4] = NULL;
	(*new)->next = NULL;
	while (jumper < 4)
	{
		if (!(((*new)->teter)[jumper] = ft_strnew(5)))
			return ;
		jumper++;
	}
	(*new)->next = NULL;
}

void	replace(char **line, char c)
{
	int	jumper;

	jumper = 0;
	while ((*line)[jumper])
	{
		if ((*line)[jumper] == '#')
			(*line)[jumper] = c;
		jumper++;
	}
}

int		count_teter(t_tlist *list)
{
	int	counter;

	counter = 0;
	while (list)
	{
		counter++;
		list = list->next;
	}
	return (counter);
}

int		read_store(t_tlist **tetrim, int fd)
{
	int			jumper;
	t_tlist		*tempo;
	char		c;
	int			counter;

	c = 'A';
	first_allocation(&tempo);
	jumper = -1;
	while (++jumper < 4)
	{
		(tempo->teter)[jumper] = ft_strnew(5);
		(tempo->teter)[jumper][4] = '\0';
	}
	*tetrim = tempo;
	jumper = 0;
	counter = 0;
	if (read_tetrim(fd, tempo, c, &jumper) == 0)
		return (0);
	return (1);
}
