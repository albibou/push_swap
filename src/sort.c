/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:49 by atardif           #+#    #+#             */
/*   Updated: 2023/03/02 16:17:09 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_5(t_data *data)
{
	int	tmp_size;

	tmp_size = ft_lstsize(data->stack_a);
	while (tmp_size > 3)
	{
		if (data->stack_a->index == 0 || (data->a_size = 4 && data->stack_a->index == 1))
		       pb(&data->stack_b, &data->stack_a);
		else
			ra(&data->stack_a);
		tmp_size = ft_lstsize(data->stack_a);
	}	
	sort_3(&data->stack_a);
	pa(&data->stack_a, &data->stack_b);
	pa(&data->stack_a, &data->stack_b);
	if (data->stack_a->index > data->stack_a->next->index)
		sa(&data->stack_a);
}

void	sort_3(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (!is_sorted(tmp))
		return ;
	if (tmp->index > tmp->next->index && tmp->index < tmp->next->next->index)
		sa(stack);
	else if (tmp->index < tmp->next->index
		&& tmp->index < tmp->next->next->index)
		sa(stack);
	else if (tmp->index > tmp->next->index
		&& tmp->next->index > tmp->next->next->index)
		sa(stack);
	tmp = *stack;
	if (tmp->index < tmp->next->index && tmp->index > tmp->next->next->index)
		rra(stack);
	else if (tmp->index > tmp->next->index
		&& tmp->index > tmp->next->next->index)
		ra(stack);
}

void	sort_hub(t_data *data)
{
	if (data->a_size == 2)
		sa(&data->stack_a);
	else if (data->a_size == 3)
		sort_3(&data->stack_a);
	else if (data->a_size <= 5)
		sort_5(data);
	else
		tri_chelou(&data->stack_a, &data->stack_b, data);
}
