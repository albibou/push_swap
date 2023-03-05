/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:13:43 by atardif           #+#    #+#             */
/*   Updated: 2023/02/21 17:35:49 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	rotate(t_list **stack)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack;
	if (!tmp || tmp->next == NULL)
		return ;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_back(stack, new);
	*stack = tmp->next;
	free(tmp);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
