/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 05:26:28 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/06 11:19:12 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>
#include "libft/libft.h"

typedef struct s_pipex
{
	pid_t	pid1;
	pid_t	pid2;
	int		file1;
	int		file2;
	char 	**path;
	char	**cmd1_part;
	char	**cmd2_part;
	char	*path_cmd1;
	char	*path_cmd2;
	int		fd[2];
}t_pipex;

#endif