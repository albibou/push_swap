/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:58:06 by atardif           #+#    #+#             */
/*   Updated: 2023/03/07 11:58:09 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
