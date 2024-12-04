/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 12:01:09 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 12:15:41 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
/*#include <stdio.h>*/

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	lend;
	size_t	lens;
	size_t	i;

	lend = 0;
	lens = 0;
	i = 0;
	while (dst[lend] && lend < size)
		lend++;
	while (src[lens])
		lens++;
	if (lend < size)
	{
		while (i < lens && lend + i < size - 1)
		{
			dst[lend + i] = src[i];
			i++;
		}
		dst[lend + i] = '\0';
	}
	return (lend + lens);
}
/*
int main(int ac, char **av)
{
	if (ac == 3)
	{
		size_t size = ft_strlen(av[1]) + ft_strlen(av[2]);
		printf("%zu", ft_strlcat(av[1], av[2], size));
	}
}*/
