/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 11:48:49 by atardif           #+#    #+#             */
/*   Updated: 2023/02/23 17:36:59 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	sort_3(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	if (tmp->index > tmp->next->index && tmp->index < tmp->next->next->index)
		sa(stack);
	else if(tmp->index < tmp->next->index &&
			tmp->index < tmp->next->next->index)
		sa(stack);
	else if (tmp->index > tmp->next->index &&
			tmp->next->index > tmp->next->next->index)
		sa(stack);
	tmp = *stack;
	if (tmp->index < tmp->next->index && tmp->index > tmp->next->next->index)
		rra(stack);
	else if (tmp->index > tmp->next->index &&
			tmp->index > tmp->next->next->index)
		ra(stack);
}


void	sort_hub(t_data *data)
{
	if (data->a_size == 2)
		sa(&data->stack_a);
	else if (data->a_size == 3)
		sort_3(&data->stack_a);
	else
	{
		//insert_sort(&data->stack_a, &data->stack_b, data);
		tri_chelou(&data->stack_a, &data->stack_b, data);
	}
}
