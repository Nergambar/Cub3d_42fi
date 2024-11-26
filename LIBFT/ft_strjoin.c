/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 15:36:06 by negambar          #+#    #+#             */
/*   Updated: 2023/10/12 15:43:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	copy_string(char *dest, const char *src, int start)
{
	size_t	i;

	i = start;
	while (src[i - start] != '\0')
	{
		dest[i] = src[i - start];
		i++;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*sf;
	int		i;

	i = 0;
	if (!s1)
		return (NULL);
	sf = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (sf)
	{
		i = copy_string(sf, s1, i);
		i = copy_string(sf, s2, i);
		sf[i] = '\0';
		return (sf);
	}
	return (NULL);
}
/*
int main(int ac, char **av)
{
	if (ac == 3)
	printf("%s", ft_strjoin(av[1], av[2]));
}*/
