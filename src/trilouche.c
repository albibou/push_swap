/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trichelou.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 17:12:49 by atardif           #+#    #+#             */
/*   Updated: 2023/02/26 18:19:13 by atardif          ###   ########.fr       */
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


int	in_chunk(t_list **stack_a, int chunk, int *lis, int l_size)
{
	t_list	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->index >= 0 && tmp->index <= chunk && !in_lis(tmp->index, lis, l_size))
			return (0);
		tmp = tmp->next;
	}
	if (tmp->index >= 0 && tmp->index <= chunk && !in_lis(tmp->index, lis, l_size))
			return (0);
	return (1);
}

void	best_move(t_list **stack, int chunk, t_data *data)
{
	int	firstpos;
	int	lastpos;
	int	size;
	t_list	*tmp;

	tmp = *stack;
	firstpos = 0;
	lastpos = 0;
	size = ft_lstsize(tmp);
	while(tmp->next != NULL)
	{
		if (is_in_chunk(tmp->index, chunk))
				break;
		tmp = tmp->next;
		firstpos++;
	}
	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (in_chunk(&tmp, chunk, data->lis, data->l_size))
				break;
		tmp = tmp->next;
		lastpos++;
	}
	if (firstpos <= size - lastpos)
	{
		while(!is_in_chunk((*stack)->index, chunk))
			ra(stack);
	}
	else if (size - lastpos < firstpos)
	{
		while(!is_in_chunk((*stack)->index, chunk))
			rra(stack);
	}

}

void	pre_sort(t_list **stack_a, t_list **stack_b, int ratio, int chunk, t_data *data)
{
	int	index;

	index = (*stack_a)->index;
	if(index >= 0 && index <= (chunk - (ratio / 2)) && !in_lis(index, data->lis, data->l_size))
		pb(stack_b, stack_a);
	else if (index > (chunk - ratio / 2) && index <= chunk && !in_lis(index, data->lis, data->l_size))
	{
		pb(stack_b, stack_a);
		if (is_in_chunk((*stack_a)->index, chunk))
			rb(stack_b);
		else
			rr(stack_a, stack_b);
	}
	else
		ra(stack_a);
		//best_move(stack_a, chunk, data);
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

void	insert_back_sort(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	i;
	int	pos;
	t_list	*tmp;

	i = data->a_size - 1;
	while (i >= 0)
	{
		tmp = ft_lstlast(*stack_a);
		while (tmp->index == (*stack_a)->index - 1)
		{
			rra(stack_a);
			tmp = ft_lstlast(*stack_a);
		}
		while(in_lis(i, data->lis, data->l_size))
				i--;
		if (i < 0)
			return;
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
	int	minlis;
	int 	minpos;
	int	size;
	t_list	*tmp;

	minlis = data->lis[data->l_size - 1];
	minpos = index_pos(*stack_a, minlis);
	if((*stack_a)->index == data->a_size - 1)
		return;
	size = ft_lstsize(*stack_a);
	while ((*stack_a)->index != minlis)
	{
		if(minpos <= size / 2)
			ra(stack_a);
		else
			rra(stack_a);
	}
	tmp = ft_lstlast(*stack_a);
	if (tmp->index == data->a_size - 1)
		rra(stack_a);
}

void	first_phase10(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	chunk;
	int	chunk2;
	int	chunk3;
	int	chunk4;
	int	chunk5;
	int	chunk6;
	int	chunk7;
	int	chunk8;
	int	chunk9;

	chunk = data->a_size / 10 - 1;
	chunk2 = (chunk * 2) + 1;
	chunk3 = (chunk * 3) + 1;
	chunk4 = (chunk * 4) + 1;
	chunk5 = (chunk * 5) + 1;
	chunk6 = (chunk * 6) + 1;
	chunk7 = (chunk * 7) + 1;
	chunk8 = (chunk * 8) + 1;
	chunk9 = (chunk * 9) + 1;
	while (!in_chunk(stack_a, chunk, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk, data);
	while (!in_chunk(stack_a, chunk2, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk2, data);
	while (!in_chunk(stack_a, chunk3, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk3, data);
	while (!in_chunk(stack_a, chunk4, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk4, data);
	while (!in_chunk(stack_a, chunk5, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk5, data);
	while (!in_chunk(stack_a, chunk6, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk6, data);
	while (!in_chunk(stack_a, chunk7, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk7, data);
	while (!in_chunk(stack_a, chunk8, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk8, data);
	while (!in_chunk(stack_a, chunk9, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk9, data);
	while (!in_chunk(stack_a, data->a_size, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, data->a_size, data);
}


void	first_phase4(t_list **stack_a, t_list **stack_b, t_data *data)
{
	int	chunk;
	int	chunk2;
	int	chunk3;

	chunk = data->a_size / 4 - 1;
	chunk2 = (chunk * 2) + 1;
	chunk3 = (chunk * 3) + 1;
	while (!in_chunk(stack_a, chunk, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk, data);
	while (!in_chunk(stack_a, chunk2, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk2, data);
	while (!in_chunk(stack_a, chunk3, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, chunk3, data);
	while (!in_chunk(stack_a, data->a_size, data->lis, data->l_size))
		pre_sort(stack_a, stack_b, chunk, data->a_size, data);
}


void	tri_chelou(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->a_size < 200)
		first_phase4(stack_a, stack_b, data);
	else if (data->a_size >= 200)
		first_phase10(stack_a, stack_b, data);
	rotate_lis(stack_a, data);
	insert_back_sort(stack_a, stack_b, data);
}
