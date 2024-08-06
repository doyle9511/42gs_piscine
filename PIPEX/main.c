/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 00:11:28 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/06 12:12:36 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"



void	ft_error(t_pipex *pipex, char *err_msg)
{
	ft_putstr_fd(err_msg, stderr);
	free(pipex);
	exit(1);
}

void	ft_set_envp(t_pipex *pipex, char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			pipex->path = ft_split(envp[i] + 5, ':');
			return ;
		}
		i++;
	}
	ft_error(pipex, "PATH_error\n");
	return ;
}

void	check_cmd(t_pipex *pipex, char *av)
{
	int	i;

	i = 0;
	while (pipex->path[i] != NULL)
	{
		pipex->path_cmd1 = ft_join(pipex->path[i], pipex->cmd1_part[0]);
		if (access(pipex->path_cmd1, X_OK) == 0)
			break ;
		i++;
	}
	if (pipex->path[i] == NULL)
		ft_error(pipex, "cmd1_not_found\n");
	i = 0;
	while (pipex->path[i] != NULL)
	{
		pipex->path_cmd2 = ft_join(pipex->path[i], pipex->cmd2_part[0]);
		if (access(pipex->path_cmd2, X_OK) == 0)
			return ;
		i++;
	}
	ft_error(pipex, "cmd2_not_found\n");
	return ;
}

void	ft_make_pipe_input(t_pipex *pipex, char **av, char **envp)
{
	int	file1;

	file1 = open(av[1], O_RDONLY);
	if (dup2(file1, stdin) == -1)
		ft_error(pipex, "dup2_file1_stdin\n");
	if (dup2(pipex->fd[1], stdout) == -1)
		ft_error(pipex, "dup2_file1_stdout\n");
	execve(pipex->path_cmd1, pipex->cmd1_part, envp);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(file1);
}

void	ft_make_pipe_output(t_pipex *pipex, char **av, char **envp)
{
	int	file2;

	file2 = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (dup2(pipex->fd[0], stdin) == -1)
		ft_error(pipex, "dup2_file2_stdin\n");
	if (dup2(file2, stdout) == -1)
		ft_error(pipex, "dup2_file2_stdout\n");
	execve(pipex->path_cmd2, pipex->cmd2_part, envp);
	close(pipex->fd[0]);
	close(pipex->fd[1]);
	close(file2);
}

set_pipe(t_pipex *pipex, char **av, char **envp)
{
	if (pipex->pid1 == 0)
		ft_make_pipe_input(pipex, av, envp);
	else
	{
		pipex->pid2 = fork();
		if (pipex->pid2 == 0)
			ft_make_pipe_output(pipex, av, envp);
		else
		{
			waitpid(pipex->pid2, NULL, 0);
			waitpid(pipex->pid1, NULL, 0);
			close(pipex->fd[0]);
			close(pipex->fd[1]);
		}
	}
}

int main(int ac, char **av, char **envp)
{
	t_pipex	*pipex;

	init_pipex(pipex);
	pipex = (t_pipex *)malloc(sizeof(t_pipex));
	if (pipex != NULL)
		ft_error(pipex, "malloc_fail\n");
	if (ac != 5)
		ft_error(pipex, "arg_incorrect\n");
	ft_set_envp(pipex, envp);
	pipex->cmd1_part = ft_split(av[2], ' ');
	pipex->cmd2_part = ft_split(av[3], ' ');
	check_cmd(pipex, av);
	if (pipe(pipex->fd) == -1)
		ft_error(pipex, "pipe_error");
	pipex->pid1 = fork();
	set_pipe(pipex, av, envp);
	free(pipex);
	return (0);
}