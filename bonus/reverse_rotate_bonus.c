/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 20:03:54 by atardif           #+#    #+#             */
/*   Updated: 2023/03/09 13:58:18 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*bottom;
	t_list	*beforelast;
	t_list	*head;

	head = *stack;
	beforelast = *stack;
	if (!head || head->next == NULL)
		return ;
	bottom = ft_lstlast(head);
	while (beforelast->next->next != NULL)
		beforelast = beforelast->next;
	beforelast->next = NULL;
	*stack = bottom;
	(*stack)->next = head;
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
