/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:53:12 by negambar          #+#    #+#             */
/*   Updated: 2025/01/14 13:15:38 by negambar         ###   ########.fr       */
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

static void	second_main(t_game *game)
{
	int	i;

	i = 0;
	init_game(game);
	mlx_hook(game->win, 17, 1L << 17, ft_close, game);
	mlx_hook(game->win, 2, 1L << 0, &key_press, game);
	mlx_hook(game->win, 3, 1L << 1, &key_release, &game->player);
	mlx_loop_hook(game->mlx, draw_loop, game);
	mlx_loop(game->mlx);
}

int	main(int ac, char **av)
{
	t_textures	txt;
	char		**mtx;
	int			trimmed;
	t_game		game;

	trimmed = 0;
	mtx = NULL;
	game.dets.mlx = mlx_init();
	// init_game(&game);
	init_attrs(&game);
	if (ac == 1)
		return (printf("ERROR\ninsert name map"), 1);
	mtx = initial_checks(av, &game);
	if (!mtx)
		return (freemtx(mtx), 1);
	mtx = map_mtx(mtx, av[1], &game);
	if (!mtx)
		return (printf("ERROR\n"), 1);
	char	**cpy = utils(av);
	game.map = cpy;
	if (check_map(cpy, &game.player) != 1)
		return (1);
	if (!set_colors(&txt, &game.dets))
		return (1);
	second_main(&game);
}
