/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:30 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:54:32 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)s;
	while (n--)
	{
		ptr[n] = (unsigned char)c;
	}
	return (s);
}
/*
int	main(void)
{
   int len;
	const char	str[];
	const char	ch;
   char *ret;

   str[] = "http://www.tutorialspoint.com";
   ch = '.';
   ret = ft_memset(str, ch, 3);
   printf("String after |%c| is - |%s|\n", ch, ret);
   
	return(0);
}
*/
