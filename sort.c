/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 12:58:41 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:07:47 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	ft_tmp_stacpy(t_stack utils)
{
	int	i;

	utils.tmp_stack = malloc (sizeof(int) * (utils.tail_a + 1));
	i = 0;
	while (i <= utils.tail_a)
	{
		utils.tmp_stack[i] = utils.a[i];
		i++;
	}
	return (utils);
}

t_stack	tmp_sort(t_stack utils)
{
	int	temp;
	int	i;
	int	j;

	i = 0;
	while (i < utils.tail_a)
	{
		j = 0;
		while (j < utils.tail_a - i)
		{
			if (utils.tmp_stack[j] > utils.tmp_stack[j + 1])
			{
				temp = utils.tmp_stack[j];
				utils.tmp_stack[j] = utils.tmp_stack[j + 1];
				utils.tmp_stack[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (utils);
}

t_stack	send_to_b(t_stack st, int d)
{
	int	i;
	int	l;
	int	j;

	j = 0;
	i = st.tail_a / best_dev(st, d);
	l = i / 2;
	while (j <= st.tail_a)
	{
		if (st.a[j] <= st.tmp_stack[i])
		{
			while (j--)
				st = ra(st, 1);
			if (st.a[0] <= st.tmp_stack[i] || st.top_b == st.tail_b)
					st = pb(st, 1);
			if (st.a[0] > st.tmp_stack[i] && st.b[st.top_b] <= st.tmp_stack[l]
				&& st.top_b != st.tail_b)
				st = rr(st, 1);
			else if (st.b[st.top_b] <= st.tmp_stack[l] && st.top_b != st.tail_b)
				st = rb(st, 1);
			j = -1;
		}
		j++;
	}
	return (st);
}

t_stack	send_to_a(t_stack utils)
{
	int	rb_move;
	int	rrb_move;
	int	pos;

	rb_move = 0;
	rrb_move = 0;
	while (utils.top_b != utils.tail_b)
	{
		pos = get_max(utils);
		rb_move = pos - utils.top_b;
		rrb_move = utils.tail_b - pos;
		if (rb_move <= rrb_move)
		{
			while (rb_move--)
				utils = rb(utils, 1);
			utils = pa(utils, 1);
		}
		else if (rb_move > rrb_move)
		{
			while (rrb_move--)
				utils = rrb(utils, 1);
			utils = pa(utils, 1);
		}
	}
	return (utils);
}
