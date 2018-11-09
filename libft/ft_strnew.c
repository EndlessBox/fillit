/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/06 20:59:26 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/02 16:31:31 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char			*new_string;
	unsigned int	jumper;

	jumper = 0;
	if ((new_string = (char*)malloc(size + 1)))
	{
		new_string[0] = 'y';
		while (jumper <= size)
		{
			new_string[jumper] = '\0';
			jumper++;
		}
		return (new_string);
	}
	else
		return (NULL);
}
