/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 11:34:15 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 11:44:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, int n)
{
	char	*d;
	char	*s;
	int		i;

	d = (char *)dest;
	s = (char *)src;
	i = 0;
	if (d == NULL && s == NULL)
		return (NULL);
	while (n > 0)
	{
		if (d > s)
			d[n - 1] = s[n - 1];
		else
			d[i] = s[i];
		n--;
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
	ft_memmove(dst, src, n);
	printf("%s", dst);

	return 0;
}
*/
