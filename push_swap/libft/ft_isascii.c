/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:01 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:02 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isascii(int c)
{
	return ((c >= 0 && c <= 127));
}
/*
#include <stdio.h>
int	main (void)
{
	int	c1;
	int	c2;

	c1 = 'a';
	c2 = 128;
	printf("char: %c is Ascii or not: %d\n", c1, ft_isascii(c1));
	printf("char: %c is Ascii or not: %d\n", c2, ft_isascii(c2));
	printf("%d\n",isascii('a'));
	printf("%d\n",isascii(128));
}
*/
