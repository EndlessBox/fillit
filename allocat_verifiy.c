/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocat_verifiy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 16:47:33 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 20:25:38 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		allocat(t_tlist *tetriminosa)
{
	int jumper;
	int saver;

	jumper = 0;
	saver = count_teter(tetriminosa) * 4;
	while ((jumper * jumper) < saver)
		jumper++;
	return (jumper);
}

void	get_relatives(t_tlist **tempo)
{
	int ct;
	int jumper;
	int hopper;

	ct = 0;
	jumper = -1;
	while (++jumper < 4)
	{
		hopper = -1;
		while (++hopper < 4)
		{
			if (((*tempo)->teter)[jumper][hopper] == (*tempo)->c && ct == 0)
			{
				((*tempo)->pos)[0][ct] = jumper;
				((*tempo)->pos)[1][ct++] = hopper;
			}
			else if (((*tempo)->teter)[jumper][hopper] == (*tempo)->c)
			{
				((*tempo)->pos)[0][ct] = jumper - ((*tempo)->pos)[0][0];
				((*tempo)->pos)[1][ct++] = hopper - ((*tempo)->pos)[1][0];
			}
		}
	}
	((*tempo)->pos)[0][0] = 0;
	((*tempo)->pos)[1][0] = 0;
}

void	relative_position(t_tlist **teterm)
{
	t_tlist		*tempo;

	if (!(tempo = (t_tlist*)malloc(sizeof(t_tlist))))
		return ;
	tempo = (*teterm);
	while (tempo)
	{
		get_relatives(&tempo);
		tempo = tempo->next;
	}
}
