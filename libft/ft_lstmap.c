/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmsanli <ahmsanli@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 19:46:10 by ahmsanli          #+#    #+#             */
/*   Updated: 2023/10/16 17:57:09 by ahmsanli         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*current;
	t_list	*temp;
	t_list	*list;

	if (lst == 0)
		return (0);
	current = lst;
	list = 0;
	while (current)
	{
		temp = ft_lstnew(f(current->content));
		if (!temp)
		{
			ft_lstclear(&list, del);
			return (0);
		}
		ft_lstadd_back(&list, temp);
		current = current->next;
	}
	return (list);
}
