/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:55:27 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:55:29 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length++;
	return (length);
}
/*
#include <stdio.h>
#include <string.h>

int	main (void)
{
	char	*s1;
	char	*s2;

	s1 = "re";
	s2 = "Test string";
	printf("string: %s length: %ld\n", s1, ft_strlen(s1));
	printf("string: %s length: %ld\n", s2, ft_strlen(s2));
	printf("string: %s length: %ld\n", s1, strlen(s1));
	printf("string: %s length: %ld\n", s2, strlen(s2));
}
*/
