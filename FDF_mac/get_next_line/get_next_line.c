/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:52:12 by donghwi2          #+#    #+#             */
/*   Updated: 2024/07/16 20:11:59 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_cut_front(char *str)
{
	int		i;
	char	*temp;

	i = 0;
	temp = str;
	while (*(temp + i) != '\0')
	{
		if (*(temp + i) == '\n')
		{
			temp = ft_strdup_gnl(temp + i + 1);
			free(str);
			return (temp);
		}
		i++;
	}
	temp = ft_strdup_gnl(str + i);
	free(str);
	return (temp);
}

char	*ft_cut_back(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		if (*(str + i) == '\n')
		{
			*(str + i + 1) = '\0';
			return (str);
		}
		i++;
	}
	return (str);
}

void	ft_free_node(t_list_gnl *lst, t_list_gnl **d_origin_lst)
{
	free(lst->save);
	if (lst->before != NULL || lst->next != NULL)
	{
		if (lst->before == NULL)
		{
			*d_origin_lst = lst->next;
			(lst->next)->before = NULL;
		}
		else if (lst->next == NULL)
		{
			(lst->before)->next = NULL;
		}
		else
		{
			(lst->before)->next = lst->next;
			(lst->next)->before = lst->before;
		}
	}
	else
		*d_origin_lst = NULL;
	free(lst);
	lst = NULL;
}

char	*ft_read(t_list_gnl *lst, int fd, t_list_gnl **d_origin_lst)
{
	int	temp_size;
	int	i;

	temp_size = BUFFER_SIZE;
	while (ft_strchr_ver2(lst->save) == 0 && temp_size == BUFFER_SIZE)
	{
		i = 0;
		temp_size = read(fd, lst->buffer, BUFFER_SIZE);
		if ((*(lst->buffer) == '\0' && temp_size == 0 && *(lst->save) == '\0')
			|| temp_size == -1)
		{
			ft_free_node(lst, d_origin_lst);
			return (NULL);
		}
		lst->save = ft_strjoin_gnl(lst->save, lst->buffer);
		while ((lst->buffer)[i] != '\0')
		{
			(lst->buffer)[i] = '\0';
			i++;
		}
	}
	return (lst->save);
}

char	*get_next_line(int fd)
{
	static t_list_gnl	*origin_lst;
	t_list_gnl			*lst;
	char			*result;

	lst = origin_lst;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (lst == NULL)
		origin_lst = ft_lstadd_new_to_back(&lst, fd);
	while (lst->fd_num != fd)
	{
		if (lst->next == NULL)
			ft_lstadd_new_to_back(&lst, fd);
		lst = lst->next;
	}
	if (ft_read(lst, fd, &origin_lst) == NULL)
		return (NULL);
	result = ft_cut_back(ft_strdup_gnl(lst->save));
	lst->save = ft_cut_front(lst->save);
	return (result);
}
