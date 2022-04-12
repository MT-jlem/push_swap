/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/20 18:22:36 by mjlem             #+#    #+#             */
/*   Updated: 2022/03/20 18:22:38 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include "get_next_line.h"

void	my_write(t_stack st)
{
	if (is_sorted(st) && (st.top_b == st.tail_b))
		write(2, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

t_stack	checker(char *arg, t_stack st)
{
	if (!ft_strcmp(arg, "sa"))
		st = sa(st, 0);
	else if (!ft_strcmp(arg, "sb"))
		st = sb(st, 0);
	else if (!ft_strcmp(arg, "ss"))
		st = ss(st, 0);
	else if (!ft_strcmp(arg, "pa"))
		st = pa(st, 0);
	else if (!ft_strcmp(arg, "pb"))
		st = pb(st, 0);
	else if (!ft_strcmp(arg, "rb"))
		st = rb(st, 2);
	else if (!ft_strcmp(arg, "ra"))
		st = ra(st, 2);
	else if (!ft_strcmp(arg, "rr"))
		st = rr(st, 0);
	else if (!ft_strcmp(arg, "rra"))
		st = rra(st, 0);
	else if (!ft_strcmp(arg, "rrb"))
		st = rrb(st, 0);
	else if (!ft_strcmp(arg, "rrr"))
		st = rrr(st, 0);
	else
		error();
	return (st);
}

int	main(int ac, char **av)
{
	t_stack	st;
	char	*arg;

	if (ac > 1 && check(av))
	{
		st.top_a = -1;
		st.tail_a = -1;
		st.top_b = ac - 1;
		st.tail_b = ac - 1;
		st.a = malloc((ac - 1) * sizeof(int));
		st.b = malloc((ac - 1) * sizeof(int));
		st = fill_stack(st, av);
		if (!duplicate(st.a, ac - 1) || is_sorted(st))
			return (0);
		arg = get_next_line(0);
		while (arg)
		{
			st = checker(arg, st);
			free(arg);
			arg = get_next_line(0);
		}
		my_write(st);
		my_free(st);
	}
}
