/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 09:39:28 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/20 09:39:32 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_min(t_stack st)
{
	int	i;
	int	pos;

	i = 0;
	pos = i;
	while (i <= st.tail_a)
	{
		if (st.a[i] < st.a[pos])
			pos = i;
		i++;
	}
	return (pos);
}

t_stack	sort_5(t_stack st)
{
	int	pos;
	int	i;

	i = 0;
	while (i < 2)
	{
		pos = get_min(st);
		if (pos <= 2)
		{
			while (pos--)
				st = ra (st, 1);
			st = pb(st, 1);
		}
		else
		{
			while (pos++ <= st.tail_a)
				st = rra(st, 1);
			st = pb(st, 1);
		}
		i++;
	}
	st = sort_3(st);
	st = pa(st, 1);
	st = pa(st, 1);
	return (st);
}
