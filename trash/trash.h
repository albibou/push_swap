/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:45:08 by atardif           #+#    #+#             */
/*   Updated: 2023/02/17 14:46:58 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _TRASH_H
# define _TRASH_H

# include "./libft/libft.h"
# include "./libft/get_next_line.h"
# include "./libft/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>


typedef struct	s_data
{
	char **args;
	char **bargs;
	int	a_size;
	int	b_size;	
	t_list	*stack_a;
	t_list	*stack_b;
} t_data;

void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	sa(t_list *stack_a);
void	sb(t_list *stack_b);
void	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
#endif
