/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:05:09 by atardif           #+#    #+#             */
/*   Updated: 2023/02/16 18:53:50 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

int	sa(t_list *stack_a)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_a;
	rep = stack_a->content;
	if(!tmp || tmp->next == NULL)
		return(1);
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_list *stack_b)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_b;
	rep = stack_b->content;
	if (!tmp || tmp->next == NULL)
		return (1);
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sb\n");
	return(0);
}

int	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
	return(0);
}

void	ra(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack_a;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_back(stack_a, new);
	*stack_a = tmp->next;
	free(tmp);
	ft_printf("ra\n");
}

void	rra(t_list **stack_a)
{
	t_list	*bottom;
	t_list	*new;
	t_list	*tmp;

	tmp = *stack_a;
	bottom = ft_lstlast(tmp);
	new = ft_lstnew(bottom->content);
	new->index = bottom->index;
	ft_lstadd_front(&tmp, new);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	free(bottom);
	*stack_a = new;
	ft_printf("rra\n");
}
