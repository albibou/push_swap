/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:13:50 by atardif           #+#    #+#             */
/*   Updated: 2023/02/21 17:31:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*bottom;
	t_list	*new;
	t_list	*tmp;

	tmp = *stack;
	if (!tmp || tmp->next == NULL)
		return ;
	bottom = ft_lstlast(tmp);
	new = ft_lstnew(bottom->content);
	new->index = bottom->index;
	ft_lstadd_front(&tmp, new);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	free(bottom);
	*stack = new;
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
}
