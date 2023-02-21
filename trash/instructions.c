/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:05:09 by atardif           #+#    #+#             */
/*   Updated: 2023/02/21 16:58:25 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

void	pa(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	t_list *new;

	tmp = *stack_b;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_front(stack_a, new);
	*stack_b = tmp->next;
	free(tmp);
	ft_printf("pa\n");	
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	t_list *tmp;
	t_list *new;

	tmp = *stack_a;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_front(stack_b, new);
	*stack_a = tmp->next;
	free(tmp);
	ft_printf("pb\n");	
}

void	sa(t_list *stack_a)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_a;
	rep = stack_a->content;
	if(!tmp || tmp->next == NULL)
		return;
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_b;
	rep = stack_b->content;
	if (!tmp || tmp->next == NULL)
		return;
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sb\n");
}

/*                                     Work In Progress
void	sa(t_list *stack_a)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_a;
	if(!tmp || tmp->next == NULL)
		return;
	stack_a = stack_a->next;
	tmp->next
	ft_printf("sa\n");
}

void	sb(t_list *stack_b)
{
	t_list	*tmp;
	int	rep;

	tmp = stack_b;
	rep = stack_b->content;
	if (!tmp || tmp->next == NULL)
		return;
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sb\n");
}
*/
void	ss(t_list *stack_a, t_list *stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_printf("ss\n");
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

void	rb(t_list **stack_b)
{
	t_list	*tmp;
	t_list	*new;

	tmp = *stack_b;
	new = ft_lstnew(tmp->content);
	new->index = tmp->index;
	ft_lstadd_back(stack_b, new);
	*stack_b = tmp->next;
	free(tmp);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_printf("rr\n");
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

void	rrb(t_list **stack_b)
{
	t_list	*bottom;
	t_list	*new;
	t_list	*tmp;

	tmp = *stack_b;
	bottom = ft_lstlast(tmp);
	new = ft_lstnew(bottom->content);
	new->index = bottom->index;
	ft_lstadd_front(&tmp, new);
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	tmp->next = NULL;
	free(bottom);
	*stack_b = new;
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	rra(stack_a);
	rrb(stack_b);
	ft_printf("rrr\n");
}
