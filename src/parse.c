/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:22 by atardif           #+#    #+#             */
/*   Updated: 2023/02/19 16:06:00 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_double(long nb, char **args)
{
	while (*args)
	{
		if (nb == ft_atoi(*args))
			return (0);
		args++;
	}
	return (1);
}	

int	check_args(char **args)
{
	int		i;
	long	nb;
	char	*tmp;

	i = 0;
	while (*args)
	{
		tmp = *args;
		i = 0;
		if (tmp[i] == '\0' || (!ft_issign(tmp[i]) && !ft_isdigit(tmp[i])))
			return (0);
		else if (!ft_isdigit(tmp[i]) && tmp[i + 1] == '\0')
			return (0);
		while (tmp[i] != '\0')
		{
			if (!ft_isdigit(tmp[i]) && !ft_issign(tmp[i]))
				return (0);
			i++;
		}
		nb = ft_atoi(tmp);
		if (nb < INT_MIN || nb > INT_MAX || !check_double(nb, args + 1))
			return (0);
		args++;
	}
	return (1);
}
