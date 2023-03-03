/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trilouche.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:12:49 by atardif           #+#    #+#             */
/*   Updated: 2023/03/03 16:17:47 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pre_sort(t_list **stack_a, t_list **stack_b, t_chunk chunk, t_sub sub)
{
	int	index;

	index = (*stack_a)->index;
	if (index >= 0 && index <= (chunk.chunk - (chunk.ratio / 2))
		&& !in_lis(index, sub.lis, sub.l_size))
		pb(stack_b, stack_a);
	else if (index > (chunk.chunk - chunk.ratio / 2) && index <= chunk.chunk
		&& !in_lis(index, sub.lis, sub.l_size))
	{
		pb(stack_b, stack_a);
		if (is_in_chunk((*stack_a)->index, chunk.chunk))
			rb(stack_b);
		else
			rr(stack_a, stack_b);
	}
	else
		ra(stack_a);
}

void	insert_back_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int		i;
	int		pos;

	i = data->a_size - 1;
	while (i >= 0)
	{
		last_insert(stack_a);
		while (in_lis(i, data->sub.lis, data->sub.l_size))
				i--;
		if (i < 0)
			return ;
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

void	rotate_lis(t_list **stack_a, t_data *data)
{
	int		minlis;
	int		minpos;
	int		size;
	t_list	*tmp;

	minlis = data->sub.lis[data->sub.l_size - 1];
	minpos = index_pos(*stack_a, minlis);
	if ((*stack_a)->index == data->a_size - 1)
		return ;
	size = ft_lstsize(*stack_a);
	while ((*stack_a)->index != minlis)
	{
		if (minpos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	tmp = ft_lstlast(*stack_a);
	if (tmp->index == data->a_size - 1)
		rra(stack_a);
}

void	first_phase(t_list **stack_a, t_list **stack_b, t_data *data, int div)
{
	float	i;

	i = 2;
	data->chunk.ratio = data->a_size / div;
	while (i < div)
	{
		data->chunk.chunk = data->chunk.ratio * i;
		while (!chunk_left(stack_a, data->chunk.chunk, data->sub.lis,
				data->sub.l_size))
			pre_sort(stack_a, stack_b, data->chunk, data->sub);
		i++;
	}
	data->chunk.chunk = data->a_size - 1;
	while (!chunk_left(stack_a, data->a_size, data->sub.lis, data->sub.l_size))
		pre_sort(stack_a, stack_b, data->chunk, data->sub);
}

void	tri_chelou(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->a_size < 200)
		first_phase(stack_a, stack_b, data, 4);
	else if (data->a_size >= 200)
		first_phase(stack_a, stack_b, data, 10);
	rotate_lis(stack_a, data);
	insert_back_sort(stack_a, stack_b, data);
}
