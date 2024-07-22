/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:52:12 by donghwi2          #+#    #+#             */
/*   Updated: 2024/04/04 17:09:45 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

// char	*ft_save_str(char *save, char *buffer, int i)
// {
// 	if (i != BUFFER_SIZE)
// 	{
// 		save = 
// 	}
// }

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
		i++;
	return (i);
}

char	*ft_strdup(char *str)
{
	char	*ptr;
	int		str_len;
	int		i;

	i = 0;
	str_len = ft_strlen(str);
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

char	*ft_strjoin(char *s1, char *s2)
{
	int		i;
	int		s1_len;
	int		s2_len;
	char	*new_str;

	i = 0;
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
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
	return (new_str);
}

t_list	*ft_lstadd_new_to_back(t_list **d_lst, int fd)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node->fd_num = fd;
	new_node->save = ft_strdup("");
	new_node->next = NULL;
	if (*d_lst == NULL)
	{
		*d_lst = new_node;
		return (*d_lst);
	}
	(*d_lst)->next = new_node;
	return (*d_lst);
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

char	*ft_cut(char *str, int flag, int i)
{
	if (flag == 2)
	{
		while (*(str + i) != '\0')
		{
			if (*(str + i) == '\n')
				return (str + i + 1);
			i++;
		}
		return (str + i);
	}
	else
	{
		while (*(str + i) != '\0')
		{
			if (*(str + i) == '\n')
			{
				*(str + i + 1) = '\0';
				return (str);//혹시 앞부분 스킵하면 프리해도 앞에 누수 생기려나?
			}
			i++;
		}
		return (str);
	}
}

void	ft_flush_buffer(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = '\0';
		i++;
	}
}

char	*get_next_line(int fd)
{
	static t_list	*origin_lst;//asdjfhsadifljhasdfjkadf
	t_list			*lst;
	char	 		*result;
	int				temp_size;

	temp_size = BUFFER_SIZE;
	lst = origin_lst;
	if (lst == NULL)
	{
		origin_lst = ft_lstadd_new_to_back(&lst, fd);
	}
	while (lst->fd_num != fd)
	{
		if (lst->next == NULL)
		{
			ft_lstadd_new_to_back(&lst, fd);
		}
		lst = lst->next;
	}
	if (ft_strchr_ver2(lst->save) == 0)//\n없으면
	{
		while (ft_strchr_ver2(lst->save) == 0 && temp_size == BUFFER_SIZE)
		{
			temp_size = read(fd, lst->buffer, BUFFER_SIZE);
			lst->save = ft_strjoin(lst->save, lst->buffer);
			ft_flush_buffer(lst->buffer);
		}
	}
	result = ft_cut(ft_strdup(lst->save), 1, 0);
	lst->save = ft_cut(lst->save, 2, 0);
	
	return (result);
}

int main(){
	int	fd3;
	int	fd4;
	int	fd5;
	char *str;

	fd3 = open("./text3.txt", O_RDONLY);
	fd4 = open("./text4.txt", O_RDONLY);
	fd5 = open("./text5.txt", O_RDONLY);
	if (fd3 == -1 || fd4 == -1 || fd5 == -1)
		printf("file open error");
	
	str = get_next_line(fd5);
	printf("5>%s\n3>", str);
	
	str = get_next_line(fd3);
	printf("%s\n5>", str);
	
	str = get_next_line(fd5);
	printf("%s\n4>", str);
	
	str = get_next_line(fd4);
	printf("%s\n3>", str);
	
	str = get_next_line(fd3);
	printf("%s\n4>", str);
	
	str = get_next_line(fd4);
	printf("%s\n", str);

	close(fd3);
	close(fd4);
	close(fd5);
	return (0);
}