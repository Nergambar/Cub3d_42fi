/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:47:00 by negambar          #+#    #+#             */
/*   Updated: 2024/11/28 11:37:55 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "LIBFT/libft.h"
# include <stdbool.h>

typedef struct s_textures
{
	int		f;
	int		c;
	void	*no;
	void	*so;
	void	*we;
	void	*ea;
}	t_textures;

typedef struct s_details
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	**mf;
	char	**mc;
}	t_details;

void	init_attrs(t_details *dets);
char	**mtxdup(char **av, int fd);
char	*get_the_line(int fd);
int		ft_strrchr2(char *s, char *c);
size_t	get_max_width(char *av);
size_t	get_height(char *av);
int		mtx_trim(char **mtx);
char	**map_mtx(char **mtx, char *av);
bool	empy_line(char *line);
void	freemtx(char **mtx);
int		check_extras(char **mtx, t_details *dets, int trimmed, int i);
void	freeatts(t_details *dets);
int		set_colors(t_textures *txt, t_details *dets);

#endif