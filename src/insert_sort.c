/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:52:58 by atardif           #+#    #+#             */
/*   Updated: 2023/02/23 16:01:42 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	index_min(t_list *stack)
{
	int	min;

	min = INT_MAX;
	while (stack->next != NULL)
	{
		if (stack->index < min)
			min = stack->index;
		stack = stack->next;
	}
	return (min);
}i*/

int	minindex_pos(t_list *stack, int min)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		if (stack->index == min)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}



void	insert_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	min;
	int	i;
	int	pos;

	min = 0;
	i = 0;
	while (i < data->a_size)
	{
		min = i;
		pos = minindex_pos(*stack_a, i);
		while((*stack_a)->index != min)
		{
			if (pos <= (data->a_size - i) / 2)
				ra(stack_a);
			else
				rra(stack_a);
		}
		pb(stack_b, stack_a);
		i++;
	}
	i = 0;
	while (i < data->a_size)
	{
		pa(stack_a, stack_b);
		i++;
	}
}
