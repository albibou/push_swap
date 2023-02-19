/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:13 by atardif           #+#    #+#             */
/*   Updated: 2023/02/19 16:38:44 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
static void	free_list(t_list *stack)
{
	t_list	*tmp;

	while (stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}*/

static void	display_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Wrong arguments idiot", 2);
}

void	free_error(t_data *data)
{
	display_error(data->error);
	if (data -> error <= 1)
		ft_freetab(data->args);
	free(data);
	exit(1);
}

void	free_data(t_data *data)
{
	ft_freetab(data->args);
	//free_list(data->stack_a);
	/*if (data -> bsize > 0)
		free_list(data->stack_b);*/
	free(data);
	exit(0);
}
