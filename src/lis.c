/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 16:01:19 by atardif           #+#    #+#             */
/*   Updated: 2023/03/02 18:01:46 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_in_tab(int	*lis, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (lis[i] > max)
			max = lis[i];
		i++;
	}
	return (max);
}

int	*lenlis(int *stackcpy, int size)
{
	int	*lis;
	int	i;
	int	j;

	lis = ft_calloc(sizeof(int), size);
	lis [0] = 1;
	i = 1;
	while (i < size)
	{
		lis[i] = 1;
		j = 0;
		while (j < i)
		{
			if (stackcpy[i] > stackcpy[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	return (lis);
}

int	*copyintab(t_list *stack, int size)
{
	int		*array;
	int		i;
	t_list	*tmp;

	array = ft_calloc(sizeof(int), size);
	i = 0;
	tmp = stack;
	while (i < size)
	{
		array[i] = tmp->index;
		tmp = tmp->next;
		i++;
	}
	return (array);
}

int	*init_lis(int *lis_len, int *stackcpy, int max, int size)
{
	int	tmp;
	int	*lis;
	int	i;
	int	y;

	lis = ft_calloc(sizeof(int), max);
	tmp = max;
	i = size - 1;
	y = 0;
	while (i >= 0)
	{
		if (lis_len[i] == tmp)
		{
			lis[y] = stackcpy[i];
			tmp--;
			y++;
		}
		i--;
	}
	return (lis);
}

void	get_lis(t_data *data)
{
	int	*stackcpy;
	int	*lis_len;

	stackcpy = copyintab(data->stack_a, data->a_size);
	lis_len = lenlis(stackcpy, data->a_size);
	data->sub.l_size = max_in_tab(lis_len, data->a_size);
	data->sub.lis = init_lis(lis_len, stackcpy, data->sub.l_size, data->a_size);
	free(stackcpy);
	free(lis_len);
}
