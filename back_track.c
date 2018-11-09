/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_track.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 17:22:41 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 15:04:31 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_it(int jumper, int hopper, char ***tetr, t_tlist *tet)
{
	(*tetr)[jumper + tet->pos[0][0]][hopper + tet->pos[1][0]] = tet->c;
	(*tetr)[jumper + tet->pos[0][1]][hopper + tet->pos[1][1]] = tet->c;
	(*tetr)[jumper + tet->pos[0][2]][hopper + tet->pos[1][2]] = tet->c;
	(*tetr)[jumper + tet->pos[0][3]][hopper + tet->pos[1][3]] = tet->c;
}

void	delete_it(int jumper, int hopper, char ***tetr, t_tlist *tet)
{
	(*tetr)[jumper + tet->pos[0][0]][hopper + tet->pos[1][0]] = '.';
	(*tetr)[jumper + tet->pos[0][1]][hopper + tet->pos[1][1]] = '.';
	(*tetr)[jumper + tet->pos[0][2]][hopper + tet->pos[1][2]] = '.';
	(*tetr)[jumper + tet->pos[0][3]][hopper + tet->pos[1][3]] = '.';
}

void	double_allocation(char ***tetr, int si)
{
	int jumper;
	int hopper;

	(*tetr) = (char**)malloc(sizeof(char*) * si + 1);
	(*tetr)[si] = NULL;
	jumper = 0;
	while (jumper < si)
	{
		(*tetr)[jumper] = (char*)malloc(sizeof(char) * si + 1);
		(*tetr)[jumper][si] = '\0';
		hopper = 0;
		while (hopper < si)
		{
			(*tetr)[jumper][hopper] = '.';
			hopper++;
		}
		jumper++;
	}
}

int		back_track(t_tlist *tet, char ***tetr)
{
	int jumper;
	int hopper;

	if (!tet)
		return (1);
	jumper = -1;
	while ((*tetr)[++jumper])
	{
		hopper = -1;
		while ((*tetr)[jumper][++hopper])
		{
			if (is_it_possible((*tetr), jumper, hopper, tet) == 1)
			{
				put_it(jumper, hopper, tetr, tet);
				if (back_track(tet->next, tetr) == 1)
					return (1);
				else
				{
					delete_it(jumper, hopper, tetr, tet);
				}
			}
		}
	}
	return (0);
}

void	squirt(char ***tetr, t_tlist *tet, int si)
{
	double_allocation(tetr, si);
	if (!back_track(tet, tetr))
		squirt(tetr, tet, si + 1);
}
