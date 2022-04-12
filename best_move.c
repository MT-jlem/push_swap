/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:17:29 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/19 16:29:03 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	send_to_b_test(t_stack st, int d)
{
	int	i;
	int	l;
	int	j;

	i = st.tail_a / best_dev(st, d);
	l = i / 2;
	j = 0;
	while (j <= st.tail_a)
	{
		if (st.a[j] <= st.tmp_stack[i])
		{
			while (j--)
				st = ra(st, 2);
			if (st.a[0] <= st.tmp_stack[i] || st.top_b == st.tail_b)
				st = pb(st, 0);
			if (st.a[0] > st.tmp_stack[i] && st.b[st.top_b] <= st.tmp_stack[l]
				&& st.top_b != st.tail_b)
				st = rr(st, 0);
			else if (st.b[st.top_b] <= st.tmp_stack[l] && st.top_b != st.tail_b)
				st = rb(st, 2);
			j = -1;
		}
		j++;
	}
	return (st);
}

t_stack	send_to_a_test(t_stack utils)
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
				utils = rb(utils, 2);
			utils = pa(utils, 0);
		}
		else
		{
			while (rrb_move--)
				utils = rrb(utils, 0);
			utils = pa(utils, 0);
		}
	}
	return (utils);
}

int	*ft_stacpy(t_stack utils)
{
	int	i;
	int	*tmp;

	tmp = malloc (sizeof(int) * (utils.tail_a + 1));
	i = 0;
	while (i <= utils.tail_a)
	{
		tmp[i] = utils.a[i];
		i++;
	}
	return (tmp);
}

t_stack	test_sort(t_stack test, int d)
{
	while (test.tail_a)
	{
		if (is_sorted(test))
			break ;
		test = tmp_sort(ft_tmp_stacpy(test));
		test = send_to_b_test(test, d);
		free(test.tmp_stack);
	}
	test = send_to_a_test(test);
	free(test.a);
	return (test);
}

int	best_move(t_stack utils)
{
	t_stack	t1;
	t_stack	t2;
	t_stack	t3;
	t_stack	t0;

	t0 = utils;
	t1 = utils;
	t2 = utils;
	t3 = utils;
	t0.a = ft_stacpy(utils);
	t1.a = ft_stacpy(utils);
	t2.a = ft_stacpy(utils);
	t3.a = ft_stacpy(utils);
	t0 = test_sort(t0, 4);
	t1 = test_sort(t1, 5);
	t2 = test_sort(t2, 6);
	t3 = test_sort(t3, 7);
	if (t1.mv <= t2.mv && t1.mv <= t3.mv && t1.mv <= t0.mv)
		return (5);
	else if (t2.mv <= t1.mv && t2.mv <= t3.mv && t2.mv <= t0.mv)
		return (6);
	else if (t3.mv <= t1.mv && t3.mv <= t2.mv && t3.mv <= t0.mv)
		return (7);
	else
		return (4);
}
