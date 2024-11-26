/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:52:32 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 15:48:58 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

void	*ft_memchr(const void *s, int c, int n)
{
	int				i;
	unsigned char	*str;
	unsigned char	character;

	str = (unsigned char *)s;
	character = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == character)
		{
			return (str + i);
		}
		i++;
	}
	return (NULL);
}

/*int main()
{
	char str[] = "Example string";
	char *pch = ft_memchr(str, 'p', ft_strlen(str));
	if (pch != NULL)
	{
		printf("'p' found at position %ld\n", pch - str + 1);
	}
	else
	{
		printf("'p' not found\n");
	}
}
*/
