/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vgabovs <vgabovs@student.42wolfsburg.de    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 23:54:39 by vgabovs           #+#    #+#             */
/*   Updated: 2023/07/14 18:25:36 by vgabovs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*begin;
	t_list	*tmp;
	void	*func;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_list = NULL;
	begin = lst;
	while (begin != NULL)
	{
		func = (f)(begin->content);
		tmp = ft_lstnew(func);
		if (tmp == NULL)
		{
			ft_lstclear(&new_list, del);
			del(func);
			return (NULL);
		}
		ft_lstadd_back(&new_list, tmp);
		begin = begin->next;
	}
	return (new_list);
}
