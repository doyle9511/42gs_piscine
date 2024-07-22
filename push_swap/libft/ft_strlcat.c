/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:55:19 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:55:20 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	dstsize;
	size_t	srcsize;

	i = 0;
	dstsize = ft_strlen(dst);
	srcsize = ft_strlen(src);
	j = dstsize;
	if (dstsize < size && size)
	{
		while (src[i] && dstsize + i < size - 1)
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	if (dstsize >= size)
		dstsize = size;
	return (dstsize + srcsize);
}
