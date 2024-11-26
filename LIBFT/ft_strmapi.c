/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:21:07 by negambar          #+#    #+#             */
/*   Updated: 2023/10/20 17:34:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	to_uppercase(char c)
{
	if (c >= 'a' && c <= 'z')
		return ((char)(c - 32));
	return (c);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	l;
	char			*res;
	unsigned int	i;

	if (!s || !f)
		return (NULL);
	l = 0;
	i = 0;
	while (s[l])
		l++;
	res = (char *)malloc(l + 1);
	if (!res)
		return (NULL);
	while (i < l)
	{
		res[i] = f(i, s[i]);
		i++;
	}
	res[l] = '\0';
	return (res);
}
/*
#include <stdio.h>
int main()
{
	const char *input = "hello";
	char *res = ft_strmapi(input, to_uppercase);
	printf("%s\n%s", input, res);
}*/
