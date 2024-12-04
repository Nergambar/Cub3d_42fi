/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 15:58:23 by negambar          #+#    #+#             */
/*   Updated: 2023/10/11 16:12:27 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*#include <stdio.h>*/

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*str1;
	const unsigned char	*str2;
	size_t				i;

	str2 = (const unsigned char *)s2;
	str1 = (const unsigned char *)s1;
	i = 0;
	while (i < n && str1[i] == str2[i])
	{
		i++;
	}
	if (i == n)
	{
		return (0);
	}
	return (str1[i] - str2[i]);
}

/*
int main() {
  char str1[] = "Hello";
  char str2[] = "World";

  // Compare the two strings
  int result = memcmp(str1, str2, sizeof(str1));

  // If the two strings are equal, print "The strings are equal".
  if (result == 0) {
    printf("The strings are equal\n");
  } else if (result < 0) {
    printf("The first string is less than the second string\n");
  } else {
    printf("The first string is greater than the second string\n");
  }

  return 0;
}

*/
