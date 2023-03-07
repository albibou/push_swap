/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:31:01 by atardif           #+#    #+#             */
/*   Updated: 2023/03/07 14:50:31 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	set_params(t_data *data, int ac, char **av)
{
	data->ac = ac;
	if (ac < 2)
	{
		free(data);
		exit(1);
	}
	else if (ac == 2)
		data->args = ft_split(av[1], ' ');
	else
		data->args = av + 1;
	if (!check_args(data->args))
	{
		data->error = 1;
		free_error(data);
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Struct alloc error\n", 2);
		exit(1);
	}
	set_params(data, ac, av);
	init_lists(data);
	get_lis(data);
	sort_hub(data);
	free_data(data);
	return (0);
}
