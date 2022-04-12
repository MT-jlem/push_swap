/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 17:18:28 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 17:18:40 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	is_sorted(t_stack utils)
{
	int	i;

	i = 0;
	while (i < utils.tail_a)
	{
		if (utils.a[i] > utils.a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

int	get_max(t_stack utils)
{
	int	i;
	int	pos;

	i = utils.top_b;
	pos = i;
	while (i < utils.tail_b)
	{
		if (utils.b[i] > utils.b[pos])
			pos = i;
		i++;
	}
	return (pos);
}

int	best_dev(t_stack utils, int d)
{
	if (utils.tail_a <= 130 && d >= 3)
		d = 3;
	else if (utils.tail_a <= 200 && d >= 4)
		d = 4;
	else if (utils.tail_a <= 300 && d >= 5)
		d = 5;
	else if (utils.tail_a <= 430 && d >= 6)
		d = 6;
	else
		return (d);
	return (d);
}

t_stack	fill_stack(t_stack st, char **av)
{
	int	i;

	i = 1;
	while (av[i])
	{
		st.tail_a++;
		if (st.tail_a == 0)
			st.top_a++;
		st.a[st.tail_a] = ft_atoi(av[i]);
		i++;
	}
	return (st);
}

int	ft_strcmp(char *s1, char *s2)
{
	unsigned char	s3;
	unsigned char	s4;
	int				i;

	i = 0;
	while (s1[i] != '\0' || s2[i] != '\0')
	{
		s3 = s1[i];
		s4 = s2[i];
		if (s3 != s4)
			return (s3 - s4);
		i++;
	}
	return (0);
}
