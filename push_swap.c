/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mjlem <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 18:19:47 by mjlem             #+#    #+#             */
/*   Updated: 2022/02/28 09:08:46 by mjlem            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

t_stack	the_sort(t_stack utils)
{
	int	d;

	if (utils.tail_a == 2)
	{
		utils = sort_3(utils);
		exit(0);
	}
	if (utils.tail_a == 4)
	{
		utils = sort_5(utils);
		exit(0);
	}
	d = best_move(utils);
	while (utils.tail_a)
	{
		if (is_sorted(utils))
			break ;
		utils = tmp_sort(ft_tmp_stacpy(utils));
		utils = send_to_b(utils, d);
		free(utils.tmp_stack);
	}
	utils = send_to_a(utils);
	return (utils);
}

int	main(int ac, char **av)
{
	t_stack	utils;

	if (ac > 1)
	{
		if (check(av))
		{
			utils.top_a = -1;
			utils.tail_a = -1;
			utils.top_b = ac - 1;
			utils.tail_b = ac - 1;
			utils.a = malloc((ac - 1) * sizeof(int));
			utils.b = malloc((ac - 1) * sizeof(int));
			utils = fill_stack(utils, av);
			if (!duplicate(utils.a, ac - 1))
				return (0);
			if (is_sorted(utils))
				return (0);
			utils = the_sort(utils);
			utils = my_free(utils);
		}
	}
	return (0);
}
