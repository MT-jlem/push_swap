/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/02 18:26:31 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:16:42 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	my_free(t_stack st)
{
	free(st.a);
	free(st.b);
	return (st);
}

void	error(void)
{
	write(2, "Error\n", 6);
	exit (1);
}

int	is_zero(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (str[i] != '0')
		return (0);
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return (1);
}

int	check(char **av)
{
	int	i;

	i = 1;
	if (!av[i])
	{
		write(2, "Error\n", 6);
		return (0);
	}
	while (av[i])
	{
		if (is_zero(av[i]))
		{
			i++;
			if (!av[i])
				break ;
		}
		if (!ft_atoi(av[i]))
		{
			write(2, "Error\n", 6);
			return (0);
		}
		i++;
	}
	return (1);
}

int	duplicate(int *stack, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (stack[i] == stack[j])
			{
				write(2, "Error\n", 6);
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}
