/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:54:24 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:54:25 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dst_p;
	char	*src_p;
	size_t	i;

	i = 0;
	dst_p = (char *)dst;
	src_p = (char *)src;
	if (src == dst || !n)
		return (dst);
	if (src_p < dst_p)
	{
		while (++i <= n)
		{
			dst_p[n - i] = src_p[n - i];
		}
	}
	else
		while (n-- > 0)
			*dst_p++ = *src_p++;
	return (dst);
}
/*
#include <stdio.h>
int	main(void)
{
	char	*p;
	char src[] = "hallaaaaaaaao";
	char dest[] = "test";
	p = ft_memmove(dest, src, 3);
	printf("%s", (unsigned char *)(p));
}
*/