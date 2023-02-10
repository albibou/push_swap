/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:50 by atardif           #+#    #+#             */
/*   Updated: 2023/02/10 18:02:08 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

void	init_list_a(t_data *data)
{
	int	i;
	int 	test;
	t_list	*tmp;

	tmp = data->stack_a;
	test = 0;
	i = 0;	
	while(data->args[i])
	{
		test = ft_atoi(data->args[i]);
		tmp = ft_lstnew(test);
		ft_lstadd_back(&data->stack_a, tmp);
		i++;
	}	
}

void	print_list_a(t_data *data)
{
	t_list	*tmp;

	tmp = data->stack_a;
	while (tmp->next != NULL)
	{
		ft_printf("%d\n", tmp->content);
		tmp = tmp->next;
	}
	ft_printf("%d\n", tmp->content);
}


int	main(int ac, char **av)
{
	(void)ac;
	t_data	*data;

	data = malloc(sizeof(t_data) * 1);
	if (!data)
	{
		ft_printf("Struct alloc error\n");
		exit(1);
	}
	if (ac != 2)
	{
		ft_printf("Use as ./trash '0 1 2 3'\n");
		free(data);
		exit(1);
	}
	data->args = ft_split(av[1], ' ');
	init_list_a(data);
	print_list_a(data);
	ft_printf("\n");
	sa(data);
	print_list_a(data);
	ft_printf("\n");
	sa(data);
	ft_printf("\n");
	print_list_a(data);
	ft_printf("\n");
	ft_freetab(data->args);
	free(data);
	return(0);
}
