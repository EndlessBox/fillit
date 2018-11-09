/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:11:33 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 20:14:41 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		verify_dashes(t_tlist *tetrim)
{
	int	dashes;
	int	jumper;
	int hopper;

	while (tetrim)
	{
		dashes = 0;
		jumper = -1;
		while (tetrim->teter[++jumper])
		{
			hopper = -1;
			while (tetrim->teter[jumper][++hopper])
				if (tetrim->teter[jumper][hopper] == tetrim->c)
					dashes++;
		}
		if (dashes != 4)
			return (0);
		tetrim = tetrim->next;
	}
	return (1);
}

int		verify_points(t_tlist *tetrim)
{
	int	points;
	int	jumper;
	int hopper;

	while (tetrim)
	{
		points = 0;
		jumper = -1;
		while (tetrim->teter[++jumper])
		{
			hopper = -1;
			while (tetrim->teter[jumper][++hopper])
				if (tetrim->teter[jumper][hopper] == '.')
					points++;
		}
		if (points != 12)
			return (0);
		tetrim = tetrim->next;
	}
	return (1);
}

int		verify_neighbors(t_tlist *tetrim)
{
	int counter;
	int jumper;
	int hopper;

	jumper = 0;
	hopper = 0;
	while (tetrim)
	{
		counter = 0;
		verify_neighbors2(tetrim, &counter, jumper, hopper);
		if (counter != 8 && counter != 6)
			return (0);
		tetrim = tetrim->next;
	}
	return (1);
}

void	verify_neighbors2(t_tlist *tetrim, int *counter, int jumper, int hopper)
{
	jumper = -1;
	while (tetrim->teter[++jumper])
	{
		hopper = -1;
		while (tetrim->teter[jumper][++hopper])
		{
			if (tetrim->teter[jumper][hopper] == tetrim->c)
			{
				if (jumper - 1 >= 0 && jumper - 1 < 4 &&
					tetrim->teter[jumper - 1][hopper] == tetrim->c)
					(*counter)++;
				if (jumper + 1 >= 0 && jumper + 1 < 4 &&
					tetrim->teter[jumper + 1][hopper] == tetrim->c)
					(*counter)++;
				if (hopper + 1 >= 0 && hopper + 1 < 4 &&
					tetrim->teter[jumper][hopper + 1] == tetrim->c)
					(*counter)++;
				if (hopper - 1 >= 0 && hopper - 1 < 4 &&
					tetrim->teter[jumper][hopper - 1] == tetrim->c)
					(*counter)++;
			}
		}
	}
}

int		verify_counting(char *line)
{
	int jumper;
	int counter;

	jumper = -1;
	counter = 0;
	while (line[++jumper])
	{
		if (line[jumper] == '#' || line[jumper] == '.')
			counter++;
		else
		{
			return (0);
		}
	}
	if (counter == 4)
		return (1);
	else
	{
		return (0);
	}
}
