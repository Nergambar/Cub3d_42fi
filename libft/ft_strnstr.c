/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:24:55 by negambar          #+#    #+#             */
/*   Updated: 2023/10/26 12:04:20 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (*little == 0)
		return ((char *)big);
	while (big[i] && len > 0)
	{
		j = 0;
		while (little[j] == big[i + j]
			&& (i + j) < len && little[j] && big[i + j])
		{
			j++;
		}
		if (little[j] == '\0')
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
/*
int main()
{
	char *p = ft_strnstr("FF", "see FF your FF return FF now FF", 30);
	printf("%s", p);
}*/
