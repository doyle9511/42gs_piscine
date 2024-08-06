/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:52:16 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:52:43 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
/*
int	main(void)
{
	char	*test;

	test = malloc(256);
	test[0] = 'a';
	printf("String after is - |%s|\n", test);	
	ft_bzero(test, 256);
	printf("String after is - |%s|\n", test);
	return (0);
}
*/
