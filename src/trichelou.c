/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trichelou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:12:49 by atardif           #+#    #+#             */
/*   Updated: 2023/02/23 18:50:39 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


int	last_chunk(t_list **stack_a, int chunk)
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


void	first_phase(t_list **stack_a, t_list **stack_b, int ratio, int size)
{
	int	chunk;

	chunk = (ratio * 2) + 1;
	while (!last_chunk(stack_a, chunk))
	{
		if ((*stack_a)->index >= 0 && (*stack_a)->index <= ratio)
			pb(stack_b, stack_a);
		else if ((*stack_a)->index > ratio && (*stack_a)->index <= chunk)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
	while (!last_chunk(stack_a, size - 3))
	{
		if ((*stack_a)->index < size - 3 && (*stack_a)->index < size - (ratio / 2))
			pb(stack_b, stack_a);
		else if ((*stack_a)->index < size - 3)
		{
			pb(stack_b, stack_a);
			rb(stack_b);
		}
		else
			ra(stack_a);
	}
}




void	tri_chelou(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	ratio;

	ratio = data->a_size / 3 - 1;
	first_phase(stack_a, stack_b, ratio, data->a_size);
	sort_3(stack_a);
}
