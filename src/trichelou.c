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

int	is_in_chunk(int index, int chunk)
{
	if (index >= 0 && index <= chunk)
		return (1);
	return (0);
}

void	best_move(t_list **stack, int chunk)
{
	int	firstpos;
	int	lastpos;
	t_list	*tmp;

	tmp = *stack;
	while(tmp->next != NULL)
	{
	}
}

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
		if (is_in_chunk((*stack_a)->index, chunk))
			rb(stack_b);
		else
			rr(stack_a, stack_b);
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

void	first_phase10(t_list **stack_a, t_list **stack_b, int size)
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

	chunk = size / 10 - 1;
	chunk2 = (chunk * 2) + 1;
	chunk3 = (chunk * 3) + 1;
	chunk4 = (chunk * 4) + 1;
	chunk5 = (chunk * 5) + 1;
	chunk6 = (chunk * 6) + 1;
	chunk7 = (chunk * 7) + 1;
	chunk8 = (chunk * 8) + 1;
	chunk9 = (chunk * 9) + 1;
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk);
	while (!in_chunk(stack_a, chunk2) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk2);
	while (!in_chunk(stack_a, chunk3) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk3);
	while (!in_chunk(stack_a, chunk4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b,chunk, chunk4);
	while (!in_chunk(stack_a, chunk5) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk5);
	while (!in_chunk(stack_a, chunk6) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk6);
	while (!in_chunk(stack_a, chunk7) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk7);
	while (!in_chunk(stack_a, chunk8) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk8);
	while (!in_chunk(stack_a, chunk9) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk9);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, size - 4);
}

/*void	first_phase9(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk;
	int	chunk2;
	int	chunk3;
	int	chunk4;
	int	chunk5;
	int	chunk6;
	int	chunk7;
	int	chunk8;

	chunk = size / 9 - 1;
	chunk2 = (chunk * 2) + 1;
	chunk3 = (chunk * 3) + 1;
	chunk4 = (chunk * 4) + 1;
	chunk5 = (chunk * 5) + 1;
	chunk6 = (chunk * 6) + 1;
	chunk7 = (chunk * 7) + 1;
	chunk8 = (chunk * 8) + 1;
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk);
	while (!in_chunk(stack_a, chunk2) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk2);
	while (!in_chunk(stack_a, chunk3) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk3);
	while (!in_chunk(stack_a, chunk4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b,chunk, chunk4);
	while (!in_chunk(stack_a, chunk5) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk5);
	while (!in_chunk(stack_a, chunk6) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk6);
	while (!in_chunk(stack_a, chunk7) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk7);
	while (!in_chunk(stack_a, chunk8) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk8);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, size - 4);
}*/

void	first_phase4(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk;
	int	chunk2;
	int	chunk3;

	chunk = size / 4 - 1;
	chunk2 = (chunk * 2) + 1;
	chunk3 = (chunk * 3) + 1;
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk);
	while (!in_chunk(stack_a, chunk2) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk2);
	while (!in_chunk(stack_a, chunk3) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk3);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, size - 4);
}


/*void	first_phase3(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk;
	int	chunk2;

	chunk = size / 3 - 1;
	chunk2 = (chunk * 2) + 1;
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk);
	while (!in_chunk(stack_a, chunk2) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk2);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, size - 4);
}*/

/*void	first_phase2(t_list **stack_a, t_list **stack_b, int size)
{
	int	chunk;

	chunk = size / 2 - 1;
	while (!in_chunk(stack_a, chunk) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, chunk);
	while (!in_chunk(stack_a, size - 4) && ft_lstsize(*stack_a) > 3)
		pre_sort(stack_a, stack_b, chunk, size - 4);
}*/

void	tri_chelou(t_list **stack_a, t_list **stack_b, t_data *data)
{
	if (data->a_size < 30)
	{
		pre_sort(stack_a, stack_b, data->a_size, data->a_size);
		insert_back_sort(stack_a, stack_b, data->a_size);
		return;
	}
	else if (data->a_size < 200)
		first_phase4(stack_a, stack_b, data->a_size);
	else if (data->a_size >= 200)
		first_phase10(stack_a, stack_b, data->a_size);
	sort_3(stack_a);
	insert_back_sort(stack_a, stack_b, data->a_size - 4);
}
