/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 17:02:53 by negambar          #+#    #+#             */
/*   Updated: 2024/11/23 12:34:28 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft.h"
#include <stdio.h>

int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
	}
	return (count);
}

char	*new(const char *s, char c, int start)
{
	char	*word;
	int		i;
	int		cpy;

	i = 0;
	cpy = start;
	while (s[start] && s[start] != c)
	{
		i++;
		start++;
	}
	word = malloc(sizeof(char) * (i + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (s[cpy] && s[cpy] != c)
	{
		word[i] = s[cpy];
		i++;
		cpy++;
	}
	word[i] = '\0';
	return (word);
}

int	check(char **res, int i)
{
	if (!res[i])
	{
		while (i >= 0)
			free(res[i--]);
		free(res);
	}
	return (1);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;

	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c && (i == 0 || s[j - 1] == c))
		{
			res[i] = new(s, c, j);
			if (!res[i] && check(res, i))
				return (NULL);
			i++;
		}
		j++;
	}
	res[i] = NULL;
	return (res);
}
int main()
{
	char **tab;
	int i;

	tab = ft_split(" ", ' ');
	i = 0;
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
	return (0);
}