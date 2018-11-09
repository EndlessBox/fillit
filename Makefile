# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/06 19:53:31 by ybouladh          #+#    #+#              #
#    Updated: 2018/11/07 12:08:56 by ybouladh         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

all: $(NAME)

$(NAME):
	gcc -Wall -Werror -Wextra -c ./libft/*.c ./GNL/*.c *.c
	gcc *.o -o $(NAME)

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re : fclean all
