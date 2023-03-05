/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initlist.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:32 by atardif           #+#    #+#             */
/*   Updated: 2023/03/03 15:32:49 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	assign_index(t_list *stack, int target, int i)
{
	while (stack->next != NULL)
	{
		if (stack->content == target)
			stack->index = i;
		stack = stack->next;
	}
	if (stack->content == target)
		stack->index = i;
}

void	init_index(t_list *stack, int stacksize)
{
	int		i;
	long	min;

	i = 0;
	min = -2147483649;
	while (i < stacksize)
	{
		min = min_list(stack, 2147483648, min);
		assign_index(stack, min, i);
		i++;
	}
}

static void	create_list(t_list **stack, char **args)
{
	int		i;
	int		nb;
	t_list	*tmp;

	nb = 0;
	i = 0;
	while (args[i])
	{
		nb = ft_atoi(args[i]);
		tmp = ft_lstnew(nb);
		ft_lstadd_back(stack, tmp);
		i++;
	}
}

void	init_lists(t_data *data)
{
	create_list(&data->stack_a, data->args);
	data->a_size = ft_lstsize(data->stack_a);
	init_index(data->stack_a, data->a_size);
	data->stack_b = NULL;
}
