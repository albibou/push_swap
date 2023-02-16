/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:50 by atardif           #+#    #+#             */
/*   Updated: 2023/02/16 18:54:03 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "trash.h"

t_list	*init_list(t_list *stack, char **args)
{
	int	i;
	int 	test;
	t_list	*tmp;

	stack = NULL;
	test = 0;
	i = 0;	
	while(args[i])
	{
		test = ft_atoi(args[i]);
		tmp = ft_lstnew(test);
		ft_lstadd_back(&stack, tmp);
		i++;
	}
	return(stack);	
}

void	free_list(t_list *stack)
{
	t_list	*tmp;

	while(stack->next != NULL)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
	free(stack);
}

void	print_list_a(t_list *stack_a)
{
	t_list	*tmp;

	tmp = stack_a;
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
	data->stack_a = init_list(data->stack_a, data->args);
	data->a_size = ft_lstsize(data->stack_a);
	print_list_a(data->stack_a);
	ft_printf("\n");
	sa(data->stack_a);
	print_list_a(data->stack_a);
	ft_printf("\n");
	ra(&data->stack_a);
	ft_printf("\n");
	print_list_a(data->stack_a);
	ft_printf("\n");
	rra(&data->stack_a);
	ft_printf("\n");
	print_list_a(data->stack_a);
	ft_freetab(data->args);
	free_list(data->stack_a);
	free(data);
	return(0);
}
