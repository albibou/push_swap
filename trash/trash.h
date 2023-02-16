/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:45:08 by atardif           #+#    #+#             */
/*   Updated: 2023/02/16 16:59:49 by atardif          ###   ########.fr       */
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
	int	a_size;
	int	b_size;	
	t_list	*stack_a;
	t_list	*stack_b;
} t_data;

int	sa(t_list *stack_a);
int	sb(t_list *stack_b);
int	ss(t_list *stack_a, t_list *stack_b);
void	ra(t_list **stack_a);
void	rra(t_list **stack_a);

#endif
