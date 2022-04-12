/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:20:56 by mjlem             #+#    #+#             */
/*   Updated: 2022/02/28 09:08:50 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack{
	int	*a;
	int	*b;
	int	top_a;
	int	top_b;
	int	tail_a;
	int	tail_b;
	int	*tmp_stack;
	int	mv;
}	t_stack;

void	error(void);
int		get_max(t_stack utils);
int		ft_atoi(char *str);
int		is_sorted(t_stack utils);
int		check(char **av);
int		is_zero(char *str);
int		duplicate(int *stack, int count);
int		best_move(t_stack utils);
int		best_dev(t_stack utils, int d);
int		get_min(t_stack st);
int		ft_strcmp(char *s1, char *s2);
t_stack	my_free(t_stack st);
t_stack	fill_stack(t_stack st, char **av);
t_stack	sort_5(t_stack st);
t_stack	sort_3(t_stack utils);
t_stack	send_to_a_test(t_stack utils);
t_stack	send_to_b_test(t_stack utils, int d);
t_stack	ft_tmp_stacpy(t_stack utils);
t_stack	tmp_sort(t_stack utils);
t_stack	send_to_b(t_stack utils, int d);
t_stack	send_to_a(t_stack utils);
t_stack	sa(t_stack utils, int flag);
t_stack	sb(t_stack utils, int flag);
t_stack	ss(t_stack utils, int flag);
t_stack	pa(t_stack utils, int flag);
t_stack	pb(t_stack utils, int flag);
t_stack	ra(t_stack utils, int flag);
t_stack	rb(t_stack	utils, int flag);
t_stack	rr(t_stack	utils, int flag);
t_stack	rra(t_stack	utils, int flag);
t_stack	rrb(t_stack utils, int flag);
t_stack	rrr(t_stack	utils, int flag);

#endif
