/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:13 by atardif           #+#    #+#             */
/*   Updated: 2023/03/03 12:23:45 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

static void	display_error(int error)
{
	if (error == 1)
		ft_putstr_fd("Error\n", 2);
}

void	free_error(t_data *data)
{
	display_error(data->error);
	if (data -> error <= 1 && data->ac == 2)
		ft_freetab(data->args);
	free(data);
	exit(1);
}

void	free_data(t_data *data)
{
	if (data->ac == 2)
		ft_freetab(data->args);
	free_list(data->stack_a);
	free(data->sub.lis);
	if (data->b_size > 0)
		free_list(data->stack_b);
	free(data);
	exit(0);
}
