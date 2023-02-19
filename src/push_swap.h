/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:42:12 by atardif           #+#    #+#             */
/*   Updated: 2023/02/19 16:36:37 by atardif          ###   ########.fr       */
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
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

int		check_args(char **args);
void	free_error(t_data *data);
void	free_data(t_data *data);
#endif
