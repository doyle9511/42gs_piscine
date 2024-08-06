/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:11 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:12 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	return (c >= ' ' && c <= '~');
}
/*
#include <stdio.h>
int	main (void)
{
	int	c1;
	int	c2;

	c1 = 'a';
	c2 = '5';
	printf("char: %c is printable or not: %d\n", c1, ft_isprint(c1));
	printf("char: %c is printable or not: %d\n", c2, ft_isprint(c2));
}
*/
