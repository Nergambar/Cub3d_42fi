/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:11:20 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 11:15:11 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dst;
	unsigned char	*sr;

	dst = (unsigned char *)dest;
	sr = (unsigned char *)src;
	i = 0;
	if (dst == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		*(dst + i) = *(sr + i);
		i++;
	}
	return (dest);
}
/*
int main()
{
	char dst[6];
	char src[] = "jello!";
	size_t n = ft_strlen(src);
	ft_memcpy(dst, src, n);
	printf("%s", dst);

	return 0;
}*/
