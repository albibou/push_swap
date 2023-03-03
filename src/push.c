/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:13:36 by atardif           #+#    #+#             */
/*   Updated: 2023/03/02 16:03:52 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **target, t_list **from)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *from;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_front(target, new);
	*from = tmp->next;
	free(tmp);
}

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
	ft_printf("pa\n");
}

void	pb(t_list **stack_b, t_list **stack_a)
{
	push(stack_b, stack_a);
	ft_printf("pb\n");
}
