/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: doyle <doyle@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:56:00 by doyle             #+#    #+#             */
/*   Updated: 2024/06/17 23:56:01 by doyle            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 'a');
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
	printf("char: %c, and in lowercase %c\n", c1, ft_tolower(c1));
	printf("char: %c, and in lowercase %c\n", c2, ft_tolower(c2));
}
*/
