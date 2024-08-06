/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/30 13:56:45 by doyle             #+#    #+#             */
/*   Updated: 2024/07/16 20:11:08 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 3
# endif
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>

typedef struct s_list_gnl
{
	int				fd_num;
	int				end_flag;
	char			buffer[BUFFER_SIZE + 1];
	char			*save;
	struct s_list_gnl	*before;
	struct s_list_gnl	*next;
}t_list_gnl;

char	*ft_cut_front(char *str);
char	*ft_cut_back(char *str);
void	ft_free_node(t_list_gnl *lst, t_list_gnl **d_origin_lst);
char	*ft_read(t_list_gnl *lst, int fd, t_list_gnl **d_origin_lst);
char	*get_next_line(int fd);

int		ft_strlen_gnl(char *str);
char	*ft_strdup_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
int		ft_strchr_ver2(char *str);
t_list_gnl	*ft_lstadd_new_to_back(t_list_gnl **d_lst, int fd);

#endif