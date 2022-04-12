/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:15:59 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 12:21:09 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	sort_3(t_stack st)
{
	if (st.a[0] > st.a[1] && st.a[1] < st.a[2] && st.a[0] < st.a[2])
		st = sa(st, 1);
	else if (st.a[0] > st.a[1] && st.a[1] > st.a[2] && st.a[0] > st.a[1])
	{
		st = sa(st, 1);
		st = rra(st, 1);
	}
	else if (st.a[0] > st.a[1] && st.a[1] < st.a[2] && st.a[0] > st.a[2])
		st = ra(st, 1);
	else if (st.a[0] < st.a[1] && st.a[1] > st.a[2] && st.a[2] > st.a[0])
	{
		st = sa(st, 1);
		st = ra(st, 1);
	}
	else if (st.a[0] < st.a[1] && st.a[1] > st.a[2] && st.a[0] > st.a[2])
		st = rra(st, 1);
	return (st);
}
