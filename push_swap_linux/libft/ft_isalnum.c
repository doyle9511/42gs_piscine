/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:52:26 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:52:37 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}
/*
#include <ctype.h>
#include <stdio.h>
int	main (void)
{
	char	c1;
	char	c2;

	c1 = 'a';
	c2 = '5';
	printf("char: %c is alphanumeric or not: %d\n", c1, ft_isalnum(c1));
	printf("char: %c is alphanumeric or not: %d\n", c2, ft_isalnum(c2));
}
*/
