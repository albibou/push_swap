/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:31:01 by atardif           #+#    #+#             */
/*   Updated: 2023/02/17 17:50:57 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	(void)ac;
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
	{
		ft_putstr_fd("Struct alloc error\n", 2);
		exit(1);
	}
	if (ac < 2)
	{
		free(data);
		exit(1);
	}
	else if (ac == 2)
		data->args = ft_split(av[1], ' ');
	else
		data->args = av;
	return (0);
}
