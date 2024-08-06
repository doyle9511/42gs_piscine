/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: donghwi2 <donghwi2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 23:51:52 by doyle             #+#    #+#             */
/*   Updated: 2024/07/26 17:33:55 by donghwi2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three_elements(t_stack *stack)
{
	if (stack->a[2] != 2)
	{
		if (stack->a[0] == 2)
			rotate(stack->a, stack->a_size, 'u', "a");
		else
			rotate(stack->a, stack->a_size, 'd', "a");
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack->a, stack->a_size);
}

void	sort_four_to_five_elements(t_stack *stack)
{
	while (stack->b_size <= 1)
	{
		if (stack->a[0] == 0 || stack->a[0] == 1)
			push("pb", stack);
		else
			rotate(stack->a, stack->a_size, 'u', "a");
	}
	if (stack->b[0] == 0)
		swap("sb", stack->b, stack->b_size);
	if (stack->a[2] != 4)
	{
		if (stack->a[0] == 4)
			rotate(stack->a, stack->a_size, 'u', "a");
		else
			rotate(stack->a, stack->a_size, 'd', "a");
	}
	if (stack->a[0] > stack->a[1])
		swap("sa", stack->a, stack->a_size);
	push("pa", stack);
	push("pa", stack);
}

int	is_array_sorted(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->a_size - 1)
	{
		if (stack->a[i] > stack->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	radix_sort_stack_b(t_stack *stack, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(stack))
	{
		if (((stack->b[0] >> j) & 1) == 0)
			rotate(stack->b, stack->b_size, 'u', "b");
		else
			push("pa", stack);
	}
	if (is_array_sorted(stack))
		while (stack->b_size != 0)
			push("pa", stack);
}

void	radix_sort(t_stack *stack)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stack->a_size;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stack->a_size;
		while (size-- && !is_array_sorted(stack))
		{
			if (((stack->a[0] >> j) & 1) == 0)
				push("pb", stack);
			else
				rotate(stack->a, stack->a_size, 'u', "a");
		}
		radix_sort_stack_b(stack, stack->b_size, bit_size, j + 1);
	}
	while (stack->b_size != 0)
		push("pa", stack);
}
