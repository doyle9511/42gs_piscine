/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:45 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:47 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*mylist;

	if (!lst)
		return (lst);
	mylist = lst;
	while (mylist != NULL)
	{
		if (mylist->next == NULL)
			return (mylist);
		mylist = mylist->next;
	}
	return (0);
}
