/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:38:49 by atardif           #+#    #+#             */
/*   Updated: 2023/02/23 11:45:45 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(int content)
{
	t_list	*new_lst;

	new_lst = malloc(sizeof(t_list));
	if (!new_lst)
		return (NULL);
	new_lst -> content = content;
	new_lst -> index = 0;
	new_lst -> next = NULL;
	return (new_lst);
}
