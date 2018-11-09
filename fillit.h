/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 14:03:08 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/09 20:18:15 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FILLIT_H
# define H_FILLIT_H
# include "./GNL/get_next_line.h"
# include "./libft/libft.h"

typedef struct			s_tlist
{
	char				**teter;
	char				c;
	int					**pos;
	struct s_tlist		*next;
}						t_tlist;
int						read_store(t_tlist **tetrim, int fd);
void					lst_creation(t_tlist **new);
void					replace(char **line, char c);
int						count_teter(t_tlist *list);
int						allocat(t_tlist *tetriminosa);
void					relative_position(t_tlist **teterm_list);
int						back_track(t_tlist *tetrim, char ***tetrisa);
void					squirt(char ***tetrisa, t_tlist *tetrim, int size);
int						verify_dashes(t_tlist *tetrim);
int						verify_points(t_tlist *tetrim);
int						verify_neighbors(t_tlist *tetrim);
void					verify_neighbors2(t_tlist *tetrim, int *counter,
						int jumper, int hopper);
int						verify_counting(char *line);
void					show_tetrisa(char **tetrisa);
int						is_it_possible(char **tetr, int x, int y, t_tlist *tet);
int						read_tetrim(int fd, t_tlist *tempo,
						char c, int *jumper);
void					first_allocation(t_tlist **tempo);
int						check_line(t_tlist **tempo, char **holder,
						int *jumper, int *counter);
int						read_tetrim(int fd, t_tlist *tempo,
						char c, int *jumper);

#endif
