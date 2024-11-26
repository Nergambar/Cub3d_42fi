/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:46:47 by negambar          #+#    #+#             */
/*   Updated: 2024/11/26 10:46:12 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

int	ft_strrchr2(char *s, char *c)
{
	int i;
	int j;
	int count;

	j = 0;
	count = ft_strlen(c);
	i = 0;
	while (s[i])
	{
		if (s[i] == c[j])
			j++;
		i++;
	}
	if (j == count)
		return (1);
	else
		return (printf("ERROR"), 0);
}

size_t	get_height(char *av)
{
    size_t i;
    char *line;
    int fd;

	i = 0;
	fd = open(av, O_RDONLY);
    if (fd == -1)
        return 0;

    while ((line = get_the_line(fd)))
    {
        i++;
        free(line);
    }
    close(fd);
    return i;
}

size_t	get_max_width(char *av)
{
	size_t	j;
	size_t 	len;
	int		fd;
	char *s;

	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	j = 0;
	while ((s = get_the_line(fd)))
	{
		len = ft_strlen(s);
		if (len > j)
			j = len;
		free(s);
	}
	close(fd);+
	return (j);
}