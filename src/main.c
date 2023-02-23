/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:31:01 by atardif           #+#    #+#             */
/*   Updated: 2023/02/23 13:59:27 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//penser a delete cette fonction
void	print_list(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
	while (tmp->next != NULL)
	{
		ft_printf("content :%d\n", tmp->content);
		ft_printf("index : %d\n", tmp->index);
		tmp = tmp->next;
	}
	ft_printf("content :%d\n", tmp->content);
	ft_printf("index : %d\n", tmp->index);
}


void	set_params(t_data *data, int ac, char **av)
{
	data->ac = ac;
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
	set_params(data, ac, av);
	//ft_printf("Yes idiot\n");
	init_lists(data);
	//print_list(data->stack_a);
	sort_hub(data);
	//ft_printf("A\n");
	//print_list(data->stack_a);
	//ft_printf("B\n");
	//print_list(data->stack_a);
	free_data(data);
	return (0);
}
