/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trichelou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:12:49 by atardif           #+#    #+#             */
/*   Updated: 2023/02/24 15:44:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	in_chunk(t_list **stack_a, int chunk)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->content >= 0 && tmp->content <= chunk)
			return (0);
		tmp = tmp->next;
	}
	if (tmp->content >= 0 && tmp->content <= chunk)
			return (0);
	return (1);
}

void	pre_sort(t_list **stack_a, t_list **stack_b, int ratio, int chunk)
{
	if((*stack_a)->index >= 0 && (*stack_a)->index <= (chunk - (ratio / 2)))
		pb(stack_b, stack_a);
	else if ((*stack_a)->index > (chunk - ratio / 2) && (*stack_a)->index <= chunk)
	{
		pb(stack_b, stack_a);
		rb(stack_b);
	}
	else
		ra(stack_a);
}

int	index_pos(t_list *stack, int target)
{
	int	i;

	i = 0;
	while (stack->next != NULL)
	{
		if (stack->index == target)
			return (i);
		stack = stack->next;
		i++;
	}
	return (i);
}

void	insert_back_sort(t_list **stack_a, t_list **stack_b, int size)
{
	int	i;
	int	pos;

	i = size;
	while (i >= 0)
	{
		pos = index_pos(*stack_b, i);
		while ((*stack_b)->index != i)
		{
			if (pos <= (i + 1) / 2)
				rb(stack_b);
			else
				rrb(stack_b);
		}
		pa(stack_a, stack_b);
		i--;
	}
}




/*void	third_phase(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;
	int	i;

	while(ft_lstsize(*stack_b) > 0)
	{
		i = 0;
		tmp = ft_lstlast(*stack_b);
		if( tmp->index > (*stack_b)->index)
			rrb(stack_b);
		while ((*stack_b)->index > (*stack_a)->index)
		{
			ra(stack_a);
			i++;
		}
		if ((*stack_b)->index < (*stack_a)->index)
			pa(stack_a, stack_b);
		while (i > 0)
		{
			rra(stack_a);
			i--;
		}
	}
}*/


void	first_phase(t_list **stack_a, t_list **stack_b, int ratio, int size)
{
	int	chunk;

	chunk = (ratio * 2) + 1;
	while (!in_chunk(stack_a, ratio) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, 0, ratio);
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, ratio, chunk);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, ratio, size - 4);
}

void	tri_chelou(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	ratio;

	ratio = data->a_size / 3 - 1;
	first_phase(stack_a, stack_b, ratio, data->a_size);
	sort_3(stack_a);
	insert_back_sort(stack_a, stack_b, data->a_size - 4);
	//third_phase(stack_a, stack_b);
}
