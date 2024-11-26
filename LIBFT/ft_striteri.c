/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 17:45:52 by negambar          #+#    #+#             */
/*   Updated: 2023/10/20 17:53:04 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	touppercase(unsigned int i, char *c)
{
	while (c[i])
	{
		if (*c >= 'a' && *c <= 'z')
			*c = (char)(*c - 32);
		i++;
	}
}

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
/*
#include <stdio.h>
int main()
{
    char input[] = "hello!";
    ft_striteri(input, touppercase);

    printf("Modified string: %s\n", input);

    return 0;
}*/
