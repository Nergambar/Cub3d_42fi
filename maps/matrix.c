/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:53:12 by negambar          #+#    #+#             */
/*   Updated: 2024/12/04 11:01:42 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

static char	**mtx_init(char **av, int fd)
{
	char	**copy;
	int		i;
	int		height;
	int		width;
	char	*line;

	height = get_height(av[1]);
	width = get_max_width(av[1]);
	if (!height || !width)
		return (NULL);
	copy = (char **)ft_calloc((height + 1), sizeof(char *));
	if (!copy)
		return (NULL);
	i = 0;
	line = get_the_line(fd);
	while (line != NULL)
	{
		copy[i] = ft_strdup(line);
		i++;
		free(line);
		line = get_the_line(fd);
	}
	free(line);
	return (copy);
}

char	*get_the_line(int fd)
{
	char	*str;
	char	*tmp;
	size_t	len;

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

char	**mtxdup(char **av, int fd)
{
	char	**copy;

	if (!ft_strrchr2(av[1], ".cub"))
		return (NULL);
	copy = mtx_init(av, fd);
	if (!copy)
		return (NULL);
	return (copy);
}

static void	printfchecks(t_details dets, t_textures txt)
{
	printf("NO:%s\n", dets.no);
	printf("SO:%s\n", dets.so);
	printf("WE:%s\n", dets.we);
	printf("EA:%s\n", dets.ea);
	if (txt.c && txt.f)
	{
		printf("F:%d\n", txt.f);
		printf("C:%d\n", txt.c);
	}
}

static char	**initial_checks(char **av, int fd, \
	t_details *dets, t_sprites *sp)
{
	char	**mtx;
	int		t;

	mtx = NULL;
	mtx = mtxdup(av, fd);
	if (!mtx)
		return (NULL);
	t = mtx_trim(mtx);
	if (!check_extras(mtx, dets, sp, t))
		return (NULL);
	return (mtx);
}
int main(int ac, char **av)
{
	char **mtx;
	int fd;
	int i;
	int trimmed;
	t_sprites sp;
	t_details dets;
	t_textures txt;

	trimmed = 0;
	init_attrs(&dets, &sp);
	if (ac == 1)
		return (0);
	fd = open("test.cub", O_RDONLY);
	if (fd < 0)
		return(printf("ERROR\n"), 1);
	mtx = initial_checks(av, fd, &dets, &sp);
	if (!mtx)
		return (printf("ERROR\n"), freemtx(mtx), 1);
	mtx = map_mtx(mtx, av[1]);
	i = -1;
	while (mtx[++i])
		printf	("%s\n", mtx[i]);
	if (!set_colors(&txt, &dets))
		return (printf("ERROR\n"), 1);
	printfchecks(dets, txt);
	closeall()
}
