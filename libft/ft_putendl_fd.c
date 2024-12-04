/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:15:10 by negambar          #+#    #+#             */
/*   Updated: 2023/10/23 12:17:41 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (fd < 0)
		return ;
	if (fd >= 0)
	{
		write(fd, &*s, ft_strlen(s));
		write(fd, "\n", 1);
	}
}
/*
int main()
{
	char s[] = "hellollollolllo";
	int fd = 1;
	ft_putendl_fd(s, fd);
}*/
