/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:42:12 by atardif           #+#    #+#             */
/*   Updated: 2023/02/21 17:37:53 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_data
{
	char	**args;
	int		a_size;
	int		b_size;
	int		error;
	int		ac;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

int		check_args(char **args);
int	is_sorted(t_list *stack);
long	min_list(t_list *stack, long min, long omin);
void	free_error(t_data *data);
void	free_data(t_data *data);
void	init_lists(t_data *data);
void	pa(t_list *stack_a, t_list *stack_b);
void	pb(t_list *stack_b, t_list *stack_a);
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
