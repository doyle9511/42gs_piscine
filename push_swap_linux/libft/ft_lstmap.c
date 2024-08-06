/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:52 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:53 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *),
void (*del)(void *))
{
	t_list	*mylist;
	void	*tmp;

	if (!lst)
		return (NULL);
	mylist = NULL;
	while (lst)
	{
		tmp = f(lst->content);
		if (!tmp)
		{
			ft_lstclear(&mylist, del);
			return (NULL);
		}
		ft_lstadd_back(&mylist, ft_lstnew(tmp));
		lst = lst->next;
	}
	return (mylist);
}
