/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:37:14 by negambar          #+#    #+#             */
/*   Updated: 2023/10/26 13:01:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

#include <stdlib.h>
#include <string.h>

static int	len(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int nb)
{
	int		nlen;
	char	*res;
	long	nbl;
	int		i;
	int		j;

	nbl = nb;
	nlen = len(nbl);
	i = 0;
	j = nlen - 1;
	res = malloc(nlen + 1);
	if (!res)
		return (NULL);
	if (nbl < 0)
	{
		res[i++] = '-';
		nbl = -nbl;
	}
	while (i++ < nlen)
	{
		res[j--] = (char)(nbl % 10) + '0';
		nbl /= 10;
	}
	res[i - 1] = '\0';
	return (res);
}

/*
#include <stdio.h>
int iain()
{
	int n = -110;
	char *r = ft_itoa(n);

	printf("%s", r);
}*/
