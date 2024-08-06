/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:55:36 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:55:38 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while ((*s1 || *s2) && (n > 0))
	{
		if (*s1 != *s2)
			return ((unsigned char)*s1 - (unsigned char)*s2);
		n--;
		s1++;
		s2++;
	}
	return (0);
}
/*
#include <stdio.h>
#include <string.h>
int main ()
{
	char	str1[50]="za";
	char	str2[50]="";
	printf("ft_cmp:%d\n", ft_strncmp(str1, str2, 5));
	printf("cmp:%d\n", strncmp(str1, str2, 5));
}
*/