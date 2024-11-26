/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 10:47:00 by negambar          #+#    #+#             */
/*   Updated: 2024/11/25 15:24:21 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include "get_next_line/get_next_line.h"
# include "LIBFT/libft.h"

char	**mtxdup(char **av, int fd);
char	*get_the_line(int fd);
int		ft_strrchr2(char *s, char *c);
size_t	get_max_width(char *av);
size_t	get_height(char *av);

#endif