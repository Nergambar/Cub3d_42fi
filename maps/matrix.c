/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:53:12 by negambar          #+#    #+#             */
/*   Updated: 2024/11/25 16:13:36 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**mtx_init(char **av, int fd)
{
	char **copy;
	int i;
	int height;
	int width;
	char *line;

	height = get_height(av[1]);
	width = get_max_width(av[1]);
	if(!height || !width)
		return (NULL);
	copy = (char **)ft_calloc((height + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	while ((line = get_the_line(fd)) != NULL)
	{
		copy[i] = ft_strdup(line);
		i++;
		free(line);
	}
	free(line);
	
	return (copy);
}

char	*get_the_line(int fd)
{
	char *str;
	char *tmp;
	size_t len;

	tmp = get_next_line(fd);
	if (!tmp)
		return (NULL);
	str = ft_strtrim(tmp, "\n");
	free(tmp);
	if (!str)
		return (NULL);
	len = ft_strlen(str);
	str[len] = '\0';
	return (str);
}

char **mtxdup(char **av, int fd)
{
	char **copy;

	if (!ft_strrchr2(av[1], ".ber"))
		return (NULL);
	copy = mtx_init(av, fd);
	if (!copy)
		return (NULL);
	return (copy);
}

int main(int ac, char **av)
{
	char **mtx;
	int fd;
	(void)ac;
	fd = open("test.ber", O_RDONLY);
	mtx = mtxdup(av, fd);
	int i = -1;
	while (mtx[++i])
	{
		printf("%s\n", mtx[i]);
	}
	close(fd);
	i = -1;
	while (mtx[++i])
	{
		free(mtx[i]);
	}
	free(mtx);
}