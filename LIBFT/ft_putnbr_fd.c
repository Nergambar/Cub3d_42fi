/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 12:18:35 by negambar          #+#    #+#             */
/*   Updated: 2023/10/23 12:26:07 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static unsigned int	ft_module_fd(int n)
{
	if (n < 0)
		return (n * (-1));
	else
		return (n);
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	num;

	if (fd < 0)
		return ;
	if (fd >= 0)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		num = ft_module_fd(n);
		if (num >= 10)
		{
			ft_putnbr_fd(num / 10, fd);
			ft_putnbr_fd(num % 10, fd);
		}
		else
			ft_putchar_fd(num + '0', fd);
	}
}
/*
int main()
{
	int fd = 1;
	ft_putnbr_fd(-10, fd);
}*/
