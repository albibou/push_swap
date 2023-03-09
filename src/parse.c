/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atardif <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:14:22 by atardif           #+#    #+#             */
/*   Updated: 2023/03/09 16:50:54 by atardif          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	max(char *tmp)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (tmp[i])
	{
		if (ft_isdigit(tmp[i]) && (tmp[i]) != '0')
			count++;
		if (count > 12)
			return (count);
		i++;
	}
	return (0);
}

static int	multisign(char *tmp)
{
	int	sign;
	int	i;

	i = 0;
	sign = 0;
	while (ft_isspace(tmp[i]))
		i++;
	if (ft_isdigit(tmp[i]))
		sign++;
	while (tmp[i] != '\0')
	{
		if (tmp[i] == '-' || tmp[i] == '+')
			sign++;
		if (sign > 1)
			return (0);
		i++;
	}
	return (1);
}

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

static int	first_check(char *s, int i)
{
	if (s[i] == '\0' || (!ft_issign(s[i]) && !ft_isdigit(s[i])
			&& !ft_isspace(s[i])))
		return (0);
	else if (max(s))
		return (0);
	else if ((!ft_isdigit(s[i]) && s[i + 1] == '\0') || !multisign(s))
		return (0);
	return (1);
}

int	check_args(char **args)
{
	int		i;
	long	nb;
	char	*s;

	i = 0;
	if (!*args)
		return (0);
	while (*args)
	{
		s = *args;
		i = 0;
		if (!first_check(s, i))
			return (0);
		while (s[i] != '\0')
		{
			if (!ft_isdigit(s[i]) && !ft_issign(s[i]) && !ft_isspace(s[i]))
				return (0);
			i++;
		}
		nb = ft_atoi(s);
		if (nb < INT_MIN || nb > INT_MAX || !check_double(nb, args + 1))
			return (0);
		args++;
	}
	return (1);
}
