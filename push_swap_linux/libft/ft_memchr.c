/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:07 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:54:08 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	char		str[50] = "he.ee.gaegea";;
	char		ch = '.';
	char		*ret;

	ret = ft_memchr(str, ch, 29);
	//ret = memchr(str, ch, 29);
	printf("String after |%c| is - |%s|\n", ch, (char *)ft_memchr(str, ch, 29));
	return (0);
}
*/