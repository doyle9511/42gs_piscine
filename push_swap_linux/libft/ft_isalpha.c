/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:52:31 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:52:34 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}
/*
#include <stdio.h>
int	main (void)
{
	char	c1;
	char	c2;

	c1 = 'a';
	c2 = '5';
	printf("char: %c is alpha or not: %d\n", c1, ft_isalpha(c1));
	printf("char: %c is alpha or not: %d\n", c2, ft_isalpha(c2));
}
*/
