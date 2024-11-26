/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 13:48:47 by negambar          #+#    #+#             */
/*   Updated: 2023/10/12 14:07:34 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*fun(unsigned int start, unsigned int lent, size_t len, const char *s)
{
	unsigned int	i;
	char			*str;

	i = 0;
	if (start >= lent)
	{
		str = (char *)malloc(1);
		if (str)
			str[0] = '\0';
		return (str);
	}
	if (len > lent - start)
		len = lent - start;
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	lent;

	lent = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	return (fun(start, lent, len, s));
}

/*int main() {
  char string[] = "Hello, world!";

  // Extract the substring "world" from the string "Hello, world!".
  char *substring = substr(string, 7, 5);

  // Print the substring to the console.
  printf("%s\n", substring);

  return 0;
}
*/
