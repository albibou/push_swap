/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 13:45:08 by atardif           #+#    #+#             */
/*   Updated: 2023/02/10 18:02:28 by atardif          ###   ########.fr       */
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
	t_list	*stack_a;
	t_list	*stack_b;
} t_data;

int	sa(t_data *data);
int	sb(t_data *data);
int	ss(t_data *data);

#endif
