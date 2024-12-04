/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:21:28 by negambar          #+#    #+#             */
/*   Updated: 2023/10/09 12:23:30 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	while (*s != (unsigned char)c && *s)
	{
		s++;
	}
	if (*s == (unsigned char)c)
	{
		return ((char *)s);
	}
	if ((unsigned char)c == '\0')
		return ((char *)s);
	return (NULL);
}
/*
#include <stdio.h>

int main()
{
	printf("%i", ft_strchr("teste", 'e'));
	
}*/
