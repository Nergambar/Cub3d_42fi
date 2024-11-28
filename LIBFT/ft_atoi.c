/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:30:13 by negambar          #+#    #+#             */
/*   Updated: 2024/11/28 11:30:35 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int check_spaces(char *str)
{
	int i;

	i = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	return (i);
}


static int check_for_alpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (-9999999);
	return (c);
}

int	ft_atoi(const char *nptr)
{
	int		i;
	int		sign;
	int		result;
	char	*str;

	str = (char *)nptr;
	i = 0;
	sign = 1;
	result = 0;
	i = check_spaces(str);
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (!check_for_alpha(str[i]))
			return (9999999);
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (sign * result);
}
/*
#include <stdio.h>
int main()
{
	char *str = " -42";
	printf("%d", ft_atoi(str));
}*/
