/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:56:08 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:56:09 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 'A');
	else
		return (c);
}
/*
#include <stdio.h>
int	main (void)
{
	char	c1;
	char	c2;

	c1 = 'B';
	c2 = 'd';
	printf("char: %c, and in uppercase %c\n", c1, ft_toupper(c1));
	printf("char: %c, and in uppercase %c\n", c2, ft_toupper(c2));
}
*/
