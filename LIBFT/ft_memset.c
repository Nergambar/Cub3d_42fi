/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 14:07:00 by negambar          #+#    #+#             */
/*   Updated: 2023/10/09 14:24:48 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/
void	*ft_memset(void *s, int c, int n)
{
	unsigned char	*test;
	int				i;

	i = 0;
	test = (unsigned char *)s;
	while (i < n)
	{
		test[i] = (unsigned char)c;
		i++;
	}
	return (s);
}

/*int main()
{
	char dst[6];
	char src[] = "jello!";
	size_t n = ft_strlen(src);
	ft_memset(dst, 'j', n);
	printf("%s", dst);

	return 0;
}*/
