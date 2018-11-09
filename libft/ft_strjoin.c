/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybouladh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 16:05:40 by ybouladh          #+#    #+#             */
/*   Updated: 2018/11/03 14:20:01 by ybouladh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		s1l;
	int		s2l;
	int		jumper;
	int		hopper;

	s1l = ft_strlen(s1);
	s2l = ft_strlen(s2);
	if ((result = (char*)malloc(sizeof(char) * (s1l + s2l + 1))))
	{
		jumper = -1;
		while (s1[++jumper])
			result[jumper] = s1[jumper];
		hopper = 0;
		while (s2[hopper])
			result[jumper++] = s2[hopper++];
		result[jumper] = '\0';
		return (result);
	}
	else
		return (NULL);
}
