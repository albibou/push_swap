/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:31:01 by atardif           #+#    #+#             */
/*   Updated: 2023/02/19 16:41:25 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_params(t_data *data, int ac, char **av)
{
	if (ac < 2)
	{
		free (data);
		exit (1);
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
	(void)ac;
	t_data	*data;

	data = ft_calloc(1, sizeof(t_data));
	if (!data)
	{
		ft_putstr_fd("Struct alloc error\n", 2);
		exit(1);
	}
	/*if (ac < 2)
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
	}*/
	set_params(data, ac, av);
	ft_printf("Yes idiot");
	//free_data(data);
	return (0);
}
