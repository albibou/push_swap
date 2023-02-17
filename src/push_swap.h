/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 12:42:12 by atardif           #+#    #+#             */
/*   Updated: 2023/02/17 17:53:15 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include "../libft/ft_printf.h"
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	char	**args;
	int		a_size;
	int		b_size;
	t_list	*stack_a;
	t_list	*stack_b;
}	t_data;

#endif
