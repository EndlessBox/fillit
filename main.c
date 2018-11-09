/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:20:12 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 15:06:49 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char **argv)
{
	int				fd;
	static t_tlist	*tetriminosa;
	char			**tetrisa;

	if (argc != 2)
	{
		ft_putendl("usage : ./fillit source_file");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (read_store(&tetriminosa, fd) == 0 ||
		verify_neighbors(tetriminosa) != 1 ||
		verify_points(tetriminosa) != 1 || verify_dashes(tetriminosa) != 1)
	{
		ft_putendl("error");
		return (0);
	}
	relative_position(&tetriminosa);
	squirt(&tetrisa, tetriminosa, allocat(tetriminosa));
	show_tetrisa(tetrisa);
	close(fd);
	return (0);
}
