/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:51:46 by doyle             #+#    #+#             */
/*   Updated: 2024/07/26 17:34:12 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 0)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stack *stack)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (stack->b_size <= 0)
			return ;
		tmp = stack->b[0];
		ft_memmove(stack->a + 1, stack->a, sizeof(int) * stack->a_size);
		stack->a[0] = tmp;
		stack->b_size--;
		ft_memmove(stack->b, stack->b + 1, sizeof(int) * stack->b_size);
		stack->a_size++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (stack->a_size <= 0)
			return ;
		tmp = stack->a[0];
		ft_memmove(stack->b + 1, stack->b, sizeof(int) * stack->b_size);
		stack->b[0] = tmp;
		stack->a_size--;
		ft_memmove(stack->a, stack->a + 1, sizeof(int) * stack->a_size);
		stack->b_size++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char direction, char *list)
{
	int	tmp;

	if (size < 0)
		return ;
	if (direction == 'u')
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (direction == 'd')
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
