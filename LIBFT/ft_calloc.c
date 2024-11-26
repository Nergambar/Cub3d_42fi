/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 16:43:54 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 16:48:08 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, (int)nmemb * size);
	return (ptr);
}
/*
int main()
{
	int *array = ft_calloc(10, sizeof(int));
	int i = 0;

	while (i >= 0 && i < 10)
	{
		array[i] = 0;
		i++;
	}
	i = 0;
	while(i < 10)
	{
		printf("%d\n", array[i]);
		i++;
	}
}*/
