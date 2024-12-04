/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mtx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:01:44 by negambar          #+#    #+#             */
/*   Updated: 2024/12/04 11:02:06 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	closeall(int fd, char **mtx, t_details dets)
{
	close(fd);
	freeatts(&dets);
	freemtx(mtx);
}