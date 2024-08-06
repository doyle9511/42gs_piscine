/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:56 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:58 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*mylist;

	mylist = (t_list *) malloc(sizeof(t_list));
	if (!mylist)
		return (NULL);
	mylist->content = content;
	mylist->next = NULL;
	return (mylist);
}
