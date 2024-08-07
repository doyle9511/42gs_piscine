/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:55:45 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:55:46 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *) &s[i]);
		i--;
	}
	return (NULL);
}
/*
#include <string.h>
#include <stdio.h>

int	main(void)
{
	char *str = "bonjour";

	printf("%s\n", ft_strrchr(str + 2, 'b'));
	printf("%s\n", strrchr(str + 2, 'b'));
	printf("%s\n", ft_strrchr("hello", '\0'));
	printf("%s\n", strrchr("hello", '\0'));
	printf("%s\n", ft_strrchr("hello", 'e'));
	printf("%s\n", strrchr("hello", 'e'));
	printf("%s\n", ft_strrchr("bonjour", 'b'));
	printf("%s\n", strrchr("bonjour", 'b'));
	printf("%s\n", ft_strrchr("", 'e'));
	printf("%s\n", strrchr("", 'e'));
	printf("%s\n", ft_strrchr("", '\0'));
	printf("%s\n", strrchr("", '\0'));
	printf("%s\n", ft_strrchr(" ", '\0'));
	printf("%s\n", strrchr(" ", '\0'));
	return (0);
}
*/