/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/03 16:15:43 by atardif           #+#    #+#             */
/*   Updated: 2023/03/03 16:23:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	in_lis(int index, int *lis, int l_size)
{
	int	i;

	i = 0;
	while (i < l_size)
	{
		if (index == lis[i])
			return (1);
		i++;
	}
	return (0);
}

int	is_in_chunk(int index, int chunk)
{
	if (index >= 0 && index <= chunk)
		return (1);
	return (0);
}

int	chunk_left(t_list **stack_a, int chunk, int *lis, int l_size)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index >= 0 && tmp->index <= chunk
			&& !in_lis(tmp->index, lis, l_size))
			return (0);
		tmp = tmp->next;
	}
	if (tmp->index >= 0 && tmp->index <= chunk
		&& !in_lis(tmp->index, lis, l_size))
		return (0);
	return (1);
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

void	last_insert(t_list **stack_a)
{
	t_list	*tmp;

	tmp = ft_lstlast(*stack_a);
	while (tmp->index == (*stack_a)->index - 1)
	{
		rra(stack_a);
		tmp = ft_lstlast(*stack_a);
	}
}
