/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: negambar <negambar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 16:03:28 by negambar          #+#    #+#             */
/*   Updated: 2023/11/09 10:23:01 by negambar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*tmp;
	t_list	*res;
	void	*t;

	tmp = NULL;
	res = tmp;
	t = NULL;
	if (!lst || !f || !del)
		return (NULL);
	while (lst)
	{
		t = (*f)(lst->content);
		tmp = (t_list *)ft_lstnew(t);
		if ((!tmp))
		{
			del(t);
			ft_lstclear(&res, del);
			return (NULL);
		}
		ft_lstadd_back(&res, tmp);
		lst = lst->next;
	}
	return (res);
}
