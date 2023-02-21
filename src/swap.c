/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:13:59 by atardif           #+#    #+#             */
/*   Updated: 2023/02/21 17:19:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list *stack)
{
	t_list	*tmp;
	int	c_swp;
	int	i_swp;

	tmp = stack;
	c_swp = stack->content;
	i_swp = stack->index;
	if(!tmp || tmp->next == NULL)
		return;
	tmp->content = tmp->next->content;
	tmp->next->content = c_swp;
	tmp->next->index = i_swp;
}

void	sa(t_list *stack_a)
{
	swap(stack_a);
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	swap(stack_b);
	ft_printf("sb\n");
}

void	ss(t_list *stack_a, t_list *stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_printf("ss\n");
}
