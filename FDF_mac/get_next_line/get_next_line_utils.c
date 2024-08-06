/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/05 22:38:18 by donghwi2          #+#    #+#             */
/*   Updated: 2024/07/16 20:11:24 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen_gnl(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strdup_gnl(char *str)
{
	char	*ptr;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen_gnl(str);
	ptr = (char *)malloc((str_len + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	while (i < str_len)
	{
		ptr[i] = str[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*new_str;

	i = 0;
	s1_len = ft_strlen_gnl(s1);
	s2_len = ft_strlen_gnl(s2);
	new_str = (char *)malloc((s1_len + s2_len + 1) * sizeof(char));
	if (new_str == NULL)
		return (NULL);
	while (i < s1_len)
	{
		new_str[i] = s1[i];
		i++;
	}
	while (i < s1_len + s2_len)
	{
		new_str[i] = s2[i - s1_len];
		i++;
	}
	new_str[i] = '\0';
	free(s1);
	return (new_str);
}

int	ft_strchr_ver2(char *str)
{
	while (*str != '\0')
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

t_list_gnl	*ft_lstadd_new_to_back(t_list_gnl **d_lst, int fd)
{
	t_list_gnl	*new_node;
	int		i;

	i = 0;
	new_node = (t_list_gnl *)malloc(sizeof(t_list_gnl));
	if (new_node == NULL)
		return (NULL);
	new_node->fd_num = fd;
	new_node->save = ft_strdup_gnl("");
	while (i < BUFFER_SIZE + 1)
	{
		new_node->buffer[i] = '\0';
		i++;
	}
	new_node->next = NULL;
	if (*d_lst == NULL)
	{
		new_node->before = NULL;
		*d_lst = new_node;
		return (*d_lst);
	}
	new_node->before = *d_lst;
	(*d_lst)->next = new_node;
	return (*d_lst);
}
