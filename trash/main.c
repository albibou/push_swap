/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:42:50 by atardif           #+#    #+#             */
/*   Updated: 2023/02/17 15:04:46 by atardif          ###   ########.fr       */
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

void	print_list(t_list *stack)
{
	t_list	*tmp;

	tmp = stack;
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
	if (ac != 3)
	{
		ft_printf("Use as ./trash '0 1 2 3' '3 2 1'\n");
		free(data);
		exit(1);
	}

	data->args = ft_split(av[1], ' ');
	data->bargs = ft_split(av[2], ' ');
	data->stack_a = init_list(data->stack_a, data->args);
	data->stack_b = init_list(data->stack_b, data->bargs);
	data->a_size = ft_lstsize(data->stack_a);
	data->b_size = ft_lstsize(data->stack_b);

	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	sa(data->stack_a);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");

	sb(data->stack_b);
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	ss(data->stack_a, data->stack_b);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	ra(&data->stack_a);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");

	rb(&data->stack_b);
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	rr(&data->stack_a, &data->stack_b);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	rra(&data->stack_a);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");

	rrb(&data->stack_b);
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	rrr(&data->stack_a, &data->stack_b);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	pa(&data->stack_a, &data->stack_b);
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");

	pb(&data->stack_a, &data->stack_b);
	ft_printf("B : \n");
	print_list(data->stack_b);
	ft_printf("\n");
	ft_printf("A : \n");
	print_list(data->stack_a);
	ft_printf("\n");

	ft_freetab(data->args);
	ft_freetab(data->bargs);
	free_list(data->stack_a);
	free_list(data->stack_b);
	free(data);
	return(0);
}
