/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42gyeongsan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 07:48:08 by donghwi2          #+#    #+#             */
/*   Updated: 2024/08/05 07:55:25 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**ft_set_envp(char **envp)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if(ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			return (ft_split(envp[i] + 5, ':'));
		}
		i++;
	}
	printf("no envp\n");
	return (NULL);
}

int main(int ac, char **av, char **envp)
{
	char **dstr;
	dstr = ft_set_envp(envp);
	for (int i = 0; dstr[i] != NULL; i++)
	{
		printf("%s\n", dstr[i]);
	}
	return (0);
}