/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 17:05:09 by atardif           #+#    #+#             */
/*   Updated: 2023/02/10 17:34:05 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

int	sa(t_data *data)
{
	t_list	*tmp;
	int	rep;

	tmp = data->stack_a;
	rep = data->stack_a->content;
	if(!tmp || tmp->next == NULL)
		return(1);
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sa\n");
	return (0);
}

int	sb(t_data *data)
{
	t_list	*tmp;
	int	rep;

	tmp = data->stack_b;
	rep = data->stack_b->content;
	if (!tmp || tmp->next == NULL)
		return (1);
	tmp->content = tmp->next->content;
	tmp->next->content = rep;
	ft_printf("sb\n");
	return(0);
}

int	ss(t_data *data)
{
	sa(data);
	sb(data);
	ft_printf("ss\n");
	return(0);
}

