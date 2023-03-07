/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 11:56:38 by atardif           #+#    #+#             */
/*   Updated: 2023/03/07 12:25:25 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	compare_instructions(t_data *data, char *str, int i)
{
	if (ft_strncmp(str, "sa\n", i) == 0)
		sa(&data->stack_a);
	else if (ft_strncmp(str, "sb\n", i) == 0)
		sb(&data->stack_b);
	else if (ft_strncmp(str, "ss\n", i) == 0)
		ss(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(str, "pa\n", i) == 0)
		pa(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(str, "pb\n", i) == 0)
		pb(&data->stack_b, &data->stack_a);
	else if (ft_strncmp(str, "ra\n", i) == 0)
		ra(&data->stack_a);
	else if (ft_strncmp(str, "rb\n", i) == 0)
		rb(&data->stack_b);
	else if (ft_strncmp(str, "rr\n", i) == 0)
		rr(&data->stack_a, &data->stack_b);
	else if (ft_strncmp(str, "rra\n", i) == 0)
		rra(&data->stack_a);
	else if (ft_strncmp(str, "rrb\n", i) == 0)
		rrb(&data->stack_b);
	else if (ft_strncmp(str, "rrr\n", i) == 0)
		rrr(&data->stack_a, &data->stack_b);
	else
		return (1);
	return (0);
}

void	checker(t_data *data)
{
	char	*str;
	int		i;

	str = get_next_line(0);
	while (str)
	{
		i = ft_strlen(str);
		if (compare_instructions(data, str, i) == 1)
		{
			free(str);
			ft_putstr_fd("Error\n", 2);
			free_data(data);
		}
		free(str);
		str = get_next_line(0);
	}
	free(str);
}
