/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:53:06 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:53:08 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
/*
#include <stdio.h>
int	main (void)
{
	int	c1;
	int	c2;

	c1 = 'a';
	c2 = '5';
	printf("char: %c is digit or not: %d\n", c1, ft_isdigit(c1));
	printf("char: %c is digit or not: %d\n", c2, ft_isdigit(c2));
}
*/
