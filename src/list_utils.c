/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 16:28:51 by atardif           #+#    #+#             */
/*   Updated: 2023/03/09 16:37:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	min_list(t_list *stack, long min, long omin)
{
	while (stack->next != NULL)
	{
		if (stack->content < min && stack->content > omin)
			min = stack->content;
		stack = stack->next;
	}
	if (stack->content < min && stack-> content > omin)
		min = stack->content;
	return (min);
}

int	is_sorted(t_list *stack)
{
	if(!stack)
		return (1);
	while (stack->next->next != NULL)
	{
		if (stack->content > stack->next->content)
			return (1);
		stack = stack->next;
	}
	if (stack->content > stack->next->content)
		return (1);
	return (0);
}
